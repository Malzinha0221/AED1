#define MAX_ELEMENTOS 100
#ifndef LLE_H
#define LLE_H

typedef struct {
    int dado;
    int proximo;
} NoLista;

typedef struct {
    NoLista nos[MAX_ELEMENTOS];
    int inicio;
    int livre;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica *lista);
void inserirElemento(ListaLigadaEstatica *lista, int elemento);
void imprimirLista(ListaLigadaEstatica *lista);
void copiarLista(ListaLigadaEstatica *origem, ListaLigadaEstatica *destino);
void concatenarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado);
void intercalarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado);


#endif