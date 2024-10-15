/*
Mostre o que será impresso pelo programa supondo que a variável i ocupa o endereço 4094 na
memória e que nessa arquitetura os inteiros possuem 2 bytes de tamanho.
main(){
    int i=5, *p;
    p = &i;
    printf("%p %p %d %d %d %d\n", p, p+1, *p+2, **&p, 3**p, **&p+4);
}
*/

#include <stdio.h>

int main() {
    int i = 5, *p;
    p = &i;
    // p = 4094
    // p + 1 = 4094 + 2 = 4096
    // *p + 2 = 5 + 2 = 7
    // **&p = 5
    // 3 * *p = 3 * 5 = 15
    // **&p + 4 = 5 + 4 = 9
    printf("%p %p %d %d %d %d\n", p, p + 1, *p + 2, **&p, 3 * *p, **&p + 4);
    return 0;
}