#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
    char categoria[50];
    struct Produto* proximo;
} Produto;

Produto* criarProduto(int codigo, const char* nome, int quantidade, const char* categoria);
void inserirProduto(Produto** lista, Produto* novoProduto);
void imprimirProdutos(Produto* lista);
Produto* buscarProduto(Produto* lista, int codigo);
void removerProduto(Produto** lista, int codigo);

#endif
