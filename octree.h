#ifndef octree
#define octree

// O monitor disponibilizou a estrutura da Octree abaixo, somente modifiquei as variaveis para melhor utilizacao
// Armazena as coordenadas do ponto
typedef struct _TPonto
{
  float x, y, z; // Coordenadas em R³ do ponto
} TPonto;

// Estrutura utilizada para armazenar os atomos da proteina
typedef struct _OctreePonto
{
  TPonto posicao; // Posição da proteína no espaço de busca
} OctreePonto;

// Estrutura da Octree
typedef struct _Nodo
{
  TPonto origem; // Ponto central do cubo
  TPonto metadeAresta; // Metade das dimensões do cubo
  TPonto verticemin; // Menor vértice do cubo
  TPonto verticemax; // Maior vértice do cubo
  int nodoOuFolha; // Inteiro que indica se é um nodo interno(0) ou uma folha(1)
  OctreePonto *conteudo; // Se for uma folha este será utilizado para armazenar um atomo da proteina
  struct _Nodo *filho[8]; // Se for um nodo interno, este vetor aponta para os filhos
} Octree;

// Fim da declaracao da Octree

/**
                         ESQUEMA DA DIVISÃO DOS CUBOS EM SEUS RESPECTIVOS NOS
                          _____________________________
                         /              /             /|   
                        /  NODE 6      /   NODE 5    / |
                       /______________/_____________/  |
                      /              /             /|  |
                     /    NODE 2    /    NODE 1   / | 5|
                    /______________/_____________/  | /|
                    |              |             | 1|/ |
                    |    NODE 2    |    NODE 1   |  |  |
                    |              |             | /| 8|
                    |______________|_____________|/ | /
                    |              |             | 4|/
                    |   NODE 3     |   NODE 4    |  /
                    |              |             | /
                    |______________|_____________|/
                    
                       ROTAÇÃO DO CUBO EM 180º
                          _____________________________
                         /              /             /|
                        /   NODE 1     /   NODE 2    / |
                       /______________/_____________/  |
                      /              /             /| 2|
                     /    NODE 5    /    NODE 6   / |  |
                    /______________/_____________/  | /|
                    |              |             | 6|/ |
                    |    NODE 5    |    NODE 6   |  | 3|
                    |              |             | /|  |
                    |______________|_____________|/ | /
                    |              |             | 7|/
                    |    NODE 8    |   NODE 7    |  /
                    |              |             | /
                    |______________|_____________|/
*/

// Definicao do cubo do ligante
typedef struct _Ligante
{
  TPonto origem; // Guarda o ponto central do cubo do ligante, que é o próprio átomo do ligante
  TPonto verticemin; // Guarda o vértice mínimo do cubo do ligante
  TPonto verticemax; // Guarda o vértice máximo do cubo do ligante
  float tamanhoAresta; // Guarda o tamanho da aresta do cubo do ligante, dado na primeira linha da entrada
} TCuboLig;
// Fim da definição do cubo do ligante

Octree *plantaRaiz(); // Aloca o espaço necessário para a raiz de acordo com o tamanho necessário para a octree
void nasceFolha(Octree *Arvore); // Aloca o espaço necessário para criar os 8 filhos de um nodo na árvore
void fazMinMaxFolhas(Octree *Arvore); // Calcula os vértices mínimos e máximos, juntamente com a origem, de cada cubo filho criado
void insereProteina(float xprot, float yprot, float zprot, Octree *Arvore); // Insere a proteína dada na entrada de acordo com a localização do seu ponto na árvore
void criaCuboLigante(TCuboLig **Cubo); // Aloca o espaço necessário para o cubo que conterá o ligante
void montaCuboLigante(TCuboLig *Cubo, float arestaCubo);// Faz os cálculos necessários para achar os vértices mínimos e máximos do cubo do ligante
int verificaInteracao(TCuboLig *Cubo, Octree *Arvore); // Verifica se a proteína está no espaço delimitado pelo cubo do ligante, retornando 1 caso esteja e 0 caso não esteja
int getPointsInsideBox(TCuboLig *Cubo, Octree *Arvore); // Função que faz a chamada das funções para que se calcule o número de interações de cada átomo do ligante com os átomos da proteína e retorna um contador para a função leEntrada() para que seja armazenada o número de interações
void desintegraLigante(TCuboLig *Cubo); // Função que dá free no Tipo Abstrato de Dados Cubo que foi criado para armazenar o ligante e possibilitar os cálculos com as demais proteínas
void podaArvore(Octree *Arvore); // Função que libera os filhos da árvore, exceto a raiz, que será utilizada posteriormente para alocar outros filhos
void desmatamento(Octree *Raiz); // Função que libera a raiz da árvore ao final da execução do programa
void leEntrada(Octree *Arvore); // Função "principal" para a execução do programa. É ela que faz todos os cálculos e chama as demais funções

#endif
