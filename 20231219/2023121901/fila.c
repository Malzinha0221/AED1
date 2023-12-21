#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicioDecolagem (struct Decolagem *pista){
    pista->inicio = -1;
    pista->fim = -1;
}
int PistaVazia(struct Decolagem *pista){
    return pista->inicio == -1;
}
int PistaCheia(struct Decolagem *pista){
    return (pista->fim +1) % MAX_AVIAO == pista->inicio;
}
void EnfilerarAviao(struct Decolagem *pista, struct Aviao aviao){
    if (PistaCheia(pista)) {
        printf("Fila Cheia. Sem chance de adicionar mais avião");
    } else {
        if (PistaVazia(pista)) {
            pista->inicio = 0;
        }
        pista->fim = (pista->fim + 1) % MAX_AVIAO;
        pista->aviao[pista->fim] = aviao;
        printf("Avião %s adicionado à fila de decolagem.\n", aviao.nome);
    }
}
void AutorizarDecolagem(struct Decolagem *pista){
    if(PistaVazia(pista)){
        printf("A fila de decolagem está vazia. Nenhum avião para decolar.\n");
    } else{
        struct Aviao Decolando = pista->aviao[pista->inicio];
        printf("Autozizando decolagem do avião %s (ID: %d).\n", Decolando.nome, Decolando.id);
        pista->inicio=(pista->inicio+1)%MAX_AVIAO;
        if(pista->inicio==(pista->fim+1)%MAX_AVIAO){
            inicioDecolagem(pista);
        }
    }
}
void ListaAviao(struct Decolagem *pista){
    if(PistaVazia(pista)){
        printf("A fila de decolagem está vazia.\n");
    } else{
        printf("Aviões na fila de decolagem:\n");
        int i = pista->inicio;
        do{
            printf("- Avião %s (ID: %d)\n", pista->aviao[i].nome, pista->aviao[i].id);
            i = (i+1)%MAX_AVIAO;
        } while (i!=(pista->fim+1)%MAX_AVIAO);
    }
}
void ListaPrimeiroAviao(struct Decolagem *pista) {
    if (PistaVazia(pista)) {
        printf("A fila de decolagem está vazia. Nenhuma informação disponível.\n");
    } else {
        struct Aviao PrimeiroAviao = pista->aviao[pista->inicio];
        printf("Característica do primeiro avião na fila de decolagem:\n");
        printf("- Nome: %s\n", PrimeiroAviao.nome);
        printf("-ID: %d\n", PrimeiroAviao.id);
    }
}

void LiberarMemoria(struct Decolagem *pista){
    int i = pista->inicio;
    while (i!=(pista->fim+1)%MAX_AVIAO){
        free(pista->aviao[i].nome);
        i=(i+1)%MAX_AVIAO;
    }
    inicioDecolagem(pista);
}