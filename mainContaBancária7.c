#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX_LIVROS 100

typedef struct {
	
    char titulo[50];
    char autor[50];
    int ano;
    
} Livro;

Livro livros[10];
int num_livros = 0;

void adicionar_livro() {
	
    if (num_livros == MAX_LIVROS) {
        printf("Nao e possível adicionar mais livros.\n");
        return;
    }

    printf("Título: ");
    scanf(" %[^\n]", livros[num_livros].titulo);
    printf("Autor: ");
    scanf(" %[^\n]", livros[num_livros].autor);
    printf("Ano de publicação: ");
    scanf("%d", &livros[num_livros].ano);

    num_livros++;
}

void listar_livros() {
    if (num_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int i;
    for (i = 0; i < num_livros; i++) {
        printf("%s - %s (%d)\n", livros[i].titulo, livros[i].autor, livros[i].ano);
    }
}

void buscar_por_autor() {
    char autor[50];
    printf("Autor: ");
    scanf(" %[^\n]", autor);

    int encontrados = 0;
    int i;
    for (i = 0; i < num_livros; i++) {
        if (strcmp(livros[i].autor, autor) == 0) {
            printf("%s - %s (%d)\n", livros[i].titulo, livros[i].autor, livros[i].ano);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado.\n");
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
    int opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar por autor\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_livro();
                break;
            case 2:
                listar_livros();
                break;
            case 3:
                buscar_por_autor();
                break;
            case 4:
                break;
            default:
                printf("Opção invalida.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}


