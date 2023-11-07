#include <stdio.h>
#include "cubo.h"
#include "cubo.c"

int main() {
    Cubo meuCubo;
    InicializarCubo(&meuCubo, 3.0);

    printf("Área do cubo: %.2lf unidades quadradas\n", CalcularArea(&meuCubo));
    printf("Volume do cubo: %.2lf unidades cúbicas\n", CalcularVolume(&meuCubo));

    return 0;
}
