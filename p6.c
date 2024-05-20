#include "stdio.h"
#include "mpi.h"

#define NUM_SUBINTERVALOS 1000000 // Número total de subintervalos

// Función para calcular el valor de f(x)
double funcion(double x) {
    return 4.0 / (1.0 + x * x); // SUMA DE RIEMANN
}

int main() {
    int num_procesos, rango_proceso;
    double suma_global = 0.0, suma_local = 0.0;
    double tamano_paso = 1.0 / NUM_SUBINTERVALOS; // Tamaño del subintervalo

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procesos);
    MPI_Comm_rank(MPI_COMM_WORLD, &rango_proceso);
    
    // Calcular el número de subintervalos que cada procesador manejará
    int subintervalos_por_proceso = (NUM_SUBINTERVALOS + num_procesos - 1) / num_procesos;
    int indice_inicio = rango_proceso * subintervalos_por_proceso;
    int indice_fin = (rango_proceso + 1) * subintervalos_por_proceso;

    // Calcular la suma local en cada procesador
    for (int i = indice_inicio; i < indice_fin && i < NUM_SUBINTERVALOS; i++) {
        double x = (i + 0.5) * tamano_paso; // Punto medio del subintervalo
        suma_local += funcion(x);
    }

    // Sumar las sumas locales de cada procesador
    MPI_Reduce(&suma_local, &suma_global, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // El proceso principal (procesador 0) calcula la aproximación final de Pi
    if (rango_proceso == 0) {
        double pi = suma_global * tamano_paso;
        printf("Aproximación de Pi: %f\n", pi);
    }

    MPI_Finalize();
    return 0;
}
