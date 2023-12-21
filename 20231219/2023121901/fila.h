#define MAX_AVIAO 10
#ifndef FILA_H
#define FILA_H

struct Aviao{
    char nome[50];
    int id;
};
struct Decolagem{
    struct Aviao aviao[MAX_AVIAO];
    int inicio;
    int fim;
};
void inicioDecolagem (struct Decolagem *pista);
int PistaVazia(struct Decolagem *pista);
int PistaCheia(struct Decolagem *pista);
void EnfilerarAviao(struct Decolagem *pista, struct Aviao aviao);
void AutorizarDecolagem(struct Decolagem *pista);
void ListaAviao(struct Decolagem *pista);
void ListaPrimeiroAviao(struct Decolagem *pista);
void LiberarMemoria(struct Decolagem *pista);
#endif
