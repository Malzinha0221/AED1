#include <stdio.h>
#include "complexo.h"
#include "complexo.c"

int main() {
    Complexo *z1 = criarComplexo(3.0, 4.0);
    Complexo *z2 = criarComplexo(1.0, 2.0);

    Complexo *soma = somaComplexos(z1, z2);
    Complexo *subtracao = subtraiComplexos(z1, z2);
    Complexo *multiplicacao = multiplicaComplexos(z1, z2);
    Complexo *divisao = divideComplexos(z1, z2);

    printf("Soma: %.2f + %.2fi\n", obterParteReal(soma), obterParteImaginaria(soma));
    printf("Subtração: %.2f + %.2fi\n", obterParteReal(subtracao), obterParteImaginaria(subtracao));
    printf("Multiplicação: %.2f + %.2fi\n", obterParteReal(multiplicacao), obterParteImaginaria(multiplicacao));
    printf("Divisão: %.2f + %.2fi\n", obterParteReal(divisao), obterParteImaginaria(divisao));

    destruirComplexo(z1);
    destruirComplexo(z2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}
