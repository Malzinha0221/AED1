#include <stdio.h>
#include <stdlib.h>
#include "lld.h"
int main() {
    ListaPolinomio polinomio1, polinomio2;
    inicializarListaPolinomio(&polinomio1);
    inicializarListaPolinomio(&polinomio2);

    // Inserir alguns termos nos polinômios
    inserirTermoOrdenado(&polinomio1, 3, 5);
    inserirTermoOrdenado(&polinomio1, 2, 1);
    inserirTermoOrdenado(&polinomio1, -1, 0);

    inserirTermoOrdenado(&polinomio2, 6, 1);
    inserirTermoOrdenado(&polinomio2, 12, 0);

    // Imprimir os polinômios
    printf("Polinômio 1: ");
    imprimirPolinomio(&polinomio1);

    printf("Polinômio 2: ");
    imprimirPolinomio(&polinomio2);

    // Somar os polinômios
    ListaPolinomio resultado = somaPolinomios(&polinomio1, &polinomio2);

    // Imprimir o resultado
    printf("Resultado da soma: ");
    imprimirPolinomio(&resultado);

    return 0;
}

