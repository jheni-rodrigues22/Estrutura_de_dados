#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct Contato {
    char nome[50];
    char telefone[20];
};

int main() {
	setlocale(LC_ALL, "Portuguese");
    struct Contato contatos[10];
    int numContatos = 0;

    int escolha;
    char nomeBusca[50];
    int i;

    while (1) {
        printf("Escolha a operação:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("0 - Sair\n");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        }

        switch (escolha) {
            case 1:
                if (numContatos < 10) {
                    printf("Digite o nome do contato: ");
                    scanf("%s", contatos[numContatos].nome);

                    printf("Digite o telefone do contato: ");
                    scanf("%s", contatos[numContatos].telefone);

                    numContatos++;
                    printf("Contato adicionado com sucesso!\n");
                } else {
                    printf("Limite de contatos atingido.\n");
                }
                break;

            case 2:
                if (numContatos == 0) {
                    printf("Nenhum contato registrado.\n");
                } else {
                    printf("Lista de contatos:\n");
                    for (i = 0; i < numContatos; i++) {
                        printf("%d. Nome: %s - Telefone: %s\n", i + 1, contatos[i].nome, contatos[i].telefone);
                    }
                }
                break;

            case 3:
                printf("Digite o nome para buscar: ");
                scanf("%s", nomeBusca);

                int encontrado = 0;
                for (i = 0; i < numContatos; i++) {
                    if (strcmp(contatos[i].nome, nomeBusca) == 0) {
                        printf("Contato encontrado:\n");
                        printf("Nome: %s - Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Contato não encontrado.\n");
                }
                break;

            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}

