/*
Qual será a saída do seguinte programa
#include <stdio.h>
void main(){
int const *x = 3;
printf("%d", ++(*x));
}
*/

#include <stdio.h>

void main(){
    int const *x = 3;
    printf("%d", ++(*x));
}

/*
ERRO DE COMPILAÇÃO pois o ponteiro é constante e não pode ser alterado.
*/