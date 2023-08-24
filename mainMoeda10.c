#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Moeda {
    float dolares;
    float euros;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
    float taxaDolarParaEuro = 0.92; // 1 dólar = 0.92 euros

    struct Moeda moeda;

    printf("Escolha a operacao:\n");
    printf("1 - Converter de Dolar para Euro\n");
    printf("2 - Converter de Euro para Dolar\n");
    int escolha;
    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("Digite o valor em dólares: ");
        scanf("%f", &moeda.dolares);

        moeda.euros = moeda.dolares * taxaDolarParaEuro;

        printf("Valor em euros: %.2f\n", moeda.euros);
    } else if (escolha == 2) {
        printf("Digite o valor em euros: ");
        scanf("%f", &moeda.euros);

        moeda.dolares = moeda.euros / taxaDolarParaEuro;

        printf("Valor em dólares: %.2f\n", moeda.dolares);
    } else {
        printf("Escolha invalida.\n");
    }

    return 0;
}

