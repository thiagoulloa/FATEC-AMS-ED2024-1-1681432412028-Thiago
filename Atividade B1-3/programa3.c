#include <stdio.h>

void imprimir_array(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int notas[5];
    printf("Informe as 5 notas:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &notas[i]);
    }
    printf("Elementos no array: ");
    imprimir_array(notas, 5);
    return 0;
}