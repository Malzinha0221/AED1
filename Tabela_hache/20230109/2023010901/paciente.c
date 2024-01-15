#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>

void inicializahash(TB_HASH tab){
    int i;
    for (int i = 0; i < N; i++) {
        tab[i]=NULL;

    }
}

int m_hash (int cod_paciente){
    return (cod_paciente%N);
}

int inserir (TB_HASH tab, PACIENTE paciente){
    int h = m_hash(paciente.cod_paciente);
    while(tab[h]!=NULL){
        if (tab[h] ->cod_paciente == paciente.cod_paciente) {
            return 0;
        }
    h = (h+1) % N;
    }
    if (tab[N]==NULL){
        tab[h] = malloc(sizeof(PACIENTE));
        *(tab[h])=paciente;
    } else{
        h++;
        while (tab[h]!=NULL){
            h++;
        }
        tab[h] = malloc(sizeof(PACIENTE));
        *(tab[h])=paciente;
    }
    return 1;
}
PACIENTE* busca (TB_HASH tab, int cod_paciente){
    int h = m_hash(cod_paciente);
    while (tab[h]!=NULL){
        if(tab[h]->cod_paciente == cod_paciente)
            return tab[h];
        h= (h+1)%N;
    }
    return NULL;
}
void mostrarHash (TB_HASH tab){
    for (int i = 0; i < N; i++) {
        if(tab[i]!=NULL){
            printf("\nPaciente: %d \n",i);
            printf("Codigo do paciente: %d\n", tab[i]->cod_paciente);
            printf(" Nome: %s\n", tab[i]->nome);
            printf(" CPF: %s\n", tab[i]->cpf);
            printf("Idade: %d\n",tab[i]->idade);
        } else
            printf("Paciente: %d NULL\n",i);
    }
}