#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
void Preencher_pessoa(Pessoa *pessoa)
{
    printf("Escreva seu primeiro nome: ");
    scanf("%s", pessoa->nome);

    printf("Escreva sua data de nascimento Exemplo:10/02/1470: ");
    scanf("%s", pessoa-> data_nascimento);

    printf("Escreva seu CPF (123.456.789-10): ");
    scanf("%s", pessoa-> cpf);
}

void Libera_pessooa(Pessoa *pessoa)
{
    free(pessoa);
}

void Imprimir_pessoa(const Pessoa *pessoa)
{
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de nascimento: %s\n", pessoa->data_nascimento);
    printf("CPF: %s\n",pessoa->cpf);
}
