/*
O que fazem os seguintes programas em C?
#include <stdio.h>
int main(){
    int vet[] = {4, 9, 13};
    int i;
    for(i=0;i<3;i++){
    printf("%d ", *(vet+i));
    }
}

#include <stdio.h>
int main(){
    int vet[] = {4, 9, 13};
    int i;
    for(i=0;i<3;i++){
    printf("%X ",vet+i);
    }
}

O primeiro programa imprime os valores dos elementos do vetor vet, 
enquanto o segundo programa tenta imprimir com o especificador de formato %X,
mas o tipo de dado é um ponteiro para int, então o correto seria usar o especificador de formato %p.
Logo, nao roda.
*/


#include <stdio.h>

int main(){
    int vet[] = {4, 9, 13};
    int i;
    for(i=0;i<3;i++){
        printf("%d ", *(vet+i));
    }
    return 0;
}
