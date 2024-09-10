#include <stdio.h>

int buscaBinaria(int arr[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == chave) {
            return meio; 
        }

        if (arr[meio] < chave) {
            inicio = meio + 1; 
        } else {
            fim = meio - 1; 
        }
    }
    return -1; 
}