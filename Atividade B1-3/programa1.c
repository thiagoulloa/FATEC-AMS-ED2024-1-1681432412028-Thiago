/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                       Data:18/03/2024    */
/*--------------------------------------------------------------------------*/

#include <stdio.h>

int encontrar_maior_elemento(int *array, int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

int main() {
    int notas[5];
    printf("Informe as 5 notas:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &notas[i]);
    }
    int maior = encontrar_maior_elemento(notas, 5);
    printf("O maior elemento no array é: %d\n", maior);
    return 0;
}
