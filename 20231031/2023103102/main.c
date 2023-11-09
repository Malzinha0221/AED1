#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"

int main() {
    TURMA *turma = criarTurma(3);

    inserirAluno(turma, 0, 1, "Alice", 20, 8.5);
    inserirAluno(turma, 1, 2, "Bob", 22, 7.8);
    inserirAluno(turma, 2, 3, "Charlie", 21, 9.2);

    printf("Informações do Aluno com Código 2:\n");
    buscarAlunoPorCodigo(turma, 2);

    imprimirCodigosENomes(turma);

    liberarTurma(turma);

    return 0;
}
