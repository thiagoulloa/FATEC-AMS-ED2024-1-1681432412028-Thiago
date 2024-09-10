#include <stdio.h>

int buscaLinear(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave) {
            return i; 
        }
    }
    return -1; 
}