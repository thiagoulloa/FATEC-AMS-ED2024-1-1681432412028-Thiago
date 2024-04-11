/* -------------------------------------------------------*
 * FATEC-São Caetano do Sul Estrutura de Dados     *
 *                                     Avaliação N1 - Parte I       *
 * Objetivo: Controlar Estoque de produtos            *
 *                                                                              *
 * Autores: <Thiago Ulloa & Matheus Macedo>          *
 *                                                   Data:02/04/2024*
 *------------------------------------------------------*
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int id;
    char nome[50];
    int quantidade;
    struct Produto *prox;
} Produto;

void cadastrarProduto(Produto **estoque);
Produto *buscarProduto(Produto *estoque, int id);
void baixarProduto(Produto **estoque, int id, int quantidade);


int main() {
    Produto *estoque = NULL;
    int opcao, id, quantidade;

    do {
        printf("\n1. Cadastrar produto\n");
        printf("2. Buscar produto\n");
        printf("3. Baixar produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarProduto(&estoque);
                break;
            case 2:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                Produto *p = buscarProduto(estoque, id);
                if (p != NULL)
                    printf("Produto encontrado: %s\n", p->nome);
                else
                    printf("Produto nao encontrado.\n");
                break;
            case 3:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                printf("Digite a quantidade a ser baixada: ");
                scanf("%d", &quantidade);
                baixarProduto(&estoque, id, quantidade);
                break;
            
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}

void cadastrarProduto(Produto **estoque) {
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    printf("Digite o ID do produto: ");
    scanf("%d", &novoProduto->id);
    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novoProduto->quantidade);

    novoProduto->prox = *estoque;
    *estoque = novoProduto;

    printf("Produto cadastrado com sucesso.\n");
}

Produto *buscarProduto(Produto *estoque, int id) {
    Produto *atual = estoque;
    while (atual != NULL) {
        if (atual->id == id)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

void baixarProduto(Produto **estoque, int id, int quantidade) {
    Produto *produto = buscarProduto(*estoque, id);
    if (produto != NULL) {
        if (produto->quantidade >= quantidade) {
            produto->quantidade -= quantidade;
            printf("Baixa de estoque realizada com sucesso.\n");
        } else {
            printf("Quantidade em estoque insuficiente.\n");
        }
    } else {
        printf("Produto nao encontrado.\n");
    }
}
