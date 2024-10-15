/*
mplemente em linguagem C uma função em um programa de computador que leia n valores do
7
tipo float do teclado e os apresente em ordem crescente. Utilize alocação dinâmica de memória
para armazenar o conjunto de pontos lidos.
*/

#include <stdio.h>
#include <stdlib.h>

void lerEOrdenarFloats(int n) {
    float *numeros = (float *)malloc(n * sizeof(float));
    if (numeros == NULL) {
        printf("Erro na alocação de memória.\n");
        return;
    }

    // Leitura dos valores
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%f", &numeros[i]);
    }

    // Ordenação (usando bubble sort para simplicidade)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                float temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    // Apresentação dos valores ordenados
    printf("Números em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numeros[i]);
    }
    printf("\n");

    free(numeros);
}

int main() {
    int n;
    printf("Quantos números você deseja inserir? ");
    scanf("%d", &n);

    lerEOrdenarFloats(n);

    return 0;
}