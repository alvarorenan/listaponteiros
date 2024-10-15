/*
Assumindo que pulo[] é um vetor do tipo int, qual das seguintes expressões referenciam o valor
do terceiro elemento do vetor?
◦ *(pulo + 2);
◦ *(pulo + 4);
◦ pulo + 4;
◦ pulo + 2;

A expressão *(pulo + 2) referencia o valor do terceiro elemento do vetor pulo[], pois pulo + 2
*/

#include <stdio.h>

int main() {
    int pulo[5] = {1, 2, 3, 4, 5};
    printf("*(pulo + 2): %d\n", *(pulo + 2));
    printf("*(pulo + 4): %d\n", *(pulo + 4));
    printf("pulo + 4: %p\n", pulo + 4);
    printf("pulo + 2: %p\n", pulo + 2);
    return 0;
}