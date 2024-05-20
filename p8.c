#include <stdio.h>
#include <omp.h>

int main() {
    int num_terminos; // Variable para almacenar el número de términos de la serie

    // Solicita al usuario el número de términos
    printf("Ingrese el número de términos: ");
    scanf("%d", &num_terminos);

    int serie[num_terminos]; // Arreglo para almacenar los términos de la serie

    // Configura el número de hilos a utilizar
    int num_hilos = omp_get_max_threads();
    printf("Utilizando %d hilos.\n", num_hilos);

    // Paraleliza la generación de la serie
    #pragma omp parallel for
    for (int i = 0; i < num_terminos; i++) {
        serie[i] = (i + 1) * 2; // Calcula cada término de la serie
    }

    // Imprimir la serie generada
    printf("Serie generada: ");
    for (int i = 0; i < num_terminos; i++) {
        printf("%d ", serie[i]); // Imprime cada término de la serie
    }
    printf("\n");

    return 0;
}
