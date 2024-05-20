#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 10  // Número de términos de Fibonacci

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char **argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        printf("Se necesitan al menos 2 procesos: un maestro y al menos un esclavo.\n");
        MPI_Finalize();
        return EXIT_FAILURE;
    }

    if (rank == 0) { // MASTER
        printf("Secuencia de Fibonacci:\n");

        // Arreglo para almacenar los resultados en el orden correcto
        int resultados[N];

        // Solicitar y almacenar cada término de Fibonacci
        for (int i = 0; i < N; i++) {
            int result;
            MPI_Recv(&result, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            resultados[i] = result;
        }

        // Imprimir la secuencia de Fibonacci completa
        for (int i = 0; i < N; i++) {
            printf("%d ", resultados[i]);
        }
        printf("\n");
    } else { // SLAVE
        int result;
        for (int i = 0; i < N; i++) {
            if (rank == 1) { // Procesador esclavo 1
                result = fibonacci(i);
                MPI_Send(&result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            }
        }
    }

    MPI_Finalize();
    return EXIT_SUCCESS;
}
