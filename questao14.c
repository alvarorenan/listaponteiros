/*
Justifique porque a saída do seguinte programa é mostrado o valor 22
#include <stdio.h>
int f(int a, int *pb, int **ppc) {
int b, c;
**ppc += 1;
c = **ppc;
*pb += 2;
b = *pb;
a += 3;
return a + b + c;
}
void main() {
int c, *b, **a;
c = 5;
b = &c;
a = &b;
printf("%d\n", f(c, b, a));
getchar();
}
*/

#include <stdio.h>

int f(int a, int *pb, int **ppc) {
    int b, c;
    **ppc += 1;  // Incrementa o valor apontado por *ppc (c) em 1
    c = **ppc;   // c recebe o valor atualizado de **ppc (6)
    *pb += 2;    // Incrementa o valor apontado por pb (c) em 2
    b = *pb;     // b recebe o valor atualizado de *pb (8)
    a += 3;      // Incrementa a em 3 (a agora é 8)
    return a + b + c;  // Retorna 8 + 8 + 6 = 22
}

void main() {
    int c, *b, **a;
    c = 5;       // Inicializa c com 5
    b = &c;      // b aponta para c
    a = &b;      // a aponta para b
    printf("%d\n", f(c, b, a));
    getchar();
}
/*

O valor impresso é 22 porque:
a termina com o valor 8
b termina com o valor 8
c (variável local da função) termina com o valor 6
A soma desses três valores é 22

*/
