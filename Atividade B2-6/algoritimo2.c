/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof Veríssimo                                 */
/*             Objetivo: Inserção de elemento no Array meio arrray        */
/*             Paradigama: - Lista ordenada - Inserir dados               */
/*                                                                        */
/* ~Pedro Coelho do Nascimento & Thiago André Ulloa        Data:28/05/2024*/
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <time.h> 

void inserir(int arr[], int *size, int value) {
    int pos = (*size) / 2;  // Encontrar a posição do meio
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];  // Deslocar elementos para a direita
    }
    arr[pos] = value;  // Inserir o valor no meio
    (*size)++;  // Incrementar o tamanho do array
}

void imprimirArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[5] = {10, 25, 40, 80};  // Array original
    int size = 4;
    clock_t inicio, fim;

    inicio = clock(); // Medir o tempo inicial

    inserir(arr, &size, 30);

    printf("Array após inserção: ");
    imprimirArray(arr, 5);
    printf("\n");
  
    fim = clock(); // Medir o tempo final
    double tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de processamento do programa: %f segundos\n", tempo_total);

    return 0;
}
