#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Imprimir "Hola Mundo" desde todos los procesos MPI
    printf("Proceso %d de %d: Hola Mundo\n", rank, size);

    MPI_Finalize();

    return 0;
}
