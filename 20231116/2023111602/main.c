#include <stdio.h>
#include "registro.h"
int main() {
    Vetor v1 = {1.0, 2.0, 3.0};
    Vetor v2 = {4.0, 5.0, 6.0};
    Vetor resultado_soma;

    soma(&v1, &v2, &resultado_soma);

    printf("Soma: (%.2f, %.2f, %.2f)\n", resultado_soma.x, resultado_soma.y, resultado_soma.z);

    float resultado_produto_escalar = produto_escalar(&v1, &v2);

    printf("Produto Escalar: %.2f\n", resultado_produto_escalar);

    return 0;
}
