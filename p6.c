#include "stdio.h"
#include "mpi.h"

#define N 1000000 // Número total de subintervalos

double f(double x) {
    return 4.0 / (1.0 + x * x); // SUMA DE RIEMMAN
}

int main() {
    int num_procs, proc_rank;
    double sum = 0.0, local_sum = 0.0;
    double step = 1.0 / N; // Tamaño del subintervalo

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);
    
    // Calcular el número de subintervalos que cada procesador manejará
    int subintervals_per_proc = (N + num_procs - 1) / num_procs;
    int start_index = proc_rank * subintervals_per_proc;
    int end_index = (proc_rank + 1) * subintervals_per_proc;

    // Calcular la suma local en cada procesador
    for (int i = start_index; i < end_index && i < N; i++) {
        double x = (i + 0.5) * step; // Punto medio del subintervalo
        local_sum += f(x);
    }

    // Sumar las sumas locales de cada procesador
    MPI_Reduce(&local_sum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // El proceso principal (procesador 0) calcula la aproximación final de Pi
    if (proc_rank == 0) {
        double pi = sum * step;
        printf("Aproximación de Pi: %f\n", pi);
    }

    MPI_Finalize();
    return 0;
}
