#include <stdio.h>

// Función para sumar dos enteros
int sumar(int *x, int *y) {
    return *x + *y;
}

// Función para restar dos enteros
int restar(int *x, int *y) {
    return *x - *y;
}

// Función para multiplicar dos enteros usando sumas repetidas
int multiplicar(int *x, int *y) {
    int producto = 0;
    // Suma *x, *y veces
    for (int i = 0; i < *y; i++) {
        producto += *x;
    }
    return producto;
}

// Función para dividir dos enteros (resultado entero)
float dividir(int *x, int *y) {
    // Verifica si el divisor es cero
    if (*y == 0) {
        printf("Error: División por cero\n");
        return 0;
    }
    float cociente = 0;
    float temporal = *x;
    // Resta *y de temporal hasta que sea menor que *y
    while (temporal >= *y) {
        temporal -= *y;
        cociente++;
    }
    return cociente;
}

int main() {
    // Declaración de variables
    int numero1, numero2;
    // Inicialización de variables
    numero1 = 5;
    numero2 = 2;
    // Imprime el resultado de la suma
    printf("Suma: %d\n", sumar(&numero1, &numero2));
    // Imprime el resultado de la resta
    printf("Resta: %d\n", restar(&numero1, &numero2));
    // Imprime el resultado de la multiplicación
    printf("Multiplicación: %d\n", multiplicar(&numero1, &numero2));
    // Imprime el resultado de la división
    printf("División: %.2f\n", dividir(&numero1, &numero2));

    return 0;
}
