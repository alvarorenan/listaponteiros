/*
Seja x um vetor de 4 elementos, declarado da forma TIPO x[4]. Suponha que depois da
declaração, x esteja armazenado no endereço de memória 4092 (ou seja, o endereço de x[0]).
Suponha também que na máquina seja usada uma variável do tipo char ocupa 1 byte, do tipo
int ocupa 2 bytes, do tipo float ocupa 4 bytes e do tipo double ocupa 8 bytes. Quais serão os
valores de x+1, x+2 e x+3 se:
◦ x for declarado como char?
◦ x for declarado como int?
◦ x for declarado como float?
◦ x for declarado como double?
Implemente um programa de computador para testar estas suposições e compare as respostas
oferecidas pelo programa com as respostas que você idealizou.

Para char (1 byte):
x+1 = 4092 + 1 = 4093
x+2 = 4092 + 2 = 4094
x+3 = 4092 + 3 = 4095
Para int (2 bytes):
x+1 = 4092 + 2 = 4094
x+2 = 4092 + 4 = 4096
x+3 = 4092 + 6 = 4098
Para float (4 bytes):
x+1 = 4092 + 4 = 4096
x+2 = 4092 + 8 = 4100
x+3 = 4092 + 12 = 4104
Para double (8 bytes):
x+1 = 4092 + 8 = 4100
x+2 = 4092 + 16 = 4108
x+3 = 4092 + 24 = 4116
*/
#include <stdio.h>

int main() {
    char *x;
    int *y;
    float *z;
    double *w;

    // Endereço base fictício
    unsigned long base = 4092;

    // Atribuir o endereço base aos ponteiros
    x = (char*)base;
    y = (int*)base;
    z = (float*)base;
    w = (double*)base;

    printf("Endereço base: %lu\n\n", base);

    printf("char:\n");
    printf("x+1: %lu\n", (unsigned long)(x+1));
    printf("x+2: %lu\n", (unsigned long)(x+2));
    printf("x+3: %lu\n\n", (unsigned long)(x+3));

    printf("int:\n");
    printf("y+1: %lu\n", (unsigned long)(y+1));
    printf("y+2: %lu\n", (unsigned long)(y+2));
    printf("y+3: %lu\n\n", (unsigned long)(y+3));

    printf("float:\n");
    printf("z+1: %lu\n", (unsigned long)(z+1));
    printf("z+2: %lu\n", (unsigned long)(z+2));
    printf("z+3: %lu\n\n", (unsigned long)(z+3));

    printf("double:\n");
    printf("w+1: %lu\n", (unsigned long)(w+1));
    printf("w+2: %lu\n", (unsigned long)(w+2));
    printf("w+3: %lu\n", (unsigned long)(w+3));

    return 0;
}