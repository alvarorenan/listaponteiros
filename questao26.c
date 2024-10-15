/*
(ENADE, 2023) Na programação de sistemas embarcados, algumas posições de memória servem
para diferentes propósitos, não apenas para armazenar valores. Em algumas dessas memórias,
cada um os bits possui um significado diferente, sendo necessário manipulá-los
individualmente ou em pequenos grupos. Por isso, o conhecimento da álgebra booliana, bem
como dos operadores tilizados para realizar operações binárias nas linguagens de programação,
é essencial para o desenvolvimento desse tipo de sistema. A partir dessas informações, observe
o código apresentado a seguir, escrito na linguagem C, que faz uso de operações binárias sobre
variáveis inteiras.
#include <stdio.h>
int main(){
int a, b;
int x, y, z;
scanf("%d %d", &a, &b);
x = a; y = b; z = a + b;
while (a) {
x = x | b;
y = y ^ a;
z = z & (a+b);
a = a >> 1;
b = b << 1;
}
printf ("%d %d %d\n", x, y, z);
return 0;
}
Após a chamada desse programa, caso o usuário entre com os valores 10 e 1, nessa ordem, qual
será, exatamente, o valor da saída do programa? Explique, PASSO-A-PASSO, os cálculos
realizados pelo programa para chegar a esse resultado.
*/


/*
Analisando o programa, posso dizer que a saída será 15 13 0. Vou explicar como cheguei a esse resultado. Primeiro, o programa recebe os valores 10 e 1 como entrada. Então, inicializa as variáveis assim: a = 10 (que é 1010 em binário), b = 1 (0001 em binário), x = 10, y = 1 e z = 11 (que é a soma de a e b).
O programa então entra num loop while que continua enquanto 'a' não for zero. Na primeira volta do loop, as operações resultam em: x = 11, y = 11, z = 11, a = 5 e b = 2. Na segunda volta, temos: x ainda 11, y muda para 14, z vira 3, a = 2 e b = 4. Na terceira iteração: x se torna 15, y = 12, z = 2, a = 1 e b = 8. Na última volta: x permanece 15, y fica 13, z se torna 0, a finalmente chega a 0 e b = 16.
As operações usadas (OR, XOR, AND, shift right e left) vão modificando os bits das variáveis a cada iteração. O OR vai acumulando bits em x, o XOR alterna bits em y, e o AND vai zerando bits em z. Enquanto isso, 'a' vai sendo dividido por 2 e 'b' multiplicado por 2 a cada volta.
No final, quando 'a' chega a zero, o loop termina e o programa imprime os valores finais de x, y e z, que são 15, 13 e 0.
*/

