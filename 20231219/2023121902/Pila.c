#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarHangar(struct Hangar *hangar) {
    hangar->topo = -1;
}

int hangarVazio(struct Hangar *hangar) {
    return hangar->topo == -1;
}

int hangarCheio(struct Hangar *hangar) {
    return hangar->topo == MAX_AVIOES - 1;
}

void adicionarAviao(struct Hangar *hangar, struct Aviao aviao) {
    if (hangarCheio(hangar)) {
        printf("Hangar cheio. Não é possível adicionar mais aviões.\n");
    } else {
        hangar->topo++;
        hangar->avioes[hangar->topo] = aviao;
        printf("Avião %s adicionado ao hangar.\n", aviao.nome);
    }
}

void tirarAviao(struct Hangar *hangar) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio. Nenhum avião para tirar.\n");
    } else {
        struct Aviao aviaoRemovido = hangar->avioes[hangar->topo];
        hangar->topo--;
        printf("Avião %s removido do hangar.\n", aviaoRemovido.nome);
    }
}

void listarAvioesNoHangar(struct Hangar *hangar) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio.\n");
    } else {
        printf("Aviões no hangar:\n");
        for (int i = 0; i <= hangar->topo; i++) {
            printf("- Avião %s (ID: %d)\n", hangar->avioes[i].nome, hangar->avioes[i].id);
        }
    }
}

void listarPrimeiroAviao(struct Hangar *hangar) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio. Nenhuma informação disponível.\n");
    } else {
        struct Aviao primeiroAviao = hangar->avioes[hangar->topo];
        printf("Características do primeiro avião no hangar:\n");
        printf("- Nome: %s\n", primeiroAviao.nome);
        printf("- ID: %d\n", primeiroAviao.id);
        // Adicione outras características conforme necessário
    }
}

void tirarAviaoPorPosicao(struct Hangar *hangar, int posicao) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio. Nenhum avião para tirar.\n");
    } else if (posicao < 1 || posicao > hangar->topo + 1) {
        printf("Posição inválida. Tente novamente.\n");
    } else {
        // Remover aviões nas posições após a posição desejada
        for (int i = posicao; i <= hangar->topo; i++) {
            hangar->avioes[i - 1] = hangar->avioes[i];
        }

        // Atualizar o topo da pilha
        hangar->topo--;

        printf("Avião na posição %d removido do hangar.\n", posicao);
    }
}

void LiberarMemoria(struct Hangar *hangar) {
    inicializarHangar(hangar);
}
