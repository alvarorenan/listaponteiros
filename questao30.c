/*
Um programador precisa desenvolver uma aplicação em linguagem C para manipular matrizes
capazes de armazenar representações de modelos tridimensionais.
Entende-se que o tamanho da matriz é definido pelo usuário e esta deve ser alocada
dinamicamente usando malloc() em tempo de execução. O processo de criar um modelo na
matriz consiste em atribuir aos seus elementos os valores inteiros “1” ou “0” para simbolizar
que há ou não parte do modelo naquela posição. Uma analogia para o modelo seria que a
criação funciona como no jogo "Minecraft", onde "0" representaria a ausência de objeto e "1"
representaria a presença de objetos.
Nesta aplicação, as matrizes devem ser definidas como tipos de dados int. Isto posto, pede-se
que o programador prepare os algoritmos de alocação dinâmica (usando malloc()/free()) para
guardar os dados da matriz tridimensional e crie um programa de testes para verificar se a sua
implementação foi realizada corretamente de modo a garantir as seguintes condições:
a. O usuário do programa de testes deverá poder fornecer o tamanho da matriz tridimensional
que deseja manipular, inserindo as dimensões da altura, largura e profundidade desta.
b. O usuário do programa de testes poderá solicitar a impressão de um dos planos da matriz
tridimensional.
c. O usuário do programa de testes poderá modificar o estado de um dos elementos da matriz.
Insira no seu código comentários para indicar como as posições da matriz poderão ser
acessadas
*/

#include <stdio.h>
#include <stdlib.h>

// Função para alocar a matriz 3D dinamicamente
int*** alocarMatriz3D(int altura, int largura, int profundidade) {
    int*** matriz = (int***)malloc(altura * sizeof(int**));
    for (int i = 0; i < altura; i++) {
        matriz[i] = (int**)malloc(largura * sizeof(int*));
        for (int j = 0; j < largura; j++) {
            matriz[i][j] = (int*)calloc(profundidade, sizeof(int));
        }
    }
    return matriz;
}

// Função para liberar a memória alocada para a matriz 3D
void liberarMatriz3D(int*** matriz, int altura, int largura) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);
}

// Função para imprimir um plano da matriz
void imprimirPlano(int*** matriz, int altura, int largura, int plano, char direcao) {
    printf("Plano %d na direção %c:\n", plano, direcao);
    switch(direcao) {
        case 'x':
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
                    printf("%d ", matriz[i][j][plano]);
                }
                printf("\n");
            }
            break;
        case 'y':
            for (int i = 0; i < altura; i++) {
                for (int k = 0; k < largura; k++) {
                    printf("%d ", matriz[i][plano][k]);
                }
                printf("\n");
            }
            break;
        case 'z':
            for (int j = 0; j < largura; j++) {
                for (int k = 0; k < altura; k++) {
                    printf("%d ", matriz[plano][j][k]);
                }
                printf("\n");
            }
            break;
    }
}

// Função para modificar um elemento da matriz
void modificarElemento(int*** matriz, int x, int y, int z, int valor) {
    matriz[x][y][z] = valor;
    printf("Elemento na posição (%d, %d, %d) modificado para %d\n", x, y, z, valor);
}

int main() {
    int altura, largura, profundidade;
    
    // Solicita as dimensões da matriz ao usuário
    printf("Digite as dimensões da matriz (altura largura profundidade): ");
    scanf("%d %d %d", &altura, &largura, &profundidade);
    
    // Aloca a matriz 3D
    int*** matriz = alocarMatriz3D(altura, largura, profundidade);
    
    int opcao;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Imprimir um plano da matriz\n");
        printf("2. Modificar um elemento da matriz\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                int plano;
                char direcao;
                printf("Digite a direção (x, y ou z) e o número do plano: ");
                scanf(" %c %d", &direcao, &plano);
                imprimirPlano(matriz, altura, largura, plano, direcao);
                break;
            }
            case 2: {
                int x, y, z, valor;
                printf("Digite as coordenadas (x y z) e o novo valor: ");
                scanf("%d %d %d %d", &x, &y, &z, &valor);
                modificarElemento(matriz, x, y, z, valor);
                break;
            }
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    // Libera a memória alocada
    liberarMatriz3D(matriz, altura, largura);
    
    return 0;
}