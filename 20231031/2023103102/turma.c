#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"
// Função para criar uma nova TURMA com uma quantidade de alunos definida
TURMA *criarTurma(int quantidade) {
    TURMA *novaTurma = (TURMA *)malloc(sizeof(TURMA));
    novaTurma->alunos = (ALUNO *)malloc(quantidade * sizeof(ALUNO));
    novaTurma->quantidade = quantidade;
    return novaTurma;
}

// Função para inserir um aluno na TURMA
void inserirAluno(TURMA *turma, int indice, int codigo, const char *nome, int idade, float coeficiente) {
    if (indice >= 0 && indice < turma->quantidade) {
        ALUNO aluno;
        aluno.codigo = codigo;
        strcpy(aluno.nome, nome);
        aluno.idade = idade;
        aluno.coeficiente = coeficiente;
        turma->alunos[indice] = aluno;
    }
}

// Função para liberar o espaço na memória de uma TURMA
void liberarTurma(TURMA *turma) {
    free(turma->alunos);
    free(turma);
}

// Função para buscar um aluno pelo código do aluno usando busca sequencial
void buscarAlunoPorCodigo(TURMA *turma, int codigo) {
    for (int i = 0; i < turma->quantidade; i++) {
        if (turma->alunos[i].codigo == codigo) {
            printf("Código: %d\n", turma->alunos[i].codigo);
            printf("Nome: %s\n", turma->alunos[i].nome);
            printf("Idade: %d\n", turma->alunos[i].idade);
            printf("Coeficiente: %.2f\n", turma->alunos[i].coeficiente);
            return;
        }
    }
    printf("Aluno com código %d não encontrado na turma.\n", codigo);
}

// Função para imprimir o código e o nome dos alunos de uma TURMA
void imprimirCodigosENomes(TURMA *turma) {
    printf("Códigos e Nomes dos Alunos:\n");
    for (int i = 0; i < turma->quantidade; i++) {
        printf("Código: %d, Nome: %s\n", turma->alunos[i].codigo, turma->alunos[i].nome);
    }
}
