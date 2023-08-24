#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct Livro {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
    struct Livro livros[10];
    int numLivros = 0;

    int escolha;
    char autorBusca[100];
    int i;

    while (1) {
        printf("Escolha a operação:\n");
        printf("1 - Adicionar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livros por autor\n");
        printf("0 - Sair\n");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        }

        switch (escolha) {
            case 1:
                if (numLivros < 10) {
                    printf("Digite o título do livro: ");
                    scanf(" %[^\n]", livros[numLivros].titulo);

                    printf("Digite o autor do livro: ");
                    scanf(" %[^\n]", livros[numLivros].autor);

                    printf("Digite o ano de publicação do livro: ");
                    scanf("%d", &livros[numLivros].anoPublicacao);

                    numLivros++;
                    printf("Livro adicionado com sucesso!\n");
                } else {
                    printf("Limite de livros atingido.\n");
                }
                break;

            case 2:
                if (numLivros == 0) {
                    printf("Nenhum livro cadastrado.\n");
                } else {
                    printf("Lista de livros:\n");
                    for (i = 0; i < numLivros; i++) {
                        printf("%d. Título: %s - Autor: %s - Ano: %d\n", i + 1, livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
                    }
                }
                break;

            case 3:
                printf("Digite o autor para buscar: ");
                scanf(" %[^\n]", autorBusca);

                int encontrados = 0;
                for (i = 0; i < numLivros; i++) {
                    if (strcmp(livros[i].autor, autorBusca) == 0) {
                        printf("Livro encontrado:\n");
                        printf("Título: %s - Autor: %s - Ano: %d\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
                        encontrados++;
                    }
                }

                if (encontrados == 0) {
                    printf("Nenhum livro encontrado para o autor '%s'.\n", autorBusca);
                }
                break;

            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}

