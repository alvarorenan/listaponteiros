/*
Crie uma função capaz de realizar multiplicação matricial da forma C = AxB. A função deve
receber 6 argumentos: os ponteiros para as matrizes A, B e C, o número de linhas e colunas de A
e o número de colunas de B (assuma que o número de coluna de A é igual ao número de linhas
de B). O resultado da multiplicação deve ficar armazenado em C. Crie um programa para testar
sua implementação, capaz de utilizar a função de multiplicação e imprimir as três matrizes. A
função criada para multiplicação não deve realizar nenhum tipo de saída de dados no terminal.
Exemplo: para multiplicar duas matrizes (A e B) de dimensões 2x3 e 3x4, respectivamente (o
resultado deve ficar armazenado em C).
multiplica_matrizes(A, B, C, 2, 3, 4)
*/

#include <stdio.h>
#include <stdlib.h>

// Função para multiplicação de matrizes
void multiplica_matrizes(int **A, int **B, int **C, int linhasA, int colunasA, int colunasB) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Função auxiliar para criar matriz
int** cria_matriz(int linhas, int colunas) {
    int **matriz = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }
    return matriz;
}

// Função auxiliar para preencher matriz
void preenche_matriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10; // Valores aleatórios de 0 a 9
        }
    }
}

// Função auxiliar para imprimir matriz
void imprime_matriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int linhasA = 2, colunasA = 3, colunasB = 4;
    
    // Criar matrizes
    int **A = cria_matriz(linhasA, colunasA);
    int **B = cria_matriz(colunasA, colunasB);
    int **C = cria_matriz(linhasA, colunasB);
    
    // Preencher matrizes A e B
    preenche_matriz(A, linhasA, colunasA);
    preenche_matriz(B, colunasA, colunasB);
    
    // Multiplicar matrizes
    multiplica_matrizes(A, B, C, linhasA, colunasA, colunasB);
    
    // Imprimir matrizes
    printf("Matriz A:\n");
    imprime_matriz(A, linhasA, colunasA);
    
    printf("Matriz B:\n");
    imprime_matriz(B, colunasA, colunasB);
    
    printf("Matriz C (resultado):\n");
    imprime_matriz(C, linhasA, colunasB);
    
    // Liberar memória
    for (int i = 0; i < linhasA; i++) {
        free(A[i]);
    }
    free(A);

    for (int i = 0; i < colunasA; i++) {
        free(B[i]);
    }
    free(B);

    for (int i = 0; i < linhasA; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}