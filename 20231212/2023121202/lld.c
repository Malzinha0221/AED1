// lld.c
#include "lld.h"
#include <stdio.h>
#include <stdlib.h>

No* criarNo(int data) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }
    novoNo->data = data;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirFinal(No** cabeca, int data) {
    No* novoNo = criarNo(data);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void imprimirLista(No* cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->data);
        cabeca = cabeca->proximo;
    }
    printf("\n");
}

void liberarLista(No* cabeca) {
    while (cabeca != NULL) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
    }
}

No* percorrerListaA(No* L) {
    if (L == NULL || L->proximo == NULL) {
        printf("Lista L precisa ter pelo menos dois elementos para construir L1.\n");
        return NULL;
    }
    No* L1 = NULL;
    No* atual = L;

    while (atual != NULL) {
        inserirFinal(&L1, atual->data);
        atual = atual->proximo;
    }

    inserirFinal(&L1, L->data);
    return L1;
}

No* percorrerListaB(No* L) {
    if (L == NULL || L->proximo == NULL) {
        printf("Lista L precisa ter pelo menos dois elementos para construir L1.\n");
        return NULL;
    }
    No* L1 = NULL;
    No* atual = L;

    while (atual != NULL) {
        inserirFinal(&L1, atual->data);
        atual = atual->proximo;
    }

    return L1;
}

No* copiarLista(No* l1) {
    No* l2 = NULL;
    No* atualL1 = l1;

    while (atualL1 != NULL) {
        inserirFinal(&l2, atualL1->data);
        atualL1 = atualL1->proximo;
    }

    return l2;
}

No* concatenarListas(No* l1, No* l2) {
    No* concatenarListas = copiarLista(l1);

    No* atuall2 = l2;
    while (atuall2 != NULL) {
        inserirFinal(&concatenarListas, atuall2->data);
        atuall2 = atuall2->proximo;
    }

    return concatenarListas;
}

No* intercalarListas(No* l1, No* l2) {
    No* intercalarListas = NULL;

    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            inserirFinal(&intercalarListas, l1->data);
            l1 = l1->proximo;
        }
        if (l2 != NULL) {
            inserirFinal(&intercalarListas, l2->data);
            l2 = l2->proximo;
        }
    }

    return intercalarListas;
}
