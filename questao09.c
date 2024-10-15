/*
Considerando a declaração
int mat[4], *p, x;
quais das seguintes expressões são válidas? Justifique.
p = mat + 1;
p = mat++;
p = ++mat;
x = (*mat);

*/

#include <stdio.h>

int main() {
    int mat[4], *p, x;
    p = mat + 1; // OK, p aponta para o segundo elemento de mat
    // p = mat++; // Erro, pois mat é um vetor e não pode ser incrementado
    // p = ++mat; // Erro, pois mat é um vetor e não pode ser incrementado
    // x = (*mat); // Erro, pois mat é um vetor e não pode ser desreferenciado
    return 0;
}
