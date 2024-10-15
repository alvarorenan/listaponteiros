/*
Utilize a ideia do ponteiro para função pela função qsort() para implementar sua própria
função de ordenação, mas que seja capaz de ordenar apenas inteiros do tipo int. Para isso, sua
função deverá receber, entre outros argumentos, um ponteiro para a função de comparação
que determinará como os elementos do array serão ordenados.
*/

#include <stdio.h>

// Função de ordenação personalizada
void ordenarInteiros(int *arr, int tamanho, int (*comparar)(const void*, const void*)) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (comparar(&arr[j], &arr[j + 1]) > 0) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função de comparação para ordenação crescente
int compararCrescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função de comparação para ordenação decrescente
int compararDecrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Função para imprimir o array
void imprimirArray(int *arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    // Ordenação crescente
    ordenarInteiros(arr, tamanho, compararCrescente);
    printf("Array ordenado (crescente): ");
    imprimirArray(arr, tamanho);

    // Ordenação decrescente
    ordenarInteiros(arr, tamanho, compararDecrescente);
    printf("Array ordenado (decrescente): ");
    imprimirArray(arr, tamanho);

    return 0;
}