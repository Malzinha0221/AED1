#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main() {
    PESSOA *pessoa = (PESSOA *)malloc(sizeof(PESSOA));

    preencherPessoa(pessoa);

    ImprimirPessoa(pessoa);

    free(pessoa);
    return 0;
}
