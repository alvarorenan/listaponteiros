/*

Determine o que será mostrado pelo seguinte programa. Compile-o, execute-o e explique se
foram obtidas as respostas esperadas. Justifique o porque de cada uma.

int main(void){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco\n");
    for(i = 0 ; i <= 4 ; i++){
    printf("i = %d",i);
    printf(" vet[%d] = %.1f",i, vet[i]);
    printf(" *(f + %d) = %.1f",i, *(f+i));
    printf(" &vet[%d] = %X",i, &vet[i]);
    printf(" (f + %d) = %X",i, f+i);
    printf("\n");
    }
}

*/

#include <stdio.h>

int main(void){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco\n");
    for(i = 0 ; i <= 4 ; i++){
        printf("i = %d",i);
        printf(" vet[%d] = %.1f",i, vet[i]);
        printf(" *(f + %d) = %.1f",i, *(f+i));
        printf(" &vet[%d] = %X",i, &vet[i]);
        printf(" (f + %d) = %X",i, f+i);
        printf("\n");
    }
}

/*O erro ocorre porque o especificador de formato %X no printf espera
um argumento do tipo unsigned int, mas você está passando um ponteiro
  do tipo float *. Para imprimir endereços de memória, o especificador
   correto é %p, que espera um argumento do tipo void *.*/