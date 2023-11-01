#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.c"
#include "pessoa.h"
int main()
{
    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));

    Preencher_pessoa(pessoa);
    Imprimir_pessoa(pessoa);
    Libera_pessooa(pessoa);

    return 0;
}
