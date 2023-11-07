#include <stdlib.h>
#include "complexo.h"

struct Complexo {
    double real;
    double imag;
};

Complexo *criarComplexo(double real, double imag) {
    Complexo *c = (Complexo *)malloc(sizeof(Complexo));
    if (c != NULL) {
        c->real = real;
        c->imag = imag;
    }
    return c;
}

void destruirComplexo(Complexo *c) {
    free(c);
}

Complexo *somaComplexos(Complexo *a, Complexo *b) {
    return criarComplexo(a->real + b->real, a->imag + b->imag);
}

Complexo *subtraiComplexos(Complexo *a, Complexo *b) {
    return criarComplexo(a->real - b->real, a->imag - b->imag);
}

Complexo *multiplicaComplexos(Complexo *a, Complexo *b) {
    return criarComplexo(a->real * b->real - a->imag * b->imag, a->real * b->imag + a->imag * b->real);
}

Complexo *divideComplexos(Complexo *a, Complexo *b) {
    double denominador = b->real * b->real + b->imag * b->imag;
    return criarComplexo((a->real * b->real + a->imag * b->imag) / denominador, (a->imag * b->real - a->real * b->imag) / denominador);
}

double obterParteReal(Complexo *c) {
    return c->real;
}

double obterParteImaginaria(Complexo *c) {
    return c->imag;
}
