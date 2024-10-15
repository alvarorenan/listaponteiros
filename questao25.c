/*
 (ENADE, 2023) Memory leak, ou vazamento de memória, é um problema que ocorre em
sistemas computacionais quando uma parte da memória, alocada para uma determinada
operação, não é liberada quando se torna desnecessária. Na linguagem C, esse tipo de problema
é quase sempre relacionado ao uso incorreto das funções malloc( ) e free( ). Esse erro de
programação pode levar a falhas no sistema se a memória for completamente consumida. Um
dos trechos abaixo apresenta um vazamento de memória. Identifique-o e justifique sua
8
resposta.
//(A)
void f( ){
void *s;
s = malloc(50);
free(s);
}
//(B)
int f( ){
float *a;
return 0;
}
//(C)
int f(char *data){
void *s;
s = malloc(50);
int size = strlen(data);
if (size > 50)
return(-1);
free(s);
return 0;
}
//(D)
int *f(int n){
int *num = malloc(sizeof(int)*n);
return num;
}
int main(void){
int *num;
num = f(10);
free(num);
return 0;
}
//(E)
void f(int n){
char *m = malloc(10);
char *n = malloc(10);
free(m);
m = n;
free(m);
9
free(n);
}
*/

/*

O trecho que apresenta um vazamento de memória é o (C):
int f(char *data){
    void *s;
    s = malloc(50);
    int size = strlen(data);
    if (size > 50)
        return(-1);
    free(s);
    return 0;
}

Neste trecho, há um vazamento de memória porque a memória alocada com malloc(50) não é liberada em todos os caminhos de execução da função. Se o tamanho da string data for maior que 50, a função retorna -1 sem liberar a memória alocada para s. Isso resulta em um vazamento de memória, pois o espaço alocado não pode ser reutilizado pelo sistema e não há mais referência a ele.
Para corrigir este problema, a função deveria liberar a memória antes de retornar, independentemente do resultado da condição:

int f(char *data){
    void *s;
    s = malloc(50);
    int size = strlen(data);
    if (size > 50) {
        free(s);  // Libera a memória antes de retornar
        return(-1);
    }
    free(s);
    return 0;
}

Quanto aos outros trechos:
(A) Não há vazamento, pois a memória alocada é corretamente liberada com free(s).
(B) Não há alocação dinâmica de memória, portanto não há vazamento.
(D) Não há vazamento na função f(), mas a responsabilidade de liberar a memória é transferida para o chamador. No main(), a memória é corretamente liberada com free(num).
(E) Não há vazamento, mas há um erro de lógica. A memória alocada para n é liberada duas vezes, o que pode causar comportamento indefinido.

*/