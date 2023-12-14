// main.c
#include "lld.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    No* lista1 = NULL;
    No* lista2 = NULL;

    for (int i = 1; i <= 5; i++) {
        inserirFinal(&lista1, i);
    }

    lista2 = copiarLista(lista1);

    printf("Lista1: ");
    imprimirLista(lista1);

    printf("Lista2 (cópia de Lista 1): ");
    imprimirLista(lista2);

    No* listaConcatenada = concatenarListas(lista1, lista2);
    printf("Lista Concatenada: ");
    imprimirLista(listaConcatenada);

    No* listaIntercalada = intercalarListas(lista1, lista2);
    printf("Lista Intercalada: ");
    imprimirLista(listaIntercalada);

    No* ListaA = percorrerListaA(lista1);
    printf("Lista A: ");
    imprimirLista(ListaA);

    No* ListaB = percorrerListaB(lista2);
    printf("Lista B: ");
    imprimirLista(ListaB);

    liberarLista(lista1);
    liberarLista(ListaA);
    liberarLista(ListaB);

    return 0;
}
