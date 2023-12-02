#ifndef LLE_H
#define LLE_H

// Definindo a estrutura do aluno
typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

// Definindo a estrutura do nó da lista
typedef struct {
    Aluno aluno;
    int proximo; // Índice do próximo nó na lista
} NoLista;

// Definindo a estrutura da lista
typedef struct {
    NoLista nos[100]; // Lista ligada estática com no máximo 100 elementos
    int livre; // Índice do primeiro nó livre na lista
    int inicio; // Índice do primeiro nó válido na lista
    int quantidade; // Quantidade de elementos válidos na lista
} ListaAlunos;

void inicializarLista(ListaAlunos *lista);
int obterNoLivre(ListaAlunos *lista);
void liberarNo(ListaAlunos *lista, int indice);
void inserirNo(ListaAlunos *lista, int indice, Aluno aluno);
void inserirOrdenado(ListaAlunos *lista, Aluno aluno);
void exibirLista(ListaAlunos *lista);
void liberarLista(ListaAlunos *lista);
int obterQuantidade(ListaAlunos *lista);
bool listaCheia(ListaAlunos *lista);
bool listaVazia(ListaAlunos *lista);
void excluirElemento(ListaAlunos *lista, int matricula);
void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula);

#endif