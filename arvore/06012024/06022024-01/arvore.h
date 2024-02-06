#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int chave;
    struct No *esquerda;
    struct No *direita;
} No;

No *criarNo(int chave);
No *inserir(No *raiz, int chave);
void imprimirEmOrdem(No *raiz); 
int contarElementos(No *raiz);
No *buscar(No *raiz, int chave);
void imprimirPreOrdem(No *raiz);
void imprimirPosOrdem(No *raiz);

#endif