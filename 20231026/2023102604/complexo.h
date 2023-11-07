#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct Complexo Complexo;

Complexo *criarComplexo(double real, double imag);
void destruirComplexo(Complexo *c);
Complexo *somaComplexos(Complexo *a, Complexo *b);
Complexo *subtraiComplexos(Complexo *a, Complexo *b);
Complexo *multiplicaComplexos(Complexo *a, Complexo *b);
Complexo *divideComplexos(Complexo *a, Complexo *b);

double obterParteReal(Complexo *c);
double obterParteImaginaria(Complexo *c);

#endif
