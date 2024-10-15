/*
O que é um ponteiro para uma função? Pesquise na Internet referências sobre o assunto e
escreva um pequeno programa exemplificando o uso deste recurso. Explique seu programa,
comentando cada uma das linhas de código.

Um ponteiro para uma função é uma variável que armazena o endereço 
de memória de uma função. Isso permite que você passe funções como 
argumentos para outras funções, armazene funções em arrays ou as atribua 
a variáveis, tornando seu código mais flexível e modular.
*/

#include <stdio.h>

// Funções de exemplo
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

// Função que usa um ponteiro para função
int operacao(int (*func)(int, int), int x, int y) {
    return func(x, y);
}

int main() {
    // Declaração de ponteiros para funções
    int (*ptr_soma)(int, int) = soma;
    int (*ptr_subtracao)(int, int) = subtracao;

    int a = 10, b = 5;

    // Usando ponteiros para funções diretamente
    printf("Soma: %d\n", ptr_soma(a, b));
    printf("Subtração: %d\n", ptr_subtracao(a, b));

    // Usando ponteiros para funções como argumentos
    printf("Soma usando operacao(): %d\n", operacao(ptr_soma, a, b));
    printf("Subtração usando operacao(): %d\n", operacao(ptr_subtracao, a, b));

    return 0;
}