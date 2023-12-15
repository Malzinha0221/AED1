#include "aluno.h"
#include <stdio.h>
#include <string.h>

int main() {
    ListaAlunos listaA, listaE, listaL;
    inicializarLista(&listaA);
    inicializarLista(&listaE);
    inicializarLista(&listaL);

    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir aluno\n");
        printf("2. Exibir os elementos das listas\n");
        printf("3. Excluir aluno\n");
        printf("0. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aluno novoAluno;
                printf("Informe a matrícula do aluno: ");
                scanf("%d", &novoAluno.matricula);

                printf("Informe o nome do aluno: ");
                scanf("%s", novoAluno.nome);

                printf("Informe a idade do aluno: ");
                scanf("%d", &novoAluno.idade);

                // Verificar a letra inicial do nome
                char inicial = novoAluno.nome[0];

                // Inserindo na lista correspondente com base na letra inicial do nome
                if (inicial >= 'A' && inicial <= 'D') {
                    inserirOrdenado(&listaA, novoAluno);
                } else if (inicial >= 'E' && inicial <= 'J') {
                    inserirOrdenado(&listaE, novoAluno);
                } else if (inicial >= 'L' && inicial <= 'Y') {
                    inserirOrdenado(&listaL, novoAluno);
                } else {
                    printf("Nome não pertence a uma lista específica.\n");
                }

                break;
            }
            case 2:
                printf("Lista A:\n");
                exibirLista(&listaA);

                printf("Lista E:\n");
                exibirLista(&listaE);

                printf("Lista L:\n");
                exibirLista(&listaL);
                break;

            case 3: {
                int matriculaExcluir;
                printf("Informe a matrícula do aluno a excluir: ");
                scanf("%d", &matriculaExcluir);

                char inicial = obterInicialPeloMatricula(&matriculaExcluir);
                switch (inicial) {
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                        excluirElemento(&listaA, matriculaExcluir);
                        break;
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                        excluirElemento(&listaE, matriculaExcluir);
                        break;
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                        excluirElemento(&listaL, matriculaExcluir);
                        break;
                    default:
                        printf("Matrícula não pertence a uma lista específica.\n");
                        break;
                }
                break;
            }
        }

    } while (opcao != 0);

    // Reiniciar as listas
    reiniciarLista(&listaA);
    reiniciarLista(&listaE);
    reiniciarLista(&listaL);

    return 0;
}
