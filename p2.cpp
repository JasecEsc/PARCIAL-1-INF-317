#include <iostream>

int suma(int *a, int *b) {
    return *a + *b;
}

int resta(int *a, int *b) {
    return *a - *b;
}

int multiplicacion(int *a, int *b) {
    int resultado = 0;
    for (int i = 0; i < *b; i++) {
        resultado += *a;
    }
    return resultado;
}

float division(int *a, int *b) {
    if (*b == 0) {
        std::cout << "Error: División por cero" << std::endl;
        return 0;
    }
    float resultado = 0;
    float temp = *a;
    while (temp >= *b) {
        temp -= *b;
        resultado++;
    }
    return resultado;
}

int main() {
    int num1, num2;
    num1 = 60;
    num2 = 30;
    std::cout << "Suma: " << suma(&num1, &num2) << std::endl;
    std::cout << "Resta: " << resta(&num1, &num2) << std::endl;
    std::cout << "Multiplicación: " << multiplicacion(&num1, &num2) << std::endl;
    std::cout << "División: " << division(&num1, &num2) << std::endl;

    return 0;
}
