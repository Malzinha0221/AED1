#include <stdio.h>
#include <stdlib.h>
#include "LLE.H"

int main() {
    ListaLigadaEstatica lista1, lista2, resultado;

    // Inicializa as listas
    inicializarLista(&lista1);
    inicializarLista(&lista2);
    inicializarLista(&resultado);

    // Insere alguns elementos nas listas
    inserirElemento(&lista1, 1);
    inserirElemento(&lista1, 3);
    inserirElemento(&lista1, 5);

    inserirElemento(&lista2, 2);
    inserirElemento(&lista2, 4);
    inserirElemento(&lista2, 6);

    // Imprime as listas originais
    printf("Lista 1: ");
    imprimirLista(&lista1);

    printf("Lista 2: ");
    imprimirLista(&lista2);

    // Operação a) Copiar uma lista l1 para uma lista l2
    copiarLista(&lista1, &resultado);
    printf("Copia de Lista 1 para Lista 2: ");
    imprimirLista(&resultado);

    // Operação b) Concatenar uma lista l1 com uma lista l2
    concatenarListas(&lista1, &lista2, &resultado);
    printf("Concatenacao de Lista 1 e Lista 2: ");
    imprimirLista(&resultado);

    // Operação c) Intercalar l1 e l2
    intercalarListas(&lista1, &lista2, &resultado);
    printf("Intercalacao de Lista 1 e Lista 2: ");
    imprimirLista(&resultado);

    return 0;
}
