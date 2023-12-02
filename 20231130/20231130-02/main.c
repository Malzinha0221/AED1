#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lle.h"

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    int opcao, matricula, novaMatricula;
    char nome[50];
    int idade;

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
                printf("Digite o nome do aluno: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Digite a idade do aluno: ");
                scanf("%d", &idade);
                Aluno novoAluno = {matricula, "", idade};
                strncpy(novoAluno.nome, nome, sizeof(novoAluno.nome) - 1);
                inserirOrdenado(&lista, novoAluno);
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

    // Liberar a lista antes de sair
    liberarLista(&lista);

    return 0;
}
