/*
Um programador pretendia armazenar em um struct (acessível através de um ponteiro) o nome
de um usuário e um valor inteiro associado e preparou o seguinte programa. Há algum erro
presente no código? Se sim, qual é ele e como pode ser corrigido?

#include <stdio.h>
struct teste{
    int x = 3;
    char nome[] = "jose";
};
main(){
    struct teste *s;
    printf("%d", s->x);
    printf("%s", s->nome);
}

Inicialização de membros de struct: Em C, não é permitido inicializar membros de uma struct diretamente na sua definição.
Ponteiro não inicializado: O ponteiro s não está apontando para uma instância válida da struct teste.
Função main deve ter um tipo de retorno: A função main deve retornar um valor do tipo int.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct teste {
    int x;
    char nome[20];
};

int main() {
    struct teste *s = (struct teste *)malloc(sizeof(struct teste));
    if (s == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    s->x = 3;
    strcpy(s->nome, "jose");

    printf("%d\n", s->x);
    printf("%s\n", s->nome);

    free(s);
    return 0;
}

