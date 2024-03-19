/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                       Data:18/03/2024    */
/*--------------------------------------------------------------------------*/

#include <stdio.h>

void multiplicar_elementos(int *array, int tamanho, int multiplicador) {
    for (int i = 0; i < tamanho; i++) {
        array[i] *= multiplicador;
    }
}

int main() {
    int notas[5];
    printf("Informe as 5 notas:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &notas[i]);
    }
    int multiplicador;
    printf("Informe o valor do multiplicador: ");
    scanf("%d", &multiplicador);
    multiplicar_elementos(notas, 5, multiplicador);
    printf("Elementos no array após multiplicação: ");
    imprimir_array(notas, 5);
    return 0;
}