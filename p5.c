#include <stdio.h>
#include <mpi.h>

#define N 4

int main(int argc, char *argv[]) {
    int rank, size;
    int matriz[N][N] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    int vector[N] = {1, 2, 3, 4};
    int resultado[N];
    int i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Utilizar el tamaño del comunicador como el número de procesadores
    int num_procs = size;

    // Cada proceso MPI calculará una parte del resultado
    for (i = rank; i < N; i += num_procs) {
        resultado[i] = 0;
        for (j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    // Se reúnen los resultados de todos los procesos
    MPI_Allgather(resultado + rank, 1, MPI_INT, resultado, 1, MPI_INT, MPI_COMM_WORLD);

    // Mostrar el resultado en el proceso 0
    if (rank == 0) {
        printf("Resultado de la multiplicación:\n");
        for (i = 0; i < N; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
    }

    MPI_Finalize();

    return 0;
}
