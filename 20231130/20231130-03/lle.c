#include <stdio.h>
#include <stdlib.h>
#include "lle.h"

// Inicializa a lista ligada estática
void inicializarLista(ListaLigadaEstatica *lista) {
    lista->inicio = -1;
    lista->livre = 0;
    for (int i = 0; i < MAX_ELEMENTOS - 1; i++) {
        lista->nos[i].proximo = i + 1;
    }
    lista->nos[MAX_ELEMENTOS - 1].proximo = -1; // Último nó aponta para -1
}

// Insere um elemento no final da lista
void inserirElemento(ListaLigadaEstatica *lista, int elemento) {
    if (lista->livre == -1) {
        printf("Lista cheia. Impossível inserir mais elementos.\n");
        return;
    }

    int novoIndice = lista->livre;
    lista->livre = lista->nos[lista->livre].proximo;

    lista->nos[novoIndice].dado = elemento;
    lista->nos[novoIndice].proximo = -1;

    if (lista->inicio == -1) {
        lista->inicio = novoIndice;
    } else {
        int atual = lista->inicio;
        while (lista->nos[atual].proximo != -1) {
            atual = lista->nos[atual].proximo;
        }
        lista->nos[atual].proximo = novoIndice;
    }
}

// Imprime os elementos da lista
void imprimirLista(ListaLigadaEstatica *lista) {
    int atual = lista->inicio;
    while (atual != -1) {
        printf("%d ", lista->nos[atual].dado);
        atual = lista->nos[atual].proximo;
    }
    printf("\n");
}

// Constrói uma nova lista L1 com os elementos l2, l3, ..., ln, l1
void construirL1a(ListaLigadaEstatica *lista) {
    if (lista->inicio == -1) {
        printf("Lista vazia. Impossível construir L1a.\n");
        return;
    }

    int primeiroElemento = lista->inicio;
    int segundoElemento = lista->nos[primeiroElemento].proximo;

    if (segundoElemento == -1) {
        printf("Lista contém apenas um elemento. Impossível construir L1a.\n");
        return;
    }

    int atual = segundoElemento;
    while (lista->nos[atual].proximo != -1) {
        printf("%d ", lista->nos[atual].dado);
        atual = lista->nos[atual].proximo;
    }

    printf("%d %d\n", lista->nos[atual].dado, primeiroElemento);
}

// Constrói uma nova lista L1 com os elementos ln, ln‐1,…, l1
void construirL1b(ListaLigadaEstatica *lista) {
    if (lista->inicio == -1) {
        printf("Lista vazia. Impossível construir L1b.\n");
        return;
    }

    int atual = lista->inicio;
    int *elementos = malloc(MAX_ELEMENTOS * sizeof(int));
    int tamanho = 0;

    // Armazena os elementos da lista em um array
    while (atual != -1) {
        elementos[tamanho++] = lista->nos[atual].dado;
        atual = lista->nos[atual].proximo;
    }

    // Imprime os elementos na ordem inversa
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d ", elementos[i]);
    }

    printf("\n");

    free(elementos);
}
