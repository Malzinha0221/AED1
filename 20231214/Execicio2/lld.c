#include <stdio.h>
#include <stdlib.h>
#include "lld.h"

// Função para inicializar uma lista de polinômio
void inicializarListaPolinomio(ListaPolinomio* lista) {
    lista->inicio = NULL;
}

// Função para inserir um termo na lista de polinômio de forma ordenada
void inserirTermoOrdenado(ListaPolinomio* lista, int coeficiente, int expoente) {
    Termo* novoTermo = (Termo*)malloc(sizeof(Termo));
    if (novoTermo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }
    novoTermo->coeficiente = coeficiente;
    novoTermo->expoente = expoente;
    novoTermo->proximo = NULL;

    if (lista->inicio == NULL || expoente > lista->inicio->expoente) {
        // Inserir no início se a lista está vazia ou o expoente é maior que o primeiro termo
        novoTermo->proximo = lista->inicio;
        lista->inicio = novoTermo;
    } else {
        // Procurar o local de inserção e realizar a inserção ordenada
        Termo* atual = lista->inicio;
        while (atual->proximo != NULL && expoente < atual->proximo->expoente) {
            atual = atual->proximo;
        }
        novoTermo->proximo = atual->proximo;
        atual->proximo = novoTermo;
    }
}

// Função para somar dois polinômios
ListaPolinomio somaPolinomios(ListaPolinomio* P1, ListaPolinomio* P2) {
    ListaPolinomio resultado;
    inicializarListaPolinomio(&resultado);

    Termo* termoP1 = P1->inicio;
    Termo* termoP2 = P2->inicio;

    while (termoP1 != NULL || termoP2 != NULL) {
        int coeficienteSoma = 0;
        int expoenteAtual = 0;

        if (termoP1 != NULL && termoP2 != NULL && termoP1->expoente == termoP2->expoente) {
            coeficienteSoma = termoP1->coeficiente + termoP2->coeficiente;
            expoenteAtual = termoP1->expoente;
            termoP1 = termoP1->proximo;
            termoP2 = termoP2->proximo;
        } else if (termoP1 != NULL && (termoP2 == NULL || termoP1->expoente > termoP2->expoente)) {
            coeficienteSoma = termoP1->coeficiente;
            expoenteAtual = termoP1->expoente;
            termoP1 = termoP1->proximo;
        } else if (termoP2 != NULL && (termoP1 == NULL || termoP1->expoente < termoP2->expoente)) {
            coeficienteSoma = termoP2->coeficiente;
            expoenteAtual = termoP2->expoente;
            termoP2 = termoP2->proximo;
        }

        if (coeficienteSoma != 0) {
            inserirTermoOrdenado(&resultado, coeficienteSoma, expoenteAtual);
        }
    }

    return resultado;
}

// Função para imprimir um polinômio
void imprimirPolinomio(ListaPolinomio* lista) {
    Termo* atual = lista->inicio;
    while (atual != NULL) {
        printf("%dx^%d ", atual->coeficiente, atual->expoente);
        if (atual->proximo != NULL) {
            printf("+ ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}
