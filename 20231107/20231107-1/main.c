#include <stdio.h>
#include <stdlib.h>
#include "NovaLista.h"

int main() {
    LISTA lista = criarLista(10);

    // Preencha a lista com elementos (você pode usar inserirElemento ou inserirElementoOrdenado)
    for (int i = 0; i < 10; i++) {
        inserirElemento(&lista, rand() % 100);  // Inserindo números aleatórios de 0 a 99
    }

    printf("Elementos da lista (iterativo): ");
    imprimirListaIterativo(lista);
    printf("\n");

    int elementoBusca = 42;
    int posicao = buscaBinariaRecursiva(lista, elementoBusca, 0, lista.tamanho - 1);
    if (posicao != -1) {
        printf("Elemento %d encontrado na posição %d.\n", elementoBusca, posicao);
    } else {
        printf("Elemento %d não encontrado na lista.\n", elementoBusca);
    }

    printf("Elementos da lista (recursivo): ");
    imprimirListaRecursivo(lista, 0);
    printf("\n");

    int maior = encontrarMaiorRecursivo(lista, 0);
    int menor = encontrarMenorRecursivo(lista, 0);
    int soma = calcularSomaRecursivo(lista, 0);
    int produto = calcularProdutoRecursivo(lista, 0);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Soma dos elementos: %d\n", soma);
    printf("Produto dos elementos: %d\n", produto);

    liberarLista(&lista);  // Liberar memória alocada
    return 0;
}
