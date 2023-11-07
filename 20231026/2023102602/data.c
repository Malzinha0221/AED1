#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "data.h"

void preencherData(DATA *data){
    data->dia=20;
    data->mes=3;
    data->ano=1998;
}

void ImprimirData(DATA *data){
    printf("%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

void preencherPessoa(PESSOA *pessoa){
    strcpy(pessoa->nome,"Daniel Nazario");
    preencherData(&pessoa->data_nascimento);
    strcpy(pessoa->CPF, "123.456.789-11");
}

void ImprimirPessoa(PESSOA *pessoa){
    printf("Nome: %s\n",pessoa->nome);
    printf("CPF: %s\n",pessoa->CPF);
    printf("Data de Nascimento: ");
    ImprimirData(&pessoa->data_nascimento);
}
