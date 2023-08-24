#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
    float altura;
} Pessoa;

Pessoa setPessoa(char nome[30], int idade, float altura) {
    Pessoa P;
    strncpy(P.nome, nome, sizeof(P.nome));
    P.idade = idade;
    P.altura = altura;
    return P;
}

void imprimePessoa(Pessoa P) {
    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", P.nome, P.idade, P.altura);
}

int main() {
    Pessoa Jhenifer;

    Jhenifer = setPessoa("Jhenifer", 23, 1.72);

    imprimePessoa(Jhenifer);
    return 0;
}

