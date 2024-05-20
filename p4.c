#include <stdio.h>
#include <omp.h>

#define N 4

int main() {
    int matriz[N][N] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    int vector[N] = {1, 2, 3, 4};
    int resultado[N];
    int i, j;

    // Multiplicación de matriz por vector con OpenMP
    #pragma omp parallel for private(i, j) shared(matriz, vector, resultado)
    for (i = 0; i < N; i++) {
        resultado[i] = 0;
        for (j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    // Mostrar el resultado
    printf("Resultado de la multiplicación:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
 }   
