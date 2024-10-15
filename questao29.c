/*
Um usuário precisa implementar o controle de uma matriz de leds com 8 x 8 elementos. Para
isso, ele criou um programa em C dotado de uma matriz da forma
unsigned char m[8][8];
para armazenar os estados dos leds. Como existem apenas dois estados possíveis para os leds
(aceso ou apagado), ele assumiu que leds acessos () seriam denotados pelo inteiro "1" nessa
matriz e leds apagados () seriam denotados pelo inteiro "0". Por exemplo, para a seguinte
matriz de leds:
       
       
       
       
       
       
       
       
a matriz m seria codificada da seguinte forma:
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
1 0 1 0 1 0 1 0
1 0 1 0 1 0 1 0
Ocorre que a função que controla os leds exige que a informação que controla a matriz seja
enviada via porta serial usando uma função que recebe um único inteiro não sinalizado de
64 bits, da forma send(unsigned long estado). Nesse inteiro, os bytes mais significativos deverão
guardar os estados das linhas iniciais da matriz de leds, enquanto os bytes menos significativos
devem guardar os estados das linhas finais da matriz. Assim, é necessário que cada estado
previsto na matriz m seja codificado em um bit correspondente na variável enviada pela função.
Para a matriz acima, a variável de 64 bits enviada pela função send() deveria ser codificada da
seguinte forma:
0101010110101010010101011010101001010101101010101010101010101010
12
Crie um programa em linguagem C para realizar essa codificação e explique na forma de
comentários como sua codificação da matriz m na variável de 64 bits foi realizada.
*/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Função para enviar o estado (simulada para este exemplo)
void send(uint64_t estado) {
    printf("Estado enviado: %" PRIu64 "\n", estado);
    // Imprime o estado em formato binário
    for (int i = 63; i >= 0; i--) {
        printf("%" PRIu64, (estado >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Matriz de LEDs 8x8
    unsigned char m[8][8] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1, 0, 1, 0}
    };

    // Variável de 64 bits para armazenar o estado
    uint64_t estado = 0;

    // Codificação da matriz m para a variável de 64 bits
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Desloca o estado 1 bit para a esquerda
            estado <<= 1;
            // Adiciona o bit atual (0 ou 1) ao estado
            estado |= m[i][j];
        }
    }

    // Envia o estado codificado
    send(estado);

    return 0;
}