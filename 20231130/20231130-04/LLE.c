#include <stdio.h>
#include <stdlib.h>
#include "LLE.H"

void inicializarLista(ListaLigadaEstatica *lista) {
    lista->inicio = -1;
    lista->livre = 0;
    for (int i = 0; i < MAX_ELEMENTOS - 1; i++) {
        lista->nos[i].proximo = i + 1;
    }
    lista->nos[MAX_ELEMENTOS - 1].proximo = -1;
}

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

void imprimirLista(ListaLigadaEstatica *lista) {
    int atual = lista->inicio;
    while (atual != -1) {
        printf("%d ", lista->nos[atual].dado);
        atual = lista->nos[atual].proximo;
    }
    printf("\n");
}

void copiarLista(ListaLigadaEstatica *origem, ListaLigadaEstatica *destino) {
    inicializarLista(destino);

    int atualOrigem = origem->inicio;
    while (atualOrigem != -1) {
        inserirElemento(destino, origem->nos[atualOrigem].dado);
        atualOrigem = origem->nos[atualOrigem].proximo;
    }
}

void concatenarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado) {
    inicializarLista(resultado);

    // Copia os elementos de l1 para o resultado
    copiarLista(l1, resultado);

    // Encontra o final do resultado
    int atualResultado = resultado->inicio;
    while (resultado->nos[atualResultado].proximo != -1) {
        atualResultado = resultado->nos[atualResultado].proximo;
    }

    // Concatena os elementos de l2 ao resultado
    int atualL2 = l2->inicio;
    while (atualL2 != -1) {
        inserirElemento(resultado, l2->nos[atualL2].dado);
        atualL2 = l2->nos[atualL2].proximo;
    }
}

void intercalarListas(ListaLigadaEstatica *l1, ListaLigadaEstatica *l2, ListaLigadaEstatica *resultado) {
    inicializarLista(resultado);

    int atualL1 = l1->inicio;
    int atualL2 = l2->inicio;

    // Intercala os elementos de l1 e l2 no resultado
    while (atualL1 != -1 && atualL2 != -1) {
        inserirElemento(resultado, l1->nos[atualL1].dado);
        inserirElemento(resultado, l2->nos[atualL2].dado);

        atualL1 = l1->nos[atualL1].proximo;
        atualL2 = l2->nos[atualL2].proximo;
    }

    // Adiciona os elementos restantes de l1, se houver
    while (atualL1 != -1) {
        inserirElemento(resultado, l1->nos[atualL1].dado);
        atualL1 = l1->nos[atualL1].proximo;
    }

    // Adiciona os elementos restantes de l2, se houver
    while (atualL2 != -1) {
        inserirElemento(resultado, l2->nos[atualL2].dado);
        atualL2 = l2->nos[atualL2].proximo;
    }
}
