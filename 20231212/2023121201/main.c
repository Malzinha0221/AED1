#include "lld.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir quantidade de Alunos\n");
        printf("2. Excluir a Matricula\n");
        printf("3. Imprimir Lista\n");
        printf("0. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int quantidadeAlunos;
                printf("Informe a quantidade de alunos: ");
                scanf("%d", &quantidadeAlunos);

                for (int i = 0; i < quantidadeAlunos; i++) {
                    Aluno novoAluno;
                    printf("Informe a matricula do aluno %d: ", i + 1);
                    scanf("%d", &novoAluno.matricula);
                    printf("Informe o nome do aluno %d: ", i + 1);
                    getchar();
                    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
                    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
                    printf("Informe a idade do aluno %d: ", i + 1);
                    scanf("%d", &novoAluno.idade);

                    inserirOrdenado(&lista, novoAluno);
                }
                break;
            }
            case 2: {
                int matriculaExcluir;
                printf("Informe a matricula do aluno a excluir: ");
                scanf("%d", &matriculaExcluir);
                excluirElemento(&lista, matriculaExcluir);
                break;
            }
            case 3:
                // Exibir a lista
                printf("Lista de Alunos:\n");
                exibirLista(&lista);
                break;
            case 0:
                // Sair
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // Reiniciar a lista antes de encerrar o programa
    reiniciarLista(&lista);

    return 0;
}
