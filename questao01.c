/*
Seja o seguinte trecho de programa:
int i=3,j=5;
int *p, *q;
p = &i;
q = &j;

Determine o valor das seguintes expressões, justificando o porquê de cada resultado:
◦ p == &i;
◦ *p - *q;
◦ **&p;
◦ 3 - *p/(*q) + 7;

*/

#include <stdio.h>

int main() {
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;
    printf("p == &i: %d\n", p == &i);
    // p == &i: 1, pois p é um ponteiro que aponta para o endereço de i
    printf("*p - *q: %d\n", *p - *q);
    // *p - *q: -2, pois *p é o valor de i e *q é o valor de j
    printf("**&p: %d\n", **&p);
    // **&p: 3, pois *&p é o endereço de i e **&p é o valor de i
    printf("3 - *p/(*q) + 7: %d\n", 3 - *p/(*q) + 7);
    // 3 - *p/(*q) + 7: 7, pois *p/(*q) é 3/5 = 0, logo 3 - 0 + 7 = 10

    return 0;
}