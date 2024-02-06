#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó
No *criarNo(int chave) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->chave = chave;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

// Função para inserir um elemento na árvore
No *inserir(No *raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }

    return raiz;
}

// Função para imprimir a árvore (em ordem)
void imprimirEmOrdem(No *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirEmOrdem(raiz->direita);
    }
}

// Função para contar quantos elementos existem na árvore
int contarElementos(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarElementos(raiz->esquerda) + contarElementos(raiz->direita);
}

// Função para buscar um elemento na árvore
No *buscar(No *raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    }
    return buscar(raiz->direita, chave);
}

// Função para percorrer e mostrar as chaves dos elementos da árvore em pré-ordem
void imprimirPreOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

// Função para percorrer e mostrar as chaves dos elementos da árvore em pós-ordem
void imprimirPosOrdem(No *raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}
