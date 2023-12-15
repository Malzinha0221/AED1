// aluno.h

#ifndef ALUNO_H
#define ALUNO_H

// Estrutura para representar um aluno
typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

// Estrutura para representar um nó da lista
typedef struct No {
    Aluno aluno;
    struct No* proximo;
    struct No* anterior;
} No;


// Estrutura para representar a lista de alunos
typedef struct {
    No* cabeca;
} ListaAlunos;


void inicializarLista(ListaAlunos* lista);
void reiniciarLista(ListaAlunos* lista);
int tamanhoLista(ListaAlunos* lista);
int listaCheia(ListaAlunos* lista);
int listaVazia(ListaAlunos* lista);
void exibirLista(ListaAlunos* lista);
void inserirOrdenado(ListaAlunos* lista, Aluno novoAluno);
void excluirElemento(ListaAlunos* lista, int matricula);
char obterInicialPeloMatricula(int *matricula);

#endif