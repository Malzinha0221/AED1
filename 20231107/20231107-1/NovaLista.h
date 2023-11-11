// Definição do TDA LISTA
typedef struct {
    int *vetor;
    int tamanho;
} LISTA;

// Protótipos das funções
LISTA criarLista(int tamanho);
void liberarLista(LISTA *lista);
void inserirElemento(LISTA *lista, int elemento);
void inserirElementoOrdenado(LISTA *lista, int elemento);
void imprimirListaIterativo(LISTA lista);
int buscaBinariaRecursiva(LISTA lista, int elemento, int esquerda, int direita);
void imprimirListaRecursivo(LISTA lista, int indice);
int encontrarMaiorRecursivo(LISTA lista, int indice);
int encontrarMenorRecursivo(LISTA lista, int indice);
int calcularSomaRecursivo(LISTA lista, int indice);
int calcularProdutoRecursivo(LISTA lista, int indice);
