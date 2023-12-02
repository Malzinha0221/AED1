#define MAX_ALUNOS 100
#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int matricula;
} Aluno;

typedef struct {
    Aluno alunos[MAX_ALUNOS];
    int quantidade;
} ListaAlunos;
void inicializarLista(ListaAlunos *lista);
void liberarLista(ListaAlunos *lista);
int obterQuantidade(ListaAlunos *lista);
bool listaCheia(ListaAlunos *lista);
bool listaVazia(ListaAlunos *lista);
void exibirLista(ListaAlunos *lista);
void inserirOrdenado(ListaAlunos *lista, int matricula);
void excluirElemento(ListaAlunos *lista, int matricula);
void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula);
#endif
