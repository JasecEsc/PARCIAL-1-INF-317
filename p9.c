#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, N, M;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // El proceso 0 solicita al usuario el número de términos (N) y el número de procesadores (M).
        printf("Ingrese el número de términos (N): ");
        scanf("%d", &N);
        printf("Ingrese el número de procesadores (M): ");
        scanf("%d", &M);
    }
    // Se distribuyen los valores de N y M a todos los procesos.
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Se calcula el número de términos por proceso.
    int terms_per_process = N / M;
    // Se calcula el número de términos adicionales para los primeros procesos cuando N no es divisible por M.
    int extra_terms = N % M;

    // Se calcula el inicio y el final de la serie para cada proceso.
    int start = rank * terms_per_process + (rank < extra_terms ? rank : extra_terms) + 2;
    int end = start + terms_per_process - 1 + (rank < extra_terms ? 1 : 0);

    // Se muestra en pantalla el rango de términos que el proceso va a generar.
    printf("Proceso %d generando la serie de %d a %d\n", rank, start, end);

    // Se genera la serie de números pares dentro del rango asignado a este proceso.
    for (int i = start; i <= end; i += 2) {
        printf("%d ", i);
    }

    printf("\n");

    MPI_Finalize();
    return 0;
}
