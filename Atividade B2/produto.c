#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Produto* criarProduto(int codigo, const char* nome, int quantidade, const char* categoria) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    if (novoProduto != NULL) {
        novoProduto->codigo = codigo;
        strcpy(novoProduto->nome, nome);
        novoProduto->quantidade = quantidade;
        strcpy(novoProduto->categoria, categoria);
        novoProduto->proximo = NULL;
    }
    return novoProduto;
}

void inserirProduto(Produto** lista, Produto* novoProduto) {
    if (*lista == NULL) {
        *lista = novoProduto;
    } else {
        Produto* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoProduto;
    }
}

void imprimirProdutos(Produto* lista) {
    if (lista == NULL) {
        printf("Lista de produtos vazia.\n");
        return;
    }
    printf("=====================================\n");
    printf("  Lista de Produtos  \n");
    printf("=====================================\n");
    while (lista != NULL) {
        printf("Código: %d\n", lista->codigo);
        printf("Nome: %s\n", lista->nome);
        printf("Quantidade: %d\n", lista->quantidade);
        printf("Categoria: %s\n", lista->categoria);
        printf("-------------------------------------\n");
        lista = lista->proximo;
    }
}

Produto* buscarProduto(Produto* lista, int codigo) {
    while (lista != NULL && lista->codigo != codigo) {
        lista = lista->proximo;
    }
    return lista;
}

void removerProduto(Produto** lista, int codigo) {
    Produto* atual = *lista;
    Produto* anterior = NULL;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            *lista = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
        printf("Produto com código %d removido com sucesso!\n", codigo);
    } else {
        printf("Produto com código %d não encontrado.\n", codigo);
    }
}
