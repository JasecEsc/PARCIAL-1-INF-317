#include <stdio.h>
#include <omp.h>

// Función para multiplicar dos números utilizando sumas
int multiplicar(int x, int y) {
    int producto = 0;
    int i; // Declaramos 'i' fuera de la directiva OpenMP
    // Directiva OpenMP para paralelizar el bucle for con reducción de 'producto'
    #pragma omp parallel for reduction(+:producto) private(i)
    for (i = 0; i < y; i++) {
        int procesadorActivo = omp_get_thread_num(); // Número del hilo activo
        // Imprime información del hilo y el cálculo actual
        printf("Procesador activo en hilo %d - Cálculo: %d * %d = %d\n", procesadorActivo, x, i, x * i);
        producto += x;
    }
    return producto;
}

// Función para dividir dos números utilizando restas
int dividir(int x, int y) {
    // Verifica si el divisor es cero
    if (y == 0) {
        printf("Error: División por cero\n");
        return 0;
    }
    int cociente = 0;
    int temporal = x;
    int procesadorActivo; // Declaramos 'procesadorActivo' fuera de la directiva OpenMP
    // Directiva OpenMP para paralelizar el cálculo
    #pragma omp parallel private(procesadorActivo)
    {
        procesadorActivo = omp_get_thread_num(); // Número del hilo activo
        #pragma omp single
        while (temporal >= y) {
            temporal -= y;
            cociente++;
            // Imprime información del hilo y el cálculo actual
            printf("Procesador activo en hilo %d - Cálculo: %d - %d = %d\n", procesadorActivo, temporal + y, y, temporal);
        }
    }
    return cociente;
}

int main() {
    int numero1 = 1500, numero2 = 42;

    // Multiplicación en base a sumas
    printf("Multiplicación: %d\n", multiplicar(numero1, numero2));

    // División en base a restas
    printf("División: %d\n", dividir(numero1, numero2));

    return 0;
}
