#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

struct pessoa
{
    char nome[20];
    char data_nascimento[11]; // XX/XX/XXXX
    char cpf[15];             // xxx.xxx.xxx-xx
};

typedef struct pessoa Pessoa;
// Colocar as funcões criadas
void Preencher_pessoa(Pessoa *pessoa);
void Libera_pessooa(Pessoa *pessoa);
void Imprimir_pessoa(const Pessoa *pessoa);
#endif // PESSOA_H_INCLUDED
