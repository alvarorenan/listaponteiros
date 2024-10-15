/*
(ENADE, 2021) Observe o código abaixo escrito na linguagem C.
#include <stdio.h>
#define TAM 10
int funcao1(int vetor[], int v){
int i;
for (i = 0; i < TAM; i++){
if (vetor[i] == v)
return i;
}
return -1;
}
int funcao2(int vetor[], int v, int i, int f){
int m = (i + f) / 2;
if (v == vetor[m])
10
return m;
if (i >= f)
return -1;
if (v > vetor[m])
return funcao2(vetor, v, m+1, f);
else
return funcao2(vetor, v, i, m-1);
}
int main(){
int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
printf("%d - %d", funcao1(vetor, 15), funcao2(vetor, 15, 0, TAM-1));
return 0;
}
A respeito das funções implementadas, avalie as afirmações a seguir.
I. O resultado da impressão na linha 24 é: 7 - 7.
II. A função funcao1(), no pior caso, é uma estratégia mais rápida do que a função funcao2().
III. A função funcao2() implementa uma estratégia iterativa na concepção do algoritmo.
É correto o que se afirma em:
a. I, apenas.
b. III, apenas.
c. I e II, apenas.
d. II e III, apenas.
e. I, II e III.
Justifique sua resposta.
*/

/*
Olha só, analisei esse código e as afirmações, e cheguei à conclusão de que só a primeira afirmação tá certa. Vou te explicar o porquê.
Primeiro, a gente tem duas funções: a funcao1 e a funcao2. A funcao1 faz uma busca linear no vetor, enquanto a funcao2 faz uma busca binária. Quando a gente roda o programa, ele imprime 7 - 7, que é exatamente o que a primeira afirmação diz. Isso acontece porque o número 15 tá na posição 7 do vetor (lembrando que a gente começa a contar do 0 em C).
Agora, a segunda afirmação tá errada. Ela diz que a funcao1 é mais rápida no pior caso, mas não é verdade. A funcao1 faz uma busca linear, que no pior caso tem que passar por todos os elementos do vetor. Já a funcao2 faz uma busca binária, que é muito mais eficiente pra vetores grandes. A busca binária sempre divide o problema pela metade, então ela é mais rápida no pior caso.
A terceira afirmação também tá errada. Ela diz que a funcao2 é iterativa, mas na verdade ela é recursiva. Dá pra ver isso porque a função chama ela mesma dentro dela. Uma função iterativa usaria um loop, tipo um for ou um while.
Então, no final das contas, só a primeira afirmação tá certa. Por isso, a resposta correta é a letra a: "I, apenas". As outras opções incluem afirmações que não são verdadeiras pra esse código.
*/