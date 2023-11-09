#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int tamanho;
    int *vetor;
} LISTA;

LISTA *criarLista(int tamanho);
void liberarLista(LISTA *lista);
void preencherLista(LISTA *lista);
void preencherAleatoriamente(LISTA *lista);
void imprimirLista(LISTA *lista);
int buscaSequencial(LISTA *lista, int elemento);
int buscaSequencialOrdenada(LISTA *lista, int elemento);
int buscaBinaria(LISTA *lista, int elemento);
int encontrarMaior(LISTA *lista);
int encontrarMenor(LISTA *lista);
int calcularSoma(LISTA *lista);
int calcularProduto(LISTA *lista);

#endif
