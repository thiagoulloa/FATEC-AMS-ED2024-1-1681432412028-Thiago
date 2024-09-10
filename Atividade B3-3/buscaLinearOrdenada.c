/* -------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Implementação de algoritmos de busca
Autor: Thiago Ulloa
Data: 09/09/2024
------------------------------------------- */

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