
#ifndef LLD_H
#define LLD_H

// Estrutura para representar um termo do polinômio
typedef struct Termo {
    int coeficiente;
    int expoente;
    struct Termo* proximo;
} Termo;

// Estrutura para representar o polinômio como uma lista encadeada
typedef struct ListaPolinomio {
    Termo* inicio;
} ListaPolinomio;

void inicializarListaPolinomio(ListaPolinomio* lista);
void inserirTermoOrdenado(ListaPolinomio* lista, int coeficiente, int expoente);
ListaPolinomio somaPolinomios(ListaPolinomio* P1, ListaPolinomio* P2);
void imprimirPolinomio(ListaPolinomio* lista);


#endif
