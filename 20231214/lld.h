
#ifndef LLD_H
#define LLD_H

typedef struct No {
    int dado;
    struct No* anterior;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} ListaDupla;

void inicializarListaDupla(ListaDupla* lista);
void inserirInicioListaDupla(ListaDupla* lista, int dado);
void imprimirLista(ListaDupla* lista);
void criarListaOrdenada(ListaDupla* listaDesordenada, ListaDupla* listaOrdenada);
void ordenarLista(ListaDupla* lista);
void liberarLista(ListaDupla* lista);

#endif
