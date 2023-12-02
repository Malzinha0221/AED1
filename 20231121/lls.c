#include <stdio.h>
#include <stdbool.h>
#include "lls.h"

// Inicializa a lista
void inicializarLista(ListaLinearSequencial *lista) {
    lista->quantidade = 0;
}

// Insere um elemento no final da lista
void inserirNoFinal(ListaLinearSequencial *lista, int elemento) {
    if (lista->quantidade < MAX_ELEMENTOS) {
        lista->dados[lista->quantidade] = elemento;
        lista->quantidade++;
        printf("Elemento %d inserido no final da lista.\n", elemento);
    } else {
        printf("Lista cheia. Impossível inserir mais elementos.\n");
    }
}

// Insere um elemento de forma ordenada na lista
void inserirOrdenado(ListaLinearSequencial *lista, int elemento) {
    if (lista->quantidade < MAX_ELEMENTOS) {
        int i = lista->quantidade - 1;
        while (i >= 0 && lista->dados[i] > elemento) {
            lista->dados[i + 1] = lista->dados[i];
            i--;
        }
        lista->dados[i + 1] = elemento;
        lista->quantidade++;
        printf("Elemento %d inserido de forma ordenada na lista.\n", elemento);
    } else {
        printf("Lista cheia. Impossível inserir mais elementos.\n");
    }
}

// Elimina um elemento pela chave
void eliminarElemento(ListaLinearSequencial *lista, int chave) {
    if (lista->quantidade > 0) {
        int i = 0;
        while (i < lista->quantidade && lista->dados[i] != chave) {
            i++;
        }

        if (i < lista->quantidade) {
            for (int j = i; j < lista->quantidade - 1; j++) {
                lista->dados[j] = lista->dados[j + 1];
            }
            lista->quantidade--;
            printf("Elemento %d eliminado da lista.\n", chave);
        } else {
            printf("Chave %d não encontrada na lista.\n", chave);
        }
    } else {
        printf("Lista vazia. Impossível eliminar elementos.\n");
    }
}

// Imprime os elementos da lista
void imprimirLista(ListaLinearSequencial *lista) {
    if (lista->quantidade > 0) {
        printf("Elementos da lista: ");
        for (int i = 0; i < lista->quantidade; i++) {
            printf("%d ", lista->dados[i]);
        }
        printf("\n");
    } else {
        printf("Lista vazia.\n");
    }
}
