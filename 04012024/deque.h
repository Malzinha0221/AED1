#define MAX 10
#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
    int codigo;
    char* nome;
    char* grau;
} SOLDADO;

typedef struct aux {
    SOLDADO sol;
    struct aux* anterior;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* cabeca;
} DEQUE;

void mostrarDeque(DEQUE* d);
void inicializaDeque(DEQUE*d);
int inserir_Inicio(DEQUE* d, SOLDADO novo_soldado);
int inserir_Fim(DEQUE* d, SOLDADO novo_soldado);
int remover_inicio(DEQUE* d);
int remover_fim(DEQUE* d);
SOLDADO inicio(DEQUE* d);
SOLDADO fim(DEQUE* d);
int contar(DEQUE* d);
void vazio(DEQUE* d);
SOLDADO remover_pos(DEQUE* d, int n);


#endif // DEQUE_H
