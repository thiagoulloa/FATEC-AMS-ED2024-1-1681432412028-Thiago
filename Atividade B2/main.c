#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Produto* listaProdutos = NULL;
    int opcao;
    int codigo;
    char nome[50];
    int quantidade;
    char categoria[50];

    do {
        printf("\n=====================================\n");
        printf("  Gerenciamento de Estoque Bacana  \n");
        printf("=====================================\n");
        printf("1. Incluir Produto\n");
        printf("2. Atualizar Produto\n");
        printf("3. Excluir Produto\n");
        printf("4. Mostrar Produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n=====================================\n");
                printf("  Incluir Produto  \n");
                printf("=====================================\n");
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                printf("Digite o nome do produto: ");
                getchar(); 
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Digite a quantidade do produto: ");
                scanf("%d", &quantidade);
                getchar();
                printf("Digite a categoria do produto: ");
                fgets(categoria, sizeof(categoria), stdin);
                categoria[strcspn(categoria, "\n")] = 0;
                inserirProduto(&listaProdutos, criarProduto(codigo, nome, quantidade, categoria));
                printf("Produto adicionado com sucesso!\n");
                break;
            case 2:
                printf("\n=====================================\n");
                printf("  Atualizar Produto  \n");
                printf("=====================================\n");
                printf("Digite o código do produto a ser atualizado: ");
                scanf("%d", &codigo);
                getchar(); 
                Produto* produtoAtualizar = buscarProduto(listaProdutos, codigo);
                if (produtoAtualizar != NULL) {
                    printf("Digite o novo nome do produto: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = 0;
                    printf("Digite a nova quantidade do produto: ");
                    scanf("%d", &quantidade);
                    getchar();
                    printf("Digite a nova categoria do produto: ");
                    fgets(categoria, sizeof(categoria), stdin);
                    categoria[strcspn(categoria, "\n")] = 0;
                    strcpy(produtoAtualizar->nome, nome);
                    produtoAtualizar->quantidade = quantidade;
                    strcpy(produtoAtualizar->categoria, categoria);
                    printf("Produto atualizado com sucesso!\n");
                } else {
                    printf("Produto com código %d não encontrado.\n", codigo);
                }
                break;
            case 3:
                printf("\n=====================================\n");
                printf("  Excluir Produto  \n");
                printf("=====================================\n");
                printf("Digite o código do produto a ser excluído: ");
                scanf("%d", &codigo);
                removerProduto(&listaProdutos, codigo);
                break;
            case 4:
                printf("\n=====================================\n");
                printf("  Mostrar Produtos  \n");
                printf("=====================================\n");
                imprimirProdutos(listaProdutos);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 0);

    Produto* atual = listaProdutos;
    while (atual != NULL) {
        Produto* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}
