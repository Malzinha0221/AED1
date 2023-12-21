#define MAX_AVIOES 10
#ifndef PILHA_H
#define PILHA_H

struct Aviao {
    char nome[50];
    int id;
};

struct Hangar {
    struct Aviao avioes[MAX_AVIOES];
    int topo;
};
void inicializarHangar(struct Hangar *hangar);

int hangarVazio(struct Hangar *hangar);

int hangarCheio(struct Hangar *hangar);

void adicionarAviao(struct Hangar *hangar, struct Aviao aviao);

void tirarAviao(struct Hangar *hangar);

void listarAvioesNoHangar(struct Hangar *hangar);

void listarPrimeiroAviao(struct Hangar *hangar);

void tirarAviaoPorPosicao(struct Hangar *hangar, int posicao);

void LiberarMemoria(struct Hangar *hangar);

#endif
