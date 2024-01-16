// paciente.h
#define N 101

#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int cod_paciente;
    char *nome;
    char *cpf;
    int idade;
    int disponivel;  // Adicionando o campo disponivel
} PACIENTE;

typedef PACIENTE *TB_HASH[N];

int m_hash(int cod_paciente);
int inserir(TB_HASH tab, PACIENTE paciente);
int excluir(TB_HASH tab, int cod_paciente);
void inicializahash(TB_HASH tab);
void mostrarHash(TB_HASH tab);
PACIENTE *busca(TB_HASH tab, int cod_paciente);

#endif
