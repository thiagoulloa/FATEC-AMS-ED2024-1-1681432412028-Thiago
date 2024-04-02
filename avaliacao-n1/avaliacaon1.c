//ThiagoUlloa_MatheusMacedo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
} Produto;

void cadastroProduto(Produto *produtos, int *numProdutos);
void buscaProduto(Produto *produtos, int numProdutos, int codigo);
void abaixaEstoque(Produto *produtos, int numProdutos, int codigo, int quantidade);

int main() {
    Produto produtos[100];
    int numProdutos = 0;

    cadastroProduto(produtos, &numProdutos);
    buscaProduto(produtos, numProdutos, 1234);
    abaixaEstoque(produtos, numProdutos, 1234, 5);

    return 0;
}

void cadastroProduto(Produto *produtos, int *numProdutos) {

}

void buscaProduto(Produto *produtos, int numProdutos, int codigo) {
}

void abaixaEstoque(Produto *produtos, int numProdutos, int codigo, int quantidade) {
}
