#include <stdio.h>
#include <stdbool.h>
#include "aluno.h"

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    int opcao, matricula, novaMatricula;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Inserir Elemento\n");
        printf("2. Excluir Elemento\n");
        printf("3. Alterar Matricula\n");
        printf("4. Exibir Lista\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matricula a ser inserida: ");
                scanf("%d", &matricula);
                inserirOrdenado(&lista, matricula);
                break;
            case 2:
                printf("Digite a matricula a ser excluida: ");
                scanf("%d", &matricula);
                excluirElemento(&lista, matricula);
                break;
            case 3:
                printf("Digite a matricula a ser alterada: ");
                scanf("%d", &matricula);
                printf("Digite a nova matricula: ");
                scanf("%d", &novaMatricula);
                alterarMatricula(&lista, matricula, novaMatricula);
                break;
            case 4:
                exibirLista(&lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
