#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"
int main() {
    int tamanhoLista;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanhoLista);

    LISTA *lista1 = criarLista(tamanhoLista);
    if (lista1 == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    }

    preencherAleatoriamente(lista1);
    printf("Lista 1:\n");
    imprimirLista(lista1);

    int elementoBusca;
    printf("Digite um elemento para buscar na lista 1: ");
    scanf("%d", &elementoBusca);
    int resultadoBuscaSequencial = buscaSequencial(lista1, elementoBusca);
    if (resultadoBuscaSequencial != -1) {
        printf("Elemento %d encontrado na posição %d (Busca Sequencial).\n", elementoBusca, resultadoBuscaSequencial);
    } else {
        printf("Elemento %d não encontrado na lista (Busca Sequencial).\n", elementoBusca);
    }

    LISTA *lista2 = criarLista(30);
    if (lista2 == NULL) {
        printf("Falha ao alocar memória para lista 2.\n");
        return 1;
    }

    for (int i = 0; i < lista2->tamanho; i++) {
        lista2->vetor[i] = i * 2;  // Preenche lista2 com números pares
    }
    printf("Lista 2:\n");
    imprimirLista(lista2);

    int elementoBusca2;
    printf("Digite um elemento para buscar na lista 2: ");
    scanf("%d", &elementoBusca2);
    int resultadoBuscaSequencialOrdenada = buscaSequencialOrdenada(lista2, elementoBusca2);
    if (resultadoBuscaSequencialOrdenada != -1) {
        printf("Elemento %d encontrado na posição %d (Busca Sequencial Ordenada).\n", elementoBusca2, resultadoBuscaSequencialOrdenada);
    } else {
        printf("Elemento %d não encontrado na lista (Busca Sequencial Ordenada).\n", elementoBusca2);
    }

    int resultadoBuscaBinaria = buscaBinaria(lista2, elementoBusca2);
    if (resultadoBuscaBinaria != -1) {
        printf("Elemento %d encontrado na posição %d (Busca Binária).\n", elementoBusca2, resultadoBuscaBinaria);
    } else {
        printf("Elemento %d não encontrado na lista (Busca Binária).\n", elementoBusca2);
    }

    int maiorElemento = encontrarMaior(lista1);
    printf("O maior elemento da lista 1 é: %d\n", maiorElemento);

    int menorElemento = encontrarMenor(lista1);
    printf("O menor elemento da lista 1 é: %d\n", menorElemento);

    int somaElementos = calcularSoma(lista1);
    printf("A soma de todos os elementos da lista 1 é: %d\n", somaElementos);

    int produtoElementos = calcularProduto(lista1);
    printf("O produto de todos os elementos da lista 1 é: %d\n", produtoElementos);

    liberarLista(lista1);
    liberarLista(lista2);

    return 0;
}
