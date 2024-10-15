/*
Reimplemente o programa da questão anterior utilizando a função qsort() do C. Comente o seu
código, explicando o que faz cada uma das linhas.
*/

#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    // Converte os ponteiros void para ponteiros float
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    
    // Compara os valores
    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

void lerEOrdenarFloats(int n) {
    // Aloca memória dinamicamente para armazenar os números
    float *numeros = (float *)malloc(n * sizeof(float));
    if (numeros == NULL) {
        printf("Erro na alocação de memória.\n");
        return;
    }

    // Lê os valores do usuário
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%f", &numeros[i]);
    }

    // Usa qsort para ordenar o array
    qsort(numeros, n, sizeof(float), comparar);

    // Imprime os números ordenados
    printf("Números em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numeros[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(numeros);
}

int main() {
    int n;
    printf("Quantos números você deseja inserir? ");
    scanf("%d", &n);

    lerEOrdenarFloats(n);

    return 0;
}