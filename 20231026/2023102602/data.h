#ifndef DATA_H_INCLUCED
#define DATA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct{
    char nome[50];
    DATA data_nascimento;
    char CPF[15];
}PESSOA;

void preencherData(DATA *data);
void ImprimirData(DATA *data);
void preencherPessoa(PESSOA *pessoa);
void ImprimirPessoa(PESSOA *pessoa);

#endif // DATA_H_INCLUDED
