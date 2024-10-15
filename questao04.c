/*Determine o que será mostrado pelo seguinte program nos trechos (a) até (n). Compile-o,
execute-o e verifique se foram obtidas as respostas esperadas. Justifique o porque de cada uma.*/

#include <stdio.h>

int main() {
    int valor;
    int *p1;
    float temp;
    float *p2;
    char aux;
    char *nome = "Ponteiros";
    char *p3;
    int idade;
    int vetor[3];
    int *p4;
    int *p5;
    /* (a) */
    valor = 10;
    p1 = &valor;
    *p1 = 20;
    printf("%d \n", valor);
    // 20, pois p1 aponta para valor e *p1 é o valor de valor
    /* (b) */
    temp = 26.5;
    p2 = &temp;
    *p2 = 29.0;
    printf("%.1f \n", temp);
    // 29.0, pois p2 aponta para temp e *p2 é o valor de temp
    /* (c) */
    p3 = &nome[0];
    aux = *p3;
    printf("%c \n", aux);
    // P, pois p3 aponta para o primeiro caractere de nome e *p3 é o valor do primeiro caractere de nome
    /* (d) */
    p3 = &nome[4];
    aux = *p3;
    printf("%c \n", aux);
    // e, pois p3 aponta para o quinto caractere de nome e *p3 é o valor do quinto caractere de nome
    /* (e) */
    p3 = nome;
    printf("%c \n", *p3);
    // P, pois p3 aponta para o primeiro caractere de nome e *p3 é o valor do primeiro caractere de nome
    /* (f) */
    p3 = p3 + 4;
    printf("%c \n", *p3);
    // e, pois p3 aponta para o quinto caractere de nome e *p3 é o valor do quinto caractere de nome
    /* (g) */
    p3--;
    printf("%c \n", *p3);
    // t, pois p3 aponta para o quarto caractere de nome e *p3 é o valor do quarto caractere de nome
    /* (h) */
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;
    idade = *p4;
    printf("%d \n", idade);
    // 31, pois p4 aponta para o primeiro elemento de vetor e *p4 é o valor do primeiro elemento de vetor
    /* (i) */
    p5 = p4 + 1;
    idade = *p5;
    printf("%d \n", idade);
    // 45, pois p5 aponta para o segundo elemento de vetor e *p5 é o valor do segundo elemento de vetor
    /* (j) */
    p4 = p5 + 1;
    idade = *p4;
    printf("%d \n", idade);
    // 27, pois p4 aponta para o terceiro elemento de vetor e *p4 é o valor do terceiro elemento de vetor
    /* (l) */
    p4 = p4 - 2;
    idade = *p4;
    printf("%d \n", idade);
    // 31, pois p4 aponta para o primeiro elemento de vetor e *p4 é o valor do primeiro elemento de vetor
    /* (m) */
    p5 = &vetor[2] - 1;
    printf("%d \n", *p5);
    // 45, pois p5 aponta para o segundo elemento de vetor e *p5 é o valor do segundo elemento de vetor
    /* (n) */
    p5++;
    printf("%d \n", *p5);
    // 27, pois p5 aponta para o terceiro elemento de vetor e *p5 é o valor do terceiro elemento de vetor
    return 0;
}