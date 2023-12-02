
#define MAX_ELEMENTOS 100
#ifndef lls_H
#define lls_H

// Estrutura da lista
typedef struct {
    int dados[MAX_ELEMENTOS];
    int quantidade;
} ListaLinearSequencial;

void inicializarLista(ListaLinearSequencial *lista);
void inserirNoFinal(ListaLinearSequencial *lista, int elemento);
void inserirOrdenado(ListaLinearSequencial *lista, int elemento);
void eliminarElemento(ListaLinearSequencial *lista, int chave);
void imprimirLista(ListaLinearSequencial *lista);

#endif