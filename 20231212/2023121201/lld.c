#include "lld.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Inicializar a lista
void inicializarLista(ListaAlunos* lista) {
    lista->inicio = NULL;
    lista->quantidade = 0;
}

// Reiniciar a lista (liberar todos os nós)
void reiniciarLista(ListaAlunos* lista) {
    NoLista* atual = lista->inicio;
    while (atual != NULL) {
        NoLista* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    lista->quantidade = 0;
}

// Retornar a quantidade de elementos válidos na lista
int obterQuantidade(ListaAlunos* lista) {
    return lista->quantidade;
}

// Retornar se a lista está cheia (alocação dinâmica, então teoricamente nunca está cheia)
bool listaCheia(ListaAlunos* lista) {
    return false;
}

// Retornar se a lista está vazia
bool listaVazia(ListaAlunos* lista) {
    return lista->quantidade == 0;
}

// Exibir os elementos da lista
void exibirLista(ListaAlunos* lista) {
    NoLista* atual = lista->inicio;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Idade: %d\n", atual->aluno.matricula, atual->aluno.nome, atual->aluno.idade);
        atual = atual->proximo;
    }
    printf("\n");
}

// Inserir um elemento de forma ordenada na lista
void inserirOrdenado(ListaAlunos* lista, Aluno aluno) {
    NoLista* novoNo = (NoLista*)malloc(sizeof(NoLista));
    if (novoNo == NULL) {
        printf("Erro: falha na alocação de memória\n");
        return;
    }

    novoNo->aluno = aluno;
    novoNo->proximo = NULL;

    if (lista->inicio == NULL || aluno.matricula < lista->inicio->aluno.matricula) {
        // Caso especial: lista vazia ou novo elemento deve ser o primeiro
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
    } else {
        NoLista* atual = lista->inicio;
        NoLista* anterior = NULL;

        // Encontrar posição correta para a inserção mantendo a ordem ascendente
        while (atual != NULL && aluno.matricula > atual->aluno.matricula) {
            anterior = atual;
            atual = atual->proximo;
        }

        novoNo->proximo = atual;
        anterior->proximo = novoNo;
    }

    lista->quantidade++;
}

// Excluir um elemento da lista pelo valor mantendo a lista ordenada
void excluirElemento(ListaAlunos* lista, int matricula) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Impossível excluir elementos.\n");
        return;
    }

    NoLista* atual = lista->inicio;
    NoLista* anterior = NULL;

    while (atual != NULL && atual->aluno.matricula != matricula) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        // Remover o nó da lista
        if (anterior == NULL) {
            // O nó a ser excluído é o primeiro
            lista->inicio = atual->proximo;
        } else {
            // O nó a ser excluído não é o primeiro
            anterior->proximo = atual->proximo;
        }

        free(atual);
        lista->quantidade--;

        printf("Matricula %d excluida com sucesso.\n", matricula);
    } else {
        printf("Matricula %d nao encontrada na lista.\n", matricula);
    }
}
