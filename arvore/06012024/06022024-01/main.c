#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

// Função principal
int main() {
    No *raiz = NULL;

    // Inserir os elementos na árvore
    raiz = inserir(raiz, 24);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 32);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 29);
    raiz = inserir(raiz, 35);

    printf("Árvore em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    printf("Número de elementos na árvore: %d\n", contarElementos(raiz));

    printf("Chaves dos elementos em pré-ordem: ");
    imprimirPreOrdem(raiz);
    printf("\n");

    printf("Chaves dos elementos em pós-ordem: ");
    imprimirPosOrdem(raiz);
    printf("\n");

    return 0;
}
