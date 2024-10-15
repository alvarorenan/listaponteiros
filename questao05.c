/*
Um programador construiu o seguinte código e esperava na saída o texto gostinho, mas não
obteve essa saída. Justifique o porquê de não ter obtido o resultado esperado.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void funcao(char** str){
    str++;
}
int main(){
    char *str = (void *)malloc(50*sizeof(char));
    strcpy(str, "Agostinho");
    funcao(&str);
    puts(str);
    free(str);
    return 0;
}

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void funcao(char** str){
    str++;
}

int main(){
    char *str = (void *)malloc(50*sizeof(char));
    strcpy(str, "Agostinho");
    funcao(&str);
    puts(str);
    free(str);
    return 0;
}

/*
O programador esperava que a função funcao alterasse o valor de str, mas isso não ocorre, 
pois a função funcao recebe um ponteiro para ponteiro para char, ou seja, ela recebe o endereço 
de um ponteiro para char, e não o endereço de um char. Assim, a função funcao não altera o valor
de str, que continua apontando para o endereço de memória onde está a string "Agostinho". 
Portanto, a função puts imprime a string "Agostinho" e não "gostinho".
*/