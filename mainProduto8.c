#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Produto {
    char nome[50];
    float preco;
    int estoque;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
    struct Produto produtos[5] = {
        {"Arroz", 18.99, 20},
        {"Feijão", 6.99, 15},
        {"Açúcar", 14.99, 8},
        {"Desinfetante", 6.99, 30},
        {"Leite", 4.99, 12 }
    };

    int escolha;
    float total = 0;
    int i;

    while (1) {
        printf("Produtos disponíveis:\n");

        i = 0;
        while (i < 5) {
            printf("%d. %s - R$%.2f (%d em estoque)\n", i + 1, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
            i++;
        }

        printf("Escolha um produto para comprar (0 para finalizar): ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        }

        if (escolha < 1 || escolha > 5) {
            printf("Opção inválida.\n");
            continue;
        }

        int indice = escolha - 1;
        if (produtos[indice].estoque > 0) {
            total += produtos[indice].preco;
            produtos[indice].estoque--;

            printf("Total atual: R$%.2f\n", total);
        } else {
            printf("Produto fora de estoque.\n");
        }
    }

    printf("Total da compra: R$%.2f\n", total);

    return 0;
}

