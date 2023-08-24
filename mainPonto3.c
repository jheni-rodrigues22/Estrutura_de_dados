#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct {
    float x, y;
} Ponto;

float distancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

float inclinacao(Ponto p1, Ponto p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Ponto p1, p2;
    
    printf("Digite os valores para a primeira coordenada: ");
    scanf("%f %f", &p1.x, &p1.y);
    
    printf("Digite os valores para a segunda coordenada: ");
    scanf("%f %f", &p2.x, &p2.y);
    
    printf("Distância: %.2f\n", distancia(p1, p2));
    
    if (p1.x == p2.x) {
        printf("Inclinação: Indefinida (divisão por zero)\n");
    } else {
        printf("Inclinação: %.2f\n", inclinacao(p1, p2));
    }
    
    return 0;
}

