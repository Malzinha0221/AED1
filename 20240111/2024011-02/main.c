#include "listaLigada.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TB_HASH tabela;
    PACIENTE p, *pr;
    inicializahash(tabela);

    p.cod_pac = 1291;
    p.nome = "Aguinaldo";
    p.cpf = "0000000000000";
    p.idade = 27;
    inserir(tabela, p);

    p.cod_pac = 1191;
    p.nome = "Camila";
    p.cpf = "000000000000";
    p.idade = 20;
    inserir(tabela, p);

    p.cod_pac = 1089;
    p.nome = "Adriano";
    p.cpf = "00000000000";
    p.idade = 20;
    inserir(tabela, p);

    mostrarHash(tabela);

    // Criar um paciente temporário com as informações do paciente a ser excluído
    PACIENTE pacienteParaExcluir;
    pacienteParaExcluir.cod_pac = 1089;

    // Chamar a função para excluir o elemento
    excluirElementoHash(tabela, pacienteParaExcluir);

    // Verificar se o elemento foi excluído
    pr = busca(tabela, 1089);
    if (pr == NULL) {
        printf("\nElemento excluído com sucesso.\n");
    } else {
        printf("\nElemento não foi excluído.\n");
    }

    return 0;
}
