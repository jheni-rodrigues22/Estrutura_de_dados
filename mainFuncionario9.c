#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    int anoAdmissao;
};

void darAumento(struct Funcionario *funcionario, float aumento) {
    funcionario->salario += aumento;
}

int calcularTempoAdmissao(struct Funcionario funcionario, int anoAtual) {
    return anoAtual - funcionario.anoAdmissao;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Funcionario funcionario;

    printf("Digite o nome do funcion�rio: ");
    fflush(stdin);
    fgets(funcionario.nome,50,stdin);

    printf("Digite o ano de admiss�o do funcion�rio: ");
    scanf("%d", &funcionario.anoAdmissao);
    
    printf("Digite o cargo do funcion�rio: ");
    fflush(stdin);
    fgets(funcionario.cargo,50,stdin);
    
    printf("Digite o sal�rio mensal: ");
    scanf("%f", &funcionario.salario);
    
    funcionario.salario = 3000.0;

    printf("Sal�rio antes do aumento: R$%.2f\n", funcionario.salario);

    darAumento(&funcionario, 1000.0);
    printf("Sal�rio ap�s o aumento: R$%.2f\n", funcionario.salario);

    int anoAtual = 2023;
    int anosAdmissao = calcularTempoAdmissao(funcionario, anoAtual);
    printf("Tempo de admiss�o: %d anos\n", anosAdmissao);

    return 0;
}

