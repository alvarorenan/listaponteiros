/*
Procure na internet mecanismos que possibilitem medir tempos de execução de rotinas
computacionais. Geralmente, estas medidas são realizadas com o auxílio de funções em C que
lêem a hora no sistema (sistemas Unix e Windows geralmente usam funções diferentes).
Utilizando os conhecimentos que você obteve com sua pesquisa, meça os tempos de execução
das implementações que você criou para os dois problemas de ordenação anteriores (com seu
método de ordenação e com qsort()), considerando apenas arrays de elementos tipo int e
compare os resultados obtidos. O que se conclui nesse caso?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Seu método de ordenação (exemplo: bubble sort)
void seuMetodoOrdenacao(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n = 10000; // Tamanho do array
    int *arr1 = malloc(n * sizeof(int));
    int *arr2 = malloc(n * sizeof(int));

    // Inicializar arrays com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 10000;
        arr1[i] = num;
        arr2[i] = num;
    }

    clock_t inicio, fim;
    double tempo_decorrido;

    // Medir tempo do seu método de ordenação
    inicio = clock();
    seuMetodoOrdenacao(arr1, n);
    fim = clock();
    tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do seu método: %f segundos\n", tempo_decorrido);

    // Medir tempo do qsort
    inicio = clock();
    qsort(arr2, n, sizeof(int), comparar);
    fim = clock();
    tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do qsort: %f segundos\n", tempo_decorrido);

    free(arr1);
    free(arr2);

    return 0;
}

/*
O qsort é mais eficiente que o meu método de ordenação, pois o qsort é um algoritmo de ordenação 
interna que utiliza o algoritmo quicksort, que é mais eficiente para grandes quantidades de dados. 
Já o meu método de ordenação é um algoritmo de ordenação simples que utiliza o algoritmo bubble sort, 
que é mais eficiente para pequenas quantidades de dados.
*/