#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lle.h"

// Inicializar a lista
void inicializarLista(ListaAlunos *lista) {
    lista->livre = 0;
    lista->inicio = -1; // Lista vazia
    lista->quantidade = 0;
}

// Função auxiliar para obter um nó livre na lista
int obterNoLivre(ListaAlunos *lista) {
    int indiceLivre = lista->livre;
    lista->livre = lista->nos[lista->livre].proximo; // Atualiza o índice do primeiro nó livre
    return indiceLivre;
}

// Função auxiliar para liberar um nó da lista
void liberarNo(ListaAlunos *lista, int indice) {
    lista->nos[indice].proximo = lista->livre; // Adiciona o nó liberado à lista de livres
    lista->livre = indice;
}

// Função auxiliar para inserir um nó na lista
void inserirNo(ListaAlunos *lista, int indice, Aluno aluno) {
    lista->nos[indice].aluno = aluno;
    lista->nos[indice].proximo = -1; // Último nó na lista
}

// Inserir um elemento de forma ordenada na lista
void inserirOrdenado(ListaAlunos *lista, Aluno aluno) {
    int novoIndice = obterNoLivre(lista);

    // Caso especial: lista vazia ou o novo elemento deve ser o primeiro
    if (lista->inicio == -1 || aluno.matricula < lista->nos[lista->inicio].aluno.matricula) {
        inserirNo(lista, novoIndice, aluno);
        lista->nos[novoIndice].proximo = lista->inicio;
        lista->inicio = novoIndice;
    } else {
        int atual = lista->inicio;
        int anterior = -1;

        // Encontrar posição correta para a inserção mantendo a ordem ascendente
        while (atual != -1 && aluno.matricula > lista->nos[atual].aluno.matricula) {
            anterior = atual;
            atual = lista->nos[atual].proximo;
        }

        inserirNo(lista, novoIndice, aluno);

        // Inserir o novo nó na posição correta
        lista->nos[anterior].proximo = novoIndice;
        lista->nos[novoIndice].proximo = atual;
    }

    lista->quantidade++;
}

// Exibir os elementos da lista
void exibirLista(ListaAlunos *lista) {
    printf("Lista de Alunos:\n");
    int atual = lista->inicio;
    while (atual != -1) {
        Aluno aluno = lista->nos[atual].aluno;
        printf("Matricula: %d, Nome: %s, Idade: %d\n", aluno.matricula, aluno.nome, aluno.idade);
        atual = lista->nos[atual].proximo;
    }
    printf("\n");
}

// Liberar a lista
void liberarLista(ListaAlunos *lista) {
    int atual = lista->inicio;
    while (atual != -1) {
        int proximo = lista->nos[atual].proximo;
        liberarNo(lista, atual);
        atual = proximo;
    }

    // Reinicializar a lista
    inicializarLista(lista);
}

// Retornar a quantidade de elementos válidos na lista
int obterQuantidade(ListaAlunos *lista) {
    return lista->quantidade;
}

// Retornar se a lista está cheia
bool listaCheia(ListaAlunos *lista) {
    return lista->quantidade == 100; // Valor máximo de elementos
}

// Retornar se a lista está vazia
bool listaVazia(ListaAlunos *lista) {
    return lista->quantidade == 0;
}

// Excluir um elemento da lista pelo valor mantendo a lista ordenada
void excluirElemento(ListaAlunos *lista, int matricula) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Impossível excluir elementos.\n");
        return;
    }

    int atual = lista->inicio;
    int anterior = -1;

    while (atual != -1 && lista->nos[atual].aluno.matricula != matricula) {
        anterior = atual;
        atual = lista->nos[atual].proximo;
    }

    if (atual != -1) {
        // Remover o nó da lista
        if (anterior == -1) {
            // O nó a ser excluído é o primeiro
            lista->inicio = lista->nos[atual].proximo;
        } else {
            // O nó a ser excluído não é o primeiro
            lista->nos[anterior].proximo = lista->nos[atual].proximo;
        }

        liberarNo(lista, atual);
        lista->quantidade--;

        printf("Matricula %d excluida com sucesso.\n", matricula);
    } else {
        printf("Matricula %d nao encontrada na lista.\n", matricula);
    }
}

// Alterar o valor de uma matricula mantendo a lista ordenada
void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Impossível alterar matricula.\n");
        return;
    }

    int atual = lista->inicio;

    while (atual != -1 && lista->nos[atual].aluno.matricula != matriculaAntiga) {
        atual = lista->nos[atual].proximo;
    }

    if (atual != -1) {
        // Encontrou a matricula a ser alterada
        lista->nos[atual].aluno.matricula = novaMatricula;
        printf("Matricula alterada de %d para %d com sucesso.\n", matriculaAntiga, novaMatricula);
    } else {
        printf("Matricula %d nao encontrada na lista. Impossível alterar.\n", matriculaAntiga);
    }
}
