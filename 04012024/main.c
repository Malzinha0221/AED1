#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main() {
    DEQUE z;
    inicializaDeque(&z);

    SOLDADO soldado;
    soldado.codigo = 1;
    soldado.nome = "Soldado A";
    soldado.grau = "Grau A";
    inserir_Fim(&z, soldado);

    soldado.codigo = 2;
    soldado.nome = "Soldado B";
    soldado.grau = "Grau B";
    inserir_Fim(&z, soldado);

    soldado.codigo = 3;
    soldado.nome = "Soldado C";
    soldado.grau = "Grau C";
    inserir_Fim(&z, soldado);

    soldado.codigo = 4;
    soldado.nome = "Soldado D";
    soldado.grau = "Grau D";
    inserir_Fim(&z, soldado);

    soldado.codigo = 5;
    soldado.nome = "Soldado E";
    soldado.grau = "Grau E";
    inserir_Fim(&z, soldado);

    mostrarDeque(&z);

    int n = 3;  // Valor de n

    // Simula o problema de Josephus
    while (contar(&z) > 1) {
        for (int i = 1; i < n; i++) {
            // Move n-1 soldados para o final
            SOLDADO soldadoRemovido = inicio(&z);
            remover_inicio(&z);
            inserir_Fim(&z, soldadoRemovido);
        }

        // Remove o soldado n
        SOLDADO soldadoEliminado = inicio(&z);
        remover_inicio(&z);

        // Exibe o soldado eliminado
        printf("Soldado %s eliminado.\n", soldadoEliminado.nome);
    }

    // Exibe o soldado que escapou
    SOLDADO soldadoEscapado = inicio(&z);
    printf("Soldado %s escapou!\n", soldadoEscapado.nome);

    return 0;
}
