/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof Veríssimo                                 */
/*             Objetivo: Inserir nó, com valor 30 no meio da lista ligada */
/*             Paradigama: Lista ordenada - Inserir dados                 */
/*                                                                        */
/* ~Thiago André Ulloa & Pedro Coelho do Nascimento        Data:28/05/2024*/
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
  int data;
  struct Node *next;
};

void insertNode(struct Node *prevNode) {
  if (prevNode == NULL) {
    printf("O nó anterior não pode ser nulo.\n");
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = 30;

  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

int main() {
  struct Node *head = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;
  struct Node *fourth = NULL;
  struct Node *fifth = NULL;

  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));

  head->data = 10;
  head->next = second;

  second->data = 25;
  second->next = third;

  third->data = 40;
  third->next = fourth;

  fourth->data = 80;
  fourth->next = fifth;


  clock_t start = clock();

  insertNode(second);

  clock_t end = clock();

  struct Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nTempo de processamento: %.6f segundos\n", time_taken);

  return 0;
}
