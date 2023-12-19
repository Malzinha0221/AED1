
#include <stdio.h>
#include <stdlib.h>
#include "lld.h"

void inicializarListaDupla(ListaDupla* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inserirInicioListaDupla(ListaDupla* lista, int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = dado;
    novoNo->anterior = NULL;
    novoNo->proximo = lista->inicio;

    if (lista->inicio == NULL) {
        // Se a lista estava vazia, o novo nó é também o fim da lista
        lista->fim = novoNo;
    } else {
        // Se a lista já tinha elementos, ajustamos o ponteiro anterior do antigo primeiro nó
        lista->inicio->anterior = novoNo;
    }

    // O novo nó agora é o primeiro da lista
    lista->inicio = novoNo;
}

void imprimirLista(ListaDupla* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void criarListaOrdenada(ListaDupla* listaDesordenada, ListaDupla* listaOrdenada) {
    while (listaDesordenada->inicio != NULL) {
        No* noRemovido = listaDesordenada->inicio;
        listaDesordenada->inicio = noRemovido->proximo;

        noRemovido->anterior = NULL;
        noRemovido->proximo = NULL;

        if (listaOrdenada->inicio == NULL) {
            // Se a lista ordenada estava vazia, o nó removido é o primeiro e último
            listaOrdenada->inicio = noRemovido;
            listaOrdenada->fim = noRemovido;
        } else {
            // Se a lista ordenada já tinha elementos, inserimos o nó no início
            noRemovido->proximo = listaOrdenada->inicio;
            listaOrdenada->inicio->anterior = noRemovido;
            listaOrdenada->inicio = noRemovido;
        }
    }
}
