
#include <stdio.h>
#include <stdlib.h>
#include "lld.h"

int main() {
    ListaDupla listaDesordenada;
    inicializarListaDupla(&listaDesordenada);

    // Inserir alguns elementos na lista desordenada
    inserirInicioListaDupla(&listaDesordenada, 5);
    inserirInicioListaDupla(&listaDesordenada, 2);
    inserirInicioListaDupla(&listaDesordenada, 8);
    inserirInicioListaDupla(&listaDesordenada, 3);

    printf("Lista Desordenada: ");
    imprimirLista(&listaDesordenada);

    ListaDupla listaOrdenada;
    inicializarListaDupla(&listaOrdenada);

    // Criar a lista ordenada a partir da lista desordenada
    criarListaOrdenada(&listaDesordenada, &listaOrdenada);

    printf("Lista Ordenada: ");
    imprimirLista(&listaOrdenada);

    return 0;
}
