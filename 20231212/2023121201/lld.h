#ifndef LLD_H
#define LLD_H
#include <stdbool.h>
// Estrutura representando um aluno
typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

// Estrutura representando um nó da lista
typedef struct No {
    Aluno aluno;
    struct No* proximo;
} NoLista;

// Estrutura representando a lista ligada dinâmica
typedef struct {
    NoLista* inicio;  // Ponteiro para o início da lista
    int quantidade;   // Quantidade de elementos na lista
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
void reiniciarLista(ListaAlunos* lista);
int obterQuantidade(ListaAlunos* lista);
bool listaCheia(ListaAlunos* lista);
bool listaVazia(ListaAlunos* lista);
void exibirLista(ListaAlunos* lista);
void inserirOrdenado(ListaAlunos* lista, Aluno aluno);
void excluirElemento(ListaAlunos* lista, int matricula);


#endif