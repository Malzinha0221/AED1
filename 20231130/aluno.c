#include <stdio.h>
#include <stdbool.h>
#include "aluno.h"
void inicializarLista(ListaAlunos *lista) {
    lista->quantidade = 0;
}

void liberarLista(ListaAlunos *lista) {
    // Não é necessário fazer nada especial para liberar a lista nesse caso.
    // Em implementações mais complexas, poderia ser necessário liberar memória alocada dinamicamente.
}

int obterQuantidade(ListaAlunos *lista) {
    return lista->quantidade;
}

bool listaCheia(ListaAlunos *lista) {
    return lista->quantidade == MAX_ALUNOS;
}

bool listaVazia(ListaAlunos *lista) {
    return lista->quantidade == 0;
}

void exibirLista(ListaAlunos *lista) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("Matricula: %d\n", lista->alunos[i].matricula);
    }
    printf("\n");
}

void inserirOrdenado(ListaAlunos *lista, int matricula) {
    if (listaCheia(lista)) {
        printf("Lista cheia. Impossível inserir mais elementos.\n");
        return;
    }

    int i;
    // Encontrar a posição correta para inserção mantendo a ordem ascendente
    for (i = lista->quantidade - 1; i >= 0 && lista->alunos[i].matricula > matricula; i--) {
        lista->alunos[i + 1] = lista->alunos[i];
    }

    // Inserir o novo elemento na posição correta
    lista->alunos[i + 1].matricula = matricula;
    lista->quantidade++;

    printf("Matricula %d inserida com sucesso.\n", matricula);
}

void excluirElemento(ListaAlunos *lista, int matricula) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Impossível excluir elementos.\n");
        return;
    }

    int i;
    for (i = 0; i < lista->quantidade; i++) {
        if (lista->alunos[i].matricula == matricula) {
            // Deslocar elementos para preencher o espaço da matrícula excluída
            for (int j = i; j < lista->quantidade - 1; j++) {
                lista->alunos[j] = lista->alunos[j + 1];
            }
            lista->quantidade--;

            printf("Matricula %d excluida com sucesso.\n", matricula);
            return;
        }
    }

    printf("Matricula %d nao encontrada na lista.\n", matricula);
}

void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Impossível alterar matricula.\n");
        return;
    }

    // Procurar a matrícula antiga na lista
    int i;
    for (i = 0; i < lista->quantidade; i++) {
        if (lista->alunos[i].matricula == matriculaAntiga) {
            // Atualizar a matrícula com o novo valor
            lista->alunos[i].matricula = novaMatricula;

            printf("Matricula alterada de %d para %d com sucesso.\n", matriculaAntiga, novaMatricula);
            return;
        }
    }

    printf("Matricula %d nao encontrada na lista. Impossível alterar.\n", matriculaAntiga);
}
