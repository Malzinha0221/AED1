// lld.h
#ifndef LLD_H
#define LLD_H

// Estrutura para representar um nó da lista
typedef struct No {
    int data;
    struct No* proximo;
} No;

No* criarNo(int data);
void inserirFinal(No** cabeca, int data);
void imprimirLista(No* cabeca);
void liberarLista(No* cabeca);
No* percorrerListaA(No* L);
No* percorrerListaB(No* L);
No* copiarLista(No* l1);
No* concatenarListas(No* l1, No* l2);
No* intercalarListas(No* l1, No* l2);

#endif
