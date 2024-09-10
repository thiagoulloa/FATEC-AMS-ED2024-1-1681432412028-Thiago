#include <stdio.h>

int buscaLinearOrdenada(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave) {
            return i; 
        } else if (arr[i] > chave) {
            return -1;
        }
    }
    return -1; 
}