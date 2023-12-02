#include <stdio.h>
#include <stdlib.h>
#include "lle.h"

int main() {
    ListaLigadaEstatica lista;
    inicializarLista(&lista);

    int quantidade, elemento;

    // Pede ao usuário para inserir a quantidade de elementos
    printf("Digite a quantidade de elementos a serem inseridos: ");
    scanf("%d", &quantidade);

    // Pede ao usuário para inserir os elementos
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &elemento);
        inserirElemento(&lista, elemento);
    }

    // Imprime a lista original
    printf("Lista Original: ");
    imprimirLista(&lista);

    // Constrói e imprime a lista L1a
    printf("L1a: ");
    construirL1a(&lista);

    // Constrói e imprime a lista L1b
    printf("L1b: ");
    construirL1b(&lista);

    return 0;
}
