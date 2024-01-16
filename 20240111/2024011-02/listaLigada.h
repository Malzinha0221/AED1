#define N 101
#ifndef LISTALIGADA_H
#define LISTALIGADA_H

typedef struct {
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
}PACIENTE;

typedef struct aux {
    PACIENTE paciente;
    struct aux* proximo;
}ELEMENTO;

typedef ELEMENTO* TB_HASH[N];

int m_hash (int cod_pac);
int inserir (TB_HASH tab, PACIENTE paciente);
void inicializahash(TB_HASH tab);
void mostrarHash (TB_HASH tab);
PACIENTE* busca (TB_HASH tab, int cod_paciente);
void excluirElementoHash (TB_HASH tab, PACIENTE paciente);

#endif