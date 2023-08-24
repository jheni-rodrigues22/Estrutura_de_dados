#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct Estudante {
    char nome[30];
    int matricula;
    float nota1, nota2, nota3;
};

float calcularMedia(struct Estudante aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
}

int resultadoFinal(struct Estudante aluno) {
    float media = calcularMedia(aluno);
    if (media >= 7.0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    struct Estudante aluno;
    
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);
    
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &aluno.matricula);
    
    printf("\nDigite as notas em três disciplinas:\n");
    printf("Nota 1: ");
    scanf("%f", &aluno.nota1);
    
    printf("Nota 2: ");
    scanf("%f", &aluno.nota2);
    
    printf("Nota 3: ");
    scanf("%f", &aluno.nota3);
    
    
    if (resultadoFinal(aluno)) {
        printf("O aluno %s está aprovado!\n", aluno.nome);
    } else {
        printf("O aluno %s não está aprovado.\n", aluno.nome);
    }
    
    return 0;
}

