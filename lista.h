#ifndef lista
#define lista

// Definição de uma lista duplamente encadeada para guardar o numero de interações de cada ligante e possibilitar a ordenação antes da impressão final do programa
typedef struct _ItensLista
{
  char nomeLigante[5]; // Armazena o nome do ligante
  int interacoes; // Armazena o número de interações de um ligante específico
} TItem;

typedef struct _TipoLista *Apontador; // Tipo apontador para a lista

typedef struct _TipoLista
{
  TItem ligante; // Armazena o nomeLigante e interacoes em seu interior
  Apontador Primeiro; // Apontador para a cabeça da lista
  Apontador Prox; // Apontador para a próxima célula da lista
} TLista;
//Fim da definicao da lista duplamente encadeada

void criaListaVazia(TLista **Lista); // Aloca o espaço necessário para uma lista encadeada que conterá o nome do ligante e o número de sua interação
void insereLista(char *nomeLigante, int interacoes, TLista *Lista); // Insere na lista criada o nome do ligante e o numero de sua interação
void ordenaLista(TLista *Lista, int contadorLista); // Deriva da lista encadeada um vetor das interações de todos os ligantes, de modo a ordenar esse vetor e utilizá-lo para imprimir em ordem crescente a saída do programa
void imprimeLista(TLista *Lista, int contadorLista, int *v); // Função para imprimir a lista com os nomes dos ligantes, de modo a utilizar como referência o vetor já ordenado para impressão do nome do ligante e as suas interações
void liberaLista(TLista *Lista); // Função que dá free nas demais células da lista, além de dar free na cabeça da lista

#endif
