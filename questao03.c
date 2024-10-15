/*
. Se i e j são variáveis inteiras e p e q ponteiros para int, quais das seguintes expressões de
atribuição produzem erro de compilação? Justifique.
p = &i;
*q = &j;
p = &*&i;
i = (*&)j;
i = *&j;
i = *&*&j;
q = *p;
i = (*p)++ + *q;
*/

#include <stdio.h>

int main() {
    int i = 3, j = 5;
    int *p, *q;
    // p = &i; // OK
    // *q = &j; // Erro, pois *q é um valor e não um endereço
    // p = &*&i; // OK
    // i = (*&)j; // Erro, pois * não pode ser aplicado a um valor
    // i = *&j; // OK
    // i = *&*&j; // OK
    // q = *p; // Erro, pois q é um ponteiro e *p é um valor
    // i = (*p)++ + *q; // OK
    return 0;
}