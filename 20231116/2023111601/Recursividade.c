#include <stdio.h>

int k_esimoDigito(int n, int k) {
    // Verifica se k é um valor válido
    if (k <= 0) {
        printf("O valor de k deve ser maior que zero.\n");
        return -1;
    }

    // Caso base: quando atingimos o k-ésimo dígito
    if (k == 1) {
        return n % 10;
    }

    // Chamada recursiva para obter o próximo dígito
    return k_esimoDigito(n / 10, k - 1);
}

int main() {
    int numero = 2845;
    int k = 3;

    int resultado = k_esimoDigito(numero, k);

    if (resultado != -1) {
        printf("O k-ésimo dígito de %d (da direita para a esquerda) é: %d\n", numero, resultado);
    }

    return 0;
}
