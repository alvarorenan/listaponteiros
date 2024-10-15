/*

Assumindo que um inteiro tem 4 bytes de tamanho, qual será a saída do seguinte programa?
Justifique sua resposta.

#include <stdio.h>
void funcao(char **p){
    char *t;
    t = (p += sizeof(int))[-1];
    printf("%s\n", t);
}
int main(){
    char *a[] = { "ab", "cd", "ef", "gh", "ij", "kl"};
    funcao(a);
    return 0;
}

*/

#include <stdio.h>
void funcao(char **p){
    char *t;
    t = (p += sizeof(int))[-1];
    printf("%s\n", t);
}
int main(){
    char *a[] = { "ab", "cd", "ef", "gh", "ij", "kl"};
    funcao(a);
    return 0;
}

// a saída será "gh", pois a função funcao recebe um ponteiro para ponteiro para char e incrementa o ponteiro