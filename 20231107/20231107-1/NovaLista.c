#include <stdio.h>
#include <stdlib.h>
#include "NovaLista.h"


LISTA criarLista(int tamanho) {
    LISTA novaLista;
    novaLista.tamanho = 0;  // Inicialmente, a lista está vazia
    novaLista.vetor = (int *)malloc(tamanho * sizeof(int));
    return novaLista;
}

void liberarLista(LISTA *lista) {
    free(lista->vetor);
    lista->tamanho = 0;
}

void inserirElemento(LISTA *lista, int elemento) {
    if (lista->tamanho >= 10) {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
        return;
    }
    lista->vetor[lista->tamanho] = elemento;
    lista->tamanho++;
}

void inserirElementoOrdenado(LISTA *lista, int elemento) {
    if (lista->tamanho >= 10) {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
        return;
    }

    int posicao = 0;
    while (posicao < lista->tamanho && lista->vetor[posicao] < elemento) {
        posicao++;
    }

    for (int i = lista->tamanho; i > posicao; i--) {
        lista->vetor[i] = lista->vetor[i - 1];
    }

    lista->vetor[posicao] = elemento;
    lista->tamanho++;
}

void imprimirListaIterativo(LISTA lista) {
    for (int i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.vetor[i]);
    }
}

int buscaBinariaRecursiva(LISTA lista, int elemento, int esquerda, int direita) {
    if (esquerda > direita) {
        return -1;  // Elemento não encontrado
    }

    int meio = (esquerda + direita) / 2;

    if (lista.vetor[meio] == elemento) {
        return meio;  // Elemento encontrado
    } else if (lista.vetor[meio] < elemento) {
        return buscaBinariaRecursiva(lista, elemento, meio + 1, direita);
    } else {
        return buscaBinariaRecursiva(lista, elemento, esquerda, meio - 1);
    }
}

void imprimirListaRecursivo(LISTA lista, int indice) {
    if (indice < lista.tamanho) {
        printf("%d ", lista.vetor[indice]);
        imprimirListaRecursivo(lista, indice + 1);
    }
}

int encontrarMaiorRecursivo(LISTA lista, int indice) {
    if (indice == lista.tamanho - 1) {
        return lista.vetor[indice];
    }

    int maiorRestante = encontrarMaiorRecursivo(lista, indice + 1);
    return (lista.vetor[indice] > maiorRestante) ? lista.vetor[indice] : maiorRestante;
}

int encontrarMenorRecursivo(LISTA lista, int indice) {
    if (indice == lista.tamanho - 1) {
        return lista.vetor[indice];
    }

    int menorRestante = encontrarMenorRecursivo(lista, indice + 1);
    return (lista.vetor[indice] < menorRestante) ? lista.vetor[indice] : menorRestante;
}

int calcularSomaRecursivo(LISTA lista, int indice) {
    if (indice == lista.tamanho - 1) {
        return lista.vetor[indice];
    }

    return lista.vetor[indice] + calcularSomaRecursivo(lista, indice + 1);
}

int calcularProdutoRecursivo(LISTA lista, int indice) {
    if (indice == lista.tamanho - 1) {
        return lista.vetor[indice];
    }

    return lista.vetor[indice] * calcularProdutoRecursivo(lista, indice + 1);
}
