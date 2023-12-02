#include <stdio.h>
#include <stdbool.h>
#include "lls.h"
int main() {
    ListaLinearSequencial lista;
    inicializarLista(&lista);

    int opcao, elemento, chave;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir elemento no final da lista\n");
        printf("2. Inserir elemento de forma ordenada\n");
        printf("3. Eliminar elemento pela chave\n");
        printf("4. Imprimir lista\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido no final: ");
                scanf("%d", &elemento);
                inserirNoFinal(&lista, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser inserido de forma ordenada: ");
                scanf("%d", &elemento);
                inserirOrdenado(&lista, elemento);
                break;
            case 3:
                printf("Digite a chave do elemento a ser eliminado: ");
                scanf("%d", &chave);
                eliminarElemento(&lista, chave);
                break;
            case 4:
                imprimirLista(&lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
