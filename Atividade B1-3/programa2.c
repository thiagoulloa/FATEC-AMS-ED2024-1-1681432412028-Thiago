/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                       Data:18/03/2024    */
/*--------------------------------------------------------------------------*/

#include <stdio.h>

int calcular_soma_elementos(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

int main() {
    int notas[5];
    printf("Informe as 5 notas:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &notas[i]);
    }
    int soma = calcular_soma_elementos(notas, 5);
    printf("A soma dos elementos no array é: %d\n", soma);
    return 0;
}