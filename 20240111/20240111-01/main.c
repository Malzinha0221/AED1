#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    TB_HASH tabela;
    PACIENTE p, *pr;
    inicializahash(tabela);

    p.cod_paciente = 1291;
    p.nome = "Aguinaldo";
    p.cpf = "0000000000000";
    p.idade = 27;
    inserir(tabela,p);

    p.cod_paciente = 1191;
    p.nome = "Camila";
    p.cpf = "000000000000";
    p.idade = 20;
    inserir(tabela, p);

    p.cod_paciente = 1089;
    p.nome = "Adriano";
    p.cpf = "00000000000";
    p.idade = 20;
    inserir(tabela,p);

    mostrarHash(tabela);

    excluir(tabela,1191);

    mostrarHash(tabela);

    pr= busca(tabela, 1089);
    printf("Achou Nome: %s", pr->nome);
}
