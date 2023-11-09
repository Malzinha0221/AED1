#ifndef TURMA_H
#define TURMA_H

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
} ALUNO;

// Definição do TDA TURMA
typedef struct {
    ALUNO *alunos;  // Vetor de ALUNOs
    int quantidade; // Quantidade de alunos na turma
} TURMA;

TURMA *criarTurma(int quantidade);
void inserirAluno(TURMA *turma, int indice, int codigo, const char *nome, int idade, float coeficiente);
void liberarTurma(TURMA *turma);
void buscarAlunoPorCodigo(TURMA *turma, int codigo);
void imprimirCodigosENomes(TURMA *turma);
#endif
