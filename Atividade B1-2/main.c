#include <stdio.h>
#include <stdlib.h>


void aplicar_desconto(float* preco, float desconto) {
    *preco -= (*preco * desconto / 100);
}

int main() {
    float preco_produto;
    float desconto;

    printf("Bem-vindo(a) à sua loja online!\n");
    printf("Digite o preço do produto: ");
    scanf("%f", &preco_produto);

    printf("Digite o desconto (em porcentagem): ");
    scanf("%f", &desconto);
 
    aplicar_desconto(&preco_produto, desconto);

    printf("Preço original: R$%.2f\n", preco_produto);
    printf("Desconto aplicado: %.2f%%\n", desconto);
    printf("Preço final após o desconto: R$%.2f\n", preco_produto);

    return 0;
}
