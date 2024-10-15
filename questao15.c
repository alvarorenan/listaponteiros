/*
O que será mostrado na tela pelo seguinte programa? Justifique sua resposta.
#include <stdio.h>
int main(){
unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6},
{7, 8, 9}, {10, 11, 12}};
printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);
}
*/

#include <stdio.h>

int main(){
    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);
}


/*

Os avisos ocorrem porque há uma incompatibilidade entre os especificadores de formato (%u) usados no printf e os tipos reais dos argumentos passados. O %u espera unsigned int, mas os argumentos são:
x+3: ponteiro para um array de 3 unsigned ints, não um unsigned int simples.
(x+3): ponteiro para unsigned int, não um valor unsigned int.
(x+2)+3: também um ponteiro para unsigned int, resultado de aritmética de ponteiros.

*/
