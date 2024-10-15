/*
O que é memory leak? Crie um exemplo de programa em C que contenha um memory leak e
proponha uma correção para o mesmo.

Memory leak (vazamento de memória) é um problema que ocorre quando um programa 
aloca memória dinamicamente, mas não a libera adequadamente quando não é mais 
necessária. Isso pode levar a um consumo crescente de memória ao longo do tempo,
 potencialmente esgotando os recursos do sistema.
*/


// #include <stdio.h>
// #include <stdlib.h>

// void funcaoComLeak() {
//     int *ptr = (int *)malloc(sizeof(int));
//     *ptr = 10;
//     printf("Valor alocado: %d\n", *ptr);
//     // A memória alocada não é liberada antes do fim da função
// }

// int main() {
//     for (int i = 0; i < 1000000; i++) {
//         funcaoComLeak();
//     }
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// void funcaoSemLeak() {
//     int *ptr = (int *)malloc(sizeof(int));
//     if (ptr == NULL) {
//         printf("Falha na alocação de memória\n");
//         return;
//     }
//     *ptr = 10;
//     printf("Valor alocado: %d\n", *ptr);
//     free(ptr);  // Libera a memória alocada
//     ptr = NULL; // Boa prática: define o ponteiro como NULL após liberar
// }

// int main() {
//     for (int i = 0; i < 1000000; i++) {
//         funcaoSemLeak();
//     }
//     return 0;
// }