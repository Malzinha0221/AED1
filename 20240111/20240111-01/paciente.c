#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>

void inicializahash(TB_HASH tab) {
    int i;
    for (int i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}

int m_hash(int cod_paciente) {
    return (cod_paciente % N);
}

int inserir(TB_HASH tab, PACIENTE paciente) {
    int h = m_hash(paciente.cod_paciente);

    while (tab[h] != NULL && tab[h]->disponivel != 1) {
        if (tab[h]->cod_paciente == paciente.cod_paciente) {
            return 0;
        }
        h = (h + 1) % N;
    }

    if (tab[h] == NULL || tab[h]->disponivel == 1) {
        if (tab[h] == NULL) {
            tab[h] = malloc(sizeof(PACIENTE));
        }
        *(tab[h]) = paciente;
        return 1;
    } else {
        // Lidar com o caso em que a tabela está cheia e não há espaço disponível.
        return 0;
    }
}

int excluir(TB_HASH tab, int cod_paciente) {
    int h = m_hash(cod_paciente);

    while (tab[h] != NULL) {
        if (tab[h]->cod_paciente == cod_paciente) {
            tab[h]->disponivel = 1;  // Marcar como "não disponível" (excluído)
            free(tab[h]);  // Liberar a memória alocada para o paciente
            tab[h] = NULL;  // Definir como NULL após a exclusão
            return 1;  // Paciente excluído com sucesso
        }
        h = (h + 1) % N;
    }

    return 0;  // Paciente não encontrado
}

PACIENTE *busca(TB_HASH tab, int cod_paciente) {
    int h = m_hash(cod_paciente);
    while (tab[h] != NULL) {
        if (tab[h]->cod_paciente == cod_paciente && tab[h]->disponivel != 1)
            return tab[h];
        h = (h + 1) % N;
    }
    return NULL;
}

void mostrarHash(TB_HASH tab) {
    for (int i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            printf("\nPaciente: %d \n", i);
            printf("Codigo do paciente: %d\n", tab[i]->cod_paciente);
            printf(" Nome: %s\n", tab[i]->nome);
            printf(" CPF: %s\n", tab[i]->cpf);
            printf("Idade: %d\n", tab[i]->idade);
        } else
            printf("Paciente: %d NULL\n", i);
    }
}
