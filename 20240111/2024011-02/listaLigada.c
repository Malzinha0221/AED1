#include "listaLigada.h"
#include <stdio.h>
#include <stdlib.h>

void inicializahash(TB_HASH tab){
    int i;
    for (int i = 0; i < N; i++) {
        tab[i]=NULL;
    }
}

int m_hash (int cod_pac){
    return (cod_pac%N);
}

int inserir (TB_HASH tab, PACIENTE paciente){
    int h = m_hash(paciente.cod_pac);
    ELEMENTO *anterior = NULL;
    ELEMENTO* e=tab[h];
    while (e!=NULL){
        if (e->paciente.cod_pac == paciente.cod_pac)
            return 0;
        anterior = e;
        e=e->proximo;
    }
    if (e==NULL){
        e = malloc (sizeof(ELEMENTO));
        e->paciente=paciente;
        e->proximo=NULL;
        if(anterior == NULL)
            tab[h]=e;
        else
            anterior->proximo=e;
    }
    return 1;
}
PACIENTE* busca (TB_HASH tab, int cod_paciente){
    int h = m_hash(cod_paciente);
    ELEMENTO* e=tab[h];
    while (e!=NULL){
        if(e->paciente.cod_pac == cod_paciente)
            return &e->paciente;
        e= e->proximo;
    }
    return NULL;
}
void mostrarHash (TB_HASH tab){
    ELEMENTO* e;
    for (int i = 0; i < N; i++) {
        if(tab[i]!=NULL){
            e=tab[i];
            printf("\nPaciente: %d",i);
            while (e!=NULL){
                printf("Nome: %s", tab[i]->paciente.nome);
                e=e->proximo;
            }
            printf(" NULL");
        } else
            printf("\nPaciente: %d NULL", i);
    }
}
void excluirElementoHash(TB_HASH tab, PACIENTE paciente) {
    int h = m_hash(paciente.cod_pac);
    ELEMENTO *anterior = NULL;
    ELEMENTO *atual = tab[h];
    while (atual != NULL && atual->paciente.cod_pac != paciente.cod_pac) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL) {
        if (anterior == NULL) {
            tab[h] = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
    }
}
