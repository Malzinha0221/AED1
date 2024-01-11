#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void inicializaDeque(DEQUE* d) {
    d->cabeca = malloc(sizeof(ELEMENTO));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

int inserir_Inicio(DEQUE* d, SOLDADO novo_soldado) {
    ELEMENTO* i = malloc(sizeof(ELEMENTO));
    i->sol = novo_soldado;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo = i;
    i->proximo->anterior = i;
    return 1;
}

int inserir_Fim(DEQUE* d, SOLDADO novo_soldado) {
    ELEMENTO* i = malloc(sizeof(ELEMENTO));
    i->sol = novo_soldado;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    d->cabeca->anterior = i;
    i->anterior->proximo = i;
    return 1;
}

int remover_inicio(DEQUE* d) {
    if (d->cabeca->proximo == d->cabeca) return 0;
    ELEMENTO* i = d->cabeca->proximo;
    d->cabeca->proximo = i->proximo;
    i->proximo->anterior = d->cabeca;
    free(i);
    return 1;
}

int remover_fim(DEQUE* d) {
    if (d->cabeca->proximo == d->cabeca) return 0;
    ELEMENTO* i = d->cabeca->anterior;
    d->cabeca->anterior = i->anterior;
    i->anterior->proximo = d->cabeca;
    free(i);
    return 1;
}

SOLDADO inicio(DEQUE* d) {
    return d->cabeca->proximo->sol;
}

SOLDADO fim(DEQUE* d) {
    return d->cabeca->anterior->sol;
}

int contar(DEQUE* d) {
    int contador = 0;
    ELEMENTO* i = d->cabeca->proximo;

    while (i != d->cabeca) {
        contador++;
        i = i->proximo;
    }
    return contador;
}

void mostrarDeque(DEQUE* d) {
    printf("----------------------\n");
    ELEMENTO* i = d->cabeca->proximo;

    while (i != d->cabeca) {
        printf("----------------------------\n");
        printf("SOLDADO: %d\n", i);
        printf("Codigo: %d\n", i->sol.codigo);
        printf("Nome: %s\n", i->sol.nome);
        printf("Grau: %s\n", i->sol.grau);

        i = i->proximo;
    }
}

void vazio(DEQUE* d) {
    if (d->cabeca->proximo == d->cabeca) {
        printf("O deque está vazio.\n");
    } else {
        printf("O deque não está vazio.\n");
    }
}

SOLDADO remover_pos(DEQUE* d, int n) {
    if (n < 1 || n > contar(d)) {
        printf("Posição inválida.\n");
        // Retorna um soldado com código -1 para indicar erro
        SOLDADO erro = {-1, "", ""};
        return erro;
    }

    ELEMENTO* i = d->cabeca->proximo;
    for (int pos = 1; pos < n; pos++) {
        i = i->proximo;
    }
    i->anterior->proximo = i->proximo;
    i->proximo->anterior = i->anterior;
    SOLDADO soldadoRemovido = i->sol;
    free(i);
    return soldadoRemovido;
}
