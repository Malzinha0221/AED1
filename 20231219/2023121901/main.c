#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct Decolagem pista;
    inicioDecolagem(&pista);
    int opcao;
    struct Aviao novoAviao;

    do {
        printf("\nMenu:\n");
        printf("1. Listar número de aviões na fila de decolagem;\n");
        printf("2. Autorizar decolagem do primeiro avião;\n");
        printf("3. Adicionar avião à fila de decolagem;\n");
        printf("4. Listar aviões na fila de decolagem;\n");
        printf("5. Listar características do primeiro avião;\n");
        printf("0. Sair.\n");
        printf("Escolar uma opção: ");

        scanf("%d",&opcao);

        switch (opcao) {
            case 1:
                printf("Número de aviões na fila de decolagem: %d\n", (pista.fim - pista.inicio+MAX_AVIAO)%MAX_AVIAO+1);
                break;
            case 2:
                AutorizarDecolagem(&pista);
                break;
            case 3:
                printf("Digite o nome do avião: ");
                scanf("%s", novoAviao.nome);
                printf("Digite o ID do avião: ");
                scanf("%d", &novoAviao.id);
                EnfilerarAviao(&pista, novoAviao);
                break;
            case 4:
                ListaAviao(&pista);
                break;
            case 5:
                ListaPrimeiroAviao(&pista);
                break;
            case 0:
                printf("Saindo do programa. Até mais\n");
                break;
            default:
                printf("Opção inválida. Tente outra vez.\n");
        }
    } while (opcao!=0);

    LiberarMemoria(&pista);
    return 0;
}