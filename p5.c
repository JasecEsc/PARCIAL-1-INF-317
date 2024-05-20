#include <stdio.h>
#include <mpi.h>

#define TAMANO 4 // Definir el tamaño de la matriz y el vector

int main(int argc, char *argv[]) {
    int rango, num_procesos;
    int matriz[TAMANO][TAMANO] = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    int vector[TAMANO] = {1, 2, 3, 4};
    int resultado[TAMANO] = {0};
    int fila, columna;

    // Inicializar el entorno MPI
    MPI_Init(&argc, &argv);
    // Obtener el rango del proceso
    MPI_Comm_rank(MPI_COMM_WORLD, &rango);
    // Obtener el número total de procesos
    MPI_Comm_size(MPI_COMM_WORLD, &num_procesos);

    // Cada proceso MPI calculará una parte del resultado
    for (fila = rango; fila < TAMANO; fila += num_procesos) {
        resultado[fila] = 0;
        // Multiplicar cada fila de la matriz por el vector
        for (columna = 0; columna < TAMANO; columna++) {
            resultado[fila] += matriz[fila][columna] * vector[columna];
        }
    }

    // Reunir los resultados de todos los procesos
    MPI_Allgather(resultado + rango, 1, MPI_INT, resultado, 1, MPI_INT, MPI_COMM_WORLD);

    // Mostrar el resultado en el proceso 0
    if (rango == 0) {
        printf("Resultado de la multiplicación:\n");
        for (fila = 0; fila < TAMANO; fila++) {
            printf("%d ", resultado[fila]);
        }
        printf("\n");
    }

    // Finalizar el entorno MPI
    MPI_Finalize();

    return 0;
}
