#include <stdio.h>
#include <omp.h>

#define TAMANO 4 // Definir el tamaño de la matriz y el vector

int main() {
    // Inicialización de la matriz y el vector
    int matriz[TAMANO][TAMANO] = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    int vector[TAMANO] = {1, 2, 3, 4};
    int resultado[TAMANO];
    int fila, columna;

    // Multiplicación de matriz por vector con OpenMP
    #pragma omp parallel for private(fila, columna) shared(matriz, vector, resultado)
    for (fila = 0; fila < TAMANO; fila++) {
        resultado[fila] = 0;
        // Multiplicar cada fila de la matriz por el vector
        for (columna = 0; columna < TAMANO; columna++) {
            resultado[fila] += matriz[fila][columna] * vector[columna];
        }
    }

    // Mostrar el resultado de la multiplicación
    printf("Resultado de la multiplicación:\n");
    for (fila = 0; fila < TAMANO; fila++) {
        printf("%d ", resultado[fila]);
    }
    printf("\n");

    return 0;
}
