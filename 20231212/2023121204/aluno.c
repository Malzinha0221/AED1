#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializar a lista de alunos
void inicializarLista(ListaAlunos* lista) {
    lista->cabeca = NULL;
}

// Reiniciar a lista de alunos (liberar todos os nós)
void reiniciarLista(ListaAlunos* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->cabeca = NULL;
}

// Retornar a quantidade de elementos válidos na lista
int tamanhoLista(ListaAlunos* lista) {
    int tamanho = 0;
    No* atual = lista->cabeca;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

// Verificar se a lista está cheia (assumindo que a memória está limitada)
int listaCheia(ListaAlunos* lista) {
    // Pode ser implementado de acordo com os requisitos do sistema
    return 0;
}

// Verificar se a lista está vazia
int listaVazia(ListaAlunos* lista) {
    return lista->cabeca == NULL;
}

// Exibir os elementos da lista
void exibirLista(ListaAlunos* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Idade: %d\n", atual->aluno.matricula, atual->aluno.nome, atual->aluno.idade);
        atual = atual->proximo;
    }
}

// Inserir um aluno de forma ordenada (ascendente) na lista
void inserirOrdenado(ListaAlunos* lista, Aluno novoAluno) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    novoNo->aluno = novoAluno;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    // Se a lista estiver vazia ou o primeiro aluno tiver uma matrícula maior
    if (listaVazia(lista) || novoAluno.matricula < lista->cabeca->aluno.matricula) {
        novoNo->proximo = lista->cabeca;
        if (lista->cabeca != NULL) {
            lista->cabeca->anterior = novoNo;
        }
        lista->cabeca = novoNo;
    } else {
        No* atual = lista->cabeca;
        while (atual->proximo != NULL && novoAluno.matricula > atual->proximo->aluno.matricula) {
            atual = atual->proximo;
        }

        novoNo->proximo = atual->proximo;
        novoNo->anterior = atual;

        if (atual->proximo != NULL) {
            atual->proximo->anterior = novoNo;
        }

        atual->proximo = novoNo;
    }
}

// Excluir um aluno da lista pelo valor mantendo a lista ordenada
void excluirElemento(ListaAlunos* lista, int matricula) {
    No* atual = lista->cabeca;

    while (atual != NULL && atual->aluno.matricula != matricula) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Aluno com matrícula %d não encontrado.\n", matricula);
        return;
    }

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->cabeca = atual->proximo;
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
}
char obterInicialPeloMatricula(int *matricula) {
    int ultimoDigito = *matricula % 10;
    char inicial = 'A' + ultimoDigito;

    // Garantindo que o caractere resultante esteja no intervalo 'A' a 'Z'
    if (inicial < 'A' || inicial > 'Z') {
        inicial = 'A';
    }

    return inicial;
}
