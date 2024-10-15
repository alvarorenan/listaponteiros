/*
Considere o exemplo seguinte. Compile-o, execute-o e JUSTIFI, usando os recursos que julgar
necessários, porque o programa imprime o resultado que imprime.
#include <stdio.h>
char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"};
char **b[] = {a + 3, a + 2, a + 1, a};
char ***c = b;
int main() {
printf("%s ", **++c);
printf("%s ", *--*++c + 3);
printf("%s ", *c[-2] + 3);
printf("%s ", c[-1][-1] + 1);
return 0;
}
*/

#include <stdio.h>

char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"};
char **b[] = {a + 3, a + 2, a + 1, a};
char ***c = b;

int main() {
    printf("%s ", **++c);
    printf("%s ", *--*++c + 3);
    printf("%s ", *c[-2] + 3);
    printf("%s ", c[-1][-1] + 1);
    return 0;
}


/*
1. printf("%s ", **++c);
c é incrementado, apontando agora para b[1] (que contém a + 2)
**++c resulta em "BRITO"
2. printf("%s ", *--*++c + 3);
c é incrementado novamente, apontando para b[2] (que contém a + 1)
*++c aponta para a + 1
--*++c decrementa isso para a
*--*++c resulta em "AGOSTINHO"
*--*++c + 3 pula 3 caracteres, resultando em "STINHO"
3. printf("%s ", *c[-2] + 3);
c[-2] é equivalente a b[0], que contém a + 3
*c[-2] resulta em "JUNIOR"
*c[-2] + 3 pula 3 caracteres, resultando em "IOR"
4. printf("%s ", c[-1][-1] + 1);
c[-1] é equivalente a b[3], que contém a
c[-1][-1] é equivalente a a[-1], que é o elemento anterior a a[0]
No arranjo de ponteiros, isso acaba apontando para "MEDEIROS"
c[-1][-1] + 1 pula 1 caractere, resultando em "EDEIROS"
*/