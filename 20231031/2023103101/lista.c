#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Função para criar uma nova LISTA com um tamanho definido
LISTA *criarLista(int tamanho) {
    LISTA *novaLista = (LISTA *)malloc(sizeof(LISTA));
    if (novaLista) {
        novaLista->tamanho = tamanho;
        novaLista->vetor = (int *)malloc(tamanho * sizeof(int));
    }
    return novaLista;
}

// Função para liberar o espaço na memória de uma LISTA
void liberarLista(LISTA *lista) {
    free(lista->vetor);
    free(lista);
}

// Função para inserir elementos em uma LISTA (preenchimento manual)
void preencherLista(LISTA *lista) {
    printf("Insira os elementos na lista:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &lista->vetor[i]);
    }
}

// Função para preencher uma LISTA com números aleatórios
void preencherAleatoriamente(LISTA *lista) {
    srand(time(NULL));
    for (int i = 0; i < lista->tamanho; i++) {
        lista->vetor[i] = rand() % 100;  // Números aleatórios entre 0 e 99
    }
}

// Função para imprimir os elementos de uma LISTA (algoritmo iterativo)
void imprimirLista(LISTA *lista) {
    printf("Elementos da lista:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->vetor[i]);
    }
    printf("\n");
}

// Função para buscar um elemento em uma LISTA de forma sequencial
int buscaSequencial(LISTA *lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->vetor[i] == elemento) {
            return i;  // Elemento encontrado
        }
    }
    return -1;  // Elemento não encontrado
}

// Função para buscar um elemento na lista de forma sequencial aproveitando que os elementos estão ordenados
int buscaSequencialOrdenada(LISTA *lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->vetor[i] == elemento) {
            return i;  // Elemento encontrado
        }
        if (lista->vetor[i] > elemento) {
            return -1;  // Elemento não encontrado (a lista está ordenada)
        }
    }
    return -1;  // Elemento não encontrado
}

// Função para busca binária de um elemento em uma LISTA (algoritmo iterativo)
int buscaBinaria(LISTA *lista, int elemento) {
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista->vetor[meio] == elemento) {
            return meio;  // Elemento encontrado
        }
        if (lista->vetor[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;  // Elemento não encontrado
}

// Função para buscar o maior elemento em uma LISTA (algoritmo iterativo)
int encontrarMaior(LISTA *lista) {
    int maior = lista->vetor[0];
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->vetor[i] > maior) {
            maior = lista->vetor[i];
        }
    }
    return maior;
}

// Função para buscar o menor elemento em uma LISTA (algoritmo iterativo)
int encontrarMenor(LISTA *lista) {
    int menor = lista->vetor[0];
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->vetor[i] < menor) {
            menor = lista->vetor[i];
        }
    }
    return menor;
}

// Função para retornar a soma de todos os elementos de uma LISTA (algoritmo iterativo)
int calcularSoma(LISTA *lista) {
    int soma = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        soma += lista->vetor[i];
    }
    return soma;
}

// Função para retornar o produto de todos os elementos de uma LISTA (algoritmo iterativo)
int calcularProduto(LISTA *lista) {
    int produto = 1;
    for (int i = 0; i < lista->tamanho; i++) {
        produto *= lista->vetor[i];
    }
    return produto;
}

