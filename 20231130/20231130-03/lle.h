#define MAX_ELEMENTOS 100

#ifndef LLE_H
#define LLE_H

// Estrutura do nó da lista
typedef struct {
    int dado;
    int proximo;
} NoLista;

// Estrutura da lista ligada estática
typedef struct {
    NoLista nos[MAX_ELEMENTOS];
    int inicio;
    int livre;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica *lista);
void inserirElemento(ListaLigadaEstatica *lista, int elemento);
void imprimirLista(ListaLigadaEstatica *lista);
void construirL1a(ListaLigadaEstatica *lista);
void construirL1b(ListaLigadaEstatica *lista);

#endif