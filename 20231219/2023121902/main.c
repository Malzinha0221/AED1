#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct Hangar hangar;
    inicializarHangar(&hangar);
    int opcao;
    struct Aviao novoAviao;

    do {
        printf("\nMenu:\n");
        printf("1- Listar número de aviões aguardando no hangar;\n");
        printf("2- Tirar um avião do hangar;\n");
        printf("3- Adicionar um avião no hangar;\n");
        printf("4- Listar todos os aviões que estão no hangar;\n");
        printf("5- Listar as características do primeiro avião do hangar;\n");
        printf("6- Tirar um avião do hangar pela posição;\n");
        printf("0. Sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Número de aviões no hangar: %d\n", hangar.topo + 1);
                break;
            case 2:
                tirarAviao(&hangar);
                break;
            case 3:
                printf("Digite o nome do avião: ");
                scanf("%s", novoAviao.nome);
                printf("Digite o ID do avião: ");
                scanf("%d", &novoAviao.id);
                adicionarAviao(&hangar, novoAviao);
                break;
            case 4:
                listarAvioesNoHangar(&hangar);
                break;
            case 5:
                listarPrimeiroAviao(&hangar);
                break;
            case 6:
                printf("Digite a posição do avião a ser removido: ");
                int posicao;
                scanf("%d", &posicao);
                tirarAviaoPorPosicao(&hangar, posicao);
                break;
            case 0:
                printf("Saindo do programa. Até mais.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    LiberarMemoria(&hangar);
    return 0;
}
