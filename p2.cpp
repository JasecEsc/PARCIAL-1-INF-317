#include <iostream>

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
        std::cout << "Error: División por cero" << std::endl;
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
    numero1 = 60;
    numero2 = 30;
    // Imprime el resultado de la suma
    std::cout << "Suma: " << sumar(&numero1, &numero2) << std::endl;
    // Imprime el resultado de la resta
    std::cout << "Resta: " << restar(&numero1, &numero2) << std::endl;
    // Imprime el resultado de la multiplicación
    std::cout << "Multiplicación: " << multiplicar(&numero1, &numero2) << std::endl;
    // Imprime el resultado de la división
    std::cout << "División: " << dividir(&numero1, &numero2) << std::endl;

    return 0;
}
