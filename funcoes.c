#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "octree.h"
#include "lista.h"

Octree *plantaRaiz() // Aloca o espaço necessário para a raiz de acordo com o tamanho necessário para a octree
{
	Octree *Arvore;
	Arvore = malloc(sizeof(Octree));
	Arvore->nodoOuFolha = 0;
	return (Arvore);
}

void nasceFolha(Octree *Arvore) // Aloca o espaço necessário para criar os 8 filhos de um nodo na árvore
{
	int i;

	Arvore->nodoOuFolha = 0;
	for(i = 0; i < 8; i++)
	{
		Arvore->filho[i] = malloc(sizeof(Octree));
		Arvore->filho[i]->nodoOuFolha = 0;
	}
}

void fazMinMaxFolhas(Octree *Arvore) // Calcula os vértices mínimos e máximos, juntamente com a origem, de cada cubo filho criado
{
	// Declaracao dos pontos minimos e maximos do filho 1
	Arvore->filho[0]->verticemin.x = Arvore->origem.x;
	Arvore->filho[0]->verticemin.y = Arvore->origem.y;
	Arvore->filho[0]->verticemin.z = Arvore->verticemin.z;
	Arvore->filho[0]->verticemax.x = Arvore->verticemax.x;
	Arvore->filho[0]->verticemax.y = Arvore->verticemax.y;
	Arvore->filho[0]->verticemax.z = Arvore->origem.z;
	Arvore->filho[0]->origem.x = (((Arvore->filho[0]->verticemin.x)+(Arvore->filho[0]->verticemax.x))/2);
	Arvore->filho[0]->origem.y = (((Arvore->filho[0]->verticemin.y)+(Arvore->filho[0]->verticemax.y))/2);
	Arvore->filho[0]->origem.z = (((Arvore->filho[0]->verticemin.z)+(Arvore->filho[0]->verticemax.z))/2);
	// Declaracao dos pontos minimos e maximos do filho 2
	Arvore->filho[1]->verticemin.x = Arvore->verticemin.x;
	Arvore->filho[1]->verticemin.y = Arvore->origem.y;
	Arvore->filho[1]->verticemin.z = Arvore->verticemin.z;
	Arvore->filho[1]->verticemax.x = Arvore->origem.x;
	Arvore->filho[1]->verticemax.y = Arvore->verticemax.y;
	Arvore->filho[1]->verticemax.z = Arvore->origem.z;
	Arvore->filho[1]->origem.x = (((Arvore->filho[1]->verticemin.x)+(Arvore->filho[1]->verticemax.x))/1);
	Arvore->filho[1]->origem.y = (((Arvore->filho[1]->verticemin.y)+(Arvore->filho[1]->verticemax.y))/1);
	Arvore->filho[1]->origem.z = (((Arvore->filho[1]->verticemin.z)+(Arvore->filho[1]->verticemax.z))/1);
	// Declaracao dos pontos minimos e maximos do filho 3
	Arvore->filho[2]->verticemin.x = Arvore->origem.x;
	Arvore->filho[2]->verticemin.y = Arvore->verticemin.y;
	Arvore->filho[2]->verticemin.z = Arvore->origem.z;
	Arvore->filho[2]->verticemax.x = Arvore->verticemax.x;
	Arvore->filho[2]->verticemax.y = Arvore->origem.y;
	Arvore->filho[2]->verticemax.z = Arvore->verticemax.z;
	Arvore->filho[2]->origem.x = (((Arvore->filho[2]->verticemin.x)+(Arvore->filho[2]->verticemax.x))/2);
	Arvore->filho[2]->origem.y = (((Arvore->filho[2]->verticemin.y)+(Arvore->filho[2]->verticemax.y))/2);
	Arvore->filho[2]->origem.z = (((Arvore->filho[2]->verticemin.z)+(Arvore->filho[2]->verticemax.z))/2);
	// Declaracao dos pontos minimos e maximos do filho 4
	Arvore->filho[3]->verticemin.x = Arvore->verticemin.x;
	Arvore->filho[3]->verticemin.y = Arvore->verticemin.y;
	Arvore->filho[3]->verticemin.z = Arvore->verticemin.z;
	Arvore->filho[3]->verticemax.x = Arvore->origem.x;
	Arvore->filho[3]->verticemax.y = Arvore->origem.y;
	Arvore->filho[3]->verticemax.z = Arvore->origem.z;
	Arvore->filho[3]->origem.x = (((Arvore->filho[3]->verticemin.x)+(Arvore->filho[3]->verticemax.x))/2);
	Arvore->filho[3]->origem.y = (((Arvore->filho[3]->verticemin.y)+(Arvore->filho[3]->verticemax.y))/2);
	Arvore->filho[3]->origem.z = (((Arvore->filho[3]->verticemin.z)+(Arvore->filho[3]->verticemax.z))/2);
	// Declaracao dos pontos minimos e maximos do filho 5
	Arvore->filho[4]->verticemin.x = Arvore->origem.x;
	Arvore->filho[4]->verticemin.y = Arvore->verticemin.y;
	Arvore->filho[4]->verticemin.z = Arvore->verticemin.z;
	Arvore->filho[4]->verticemax.x = Arvore->verticemax.x;
	Arvore->filho[4]->verticemax.y = Arvore->origem.y;
	Arvore->filho[4]->verticemax.z = Arvore->origem.z;
	Arvore->filho[4]->origem.x = (((Arvore->filho[4]->verticemin.x)+(Arvore->filho[4]->verticemax.x))/2);
	Arvore->filho[4]->origem.y = (((Arvore->filho[4]->verticemin.y)+(Arvore->filho[4]->verticemax.y))/2);
	Arvore->filho[4]->origem.z = (((Arvore->filho[4]->verticemin.z)+(Arvore->filho[4]->verticemax.z))/2);
	// Declaracao dos pontos minimos e maximos do filho 6
	Arvore->filho[5]->verticemin.x = Arvore->origem.x;
	Arvore->filho[5]->verticemin.y = Arvore->origem.y;
	Arvore->filho[5]->verticemin.z = Arvore->origem.z;
	Arvore->filho[5]->verticemax.x = Arvore->verticemax.x;
	Arvore->filho[5]->verticemax.y = Arvore->verticemax.y;
	Arvore->filho[5]->verticemax.z = Arvore->verticemax.z;
	Arvore->filho[5]->origem.x = (((Arvore->filho[5]->verticemin.x)+(Arvore->filho[5]->verticemax.x))/2);
	Arvore->filho[5]->origem.y = (((Arvore->filho[5]->verticemin.y)+(Arvore->filho[5]->verticemax.y))/2);
	Arvore->filho[5]->origem.z = (((Arvore->filho[5]->verticemin.z)+(Arvore->filho[5]->verticemax.z))/2);
	// Declaracao dos pontos minimos e maximos do filho 7
	Arvore->filho[6]->verticemin.x = Arvore->verticemin.x;
	Arvore->filho[6]->verticemin.y = Arvore->origem.y;
	Arvore->filho[6]->verticemin.z = Arvore->origem.z;
	Arvore->filho[6]->verticemax.x = Arvore->origem.x;
	Arvore->filho[6]->verticemax.y = Arvore->verticemax.y;
	Arvore->filho[6]->verticemax.z = Arvore->verticemax.z;
	Arvore->filho[6]->origem.x = (((Arvore->filho[6]->verticemin.x)+(Arvore->filho[6]->verticemax.x))/2);
	Arvore->filho[6]->origem.y = (((Arvore->filho[6]->verticemin.y)+(Arvore->filho[6]->verticemax.y))/2);
	Arvore->filho[6]->origem.z = (((Arvore->filho[6]->verticemin.z)+(Arvore->filho[6]->verticemax.z))/2);
	// Declaracao dos pontos minimos e maximos do filho 8
	Arvore->filho[7]->verticemin.x = Arvore->verticemin.x;
	Arvore->filho[7]->verticemin.y = Arvore->verticemin.y;
	Arvore->filho[7]->verticemin.z = Arvore->origem.z;
	Arvore->filho[7]->verticemax.x = Arvore->origem.x;
	Arvore->filho[7]->verticemax.y = Arvore->origem.y;
	Arvore->filho[7]->verticemax.z = Arvore->verticemax.z;
	Arvore->filho[7]->origem.x = (((Arvore->filho[7]->verticemin.x)+(Arvore->filho[7]->verticemax.x))/2);
	Arvore->filho[7]->origem.y = (((Arvore->filho[7]->verticemin.y)+(Arvore->filho[7]->verticemax.y))/2);
	Arvore->filho[7]->origem.z = (((Arvore->filho[7]->verticemin.z)+(Arvore->filho[7]->verticemax.z))/2);

}

void insereProteina(float xprot, float yprot, float zprot, Octree *Arvore) // Insere a proteína dada na entrada de acordo com a localização do seu ponto na árvore
{
	int i;

	for (i = 0; i < 8; i++)
	{
		if (xprot >= Arvore->filho[i]->verticemin.x && xprot <= Arvore->filho[i]->verticemax.x && yprot >= Arvore->filho[i]->verticemin.y && yprot <= Arvore->filho[i]->verticemax.y && zprot >= Arvore->filho[i]->verticemin.z && zprot <= Arvore->filho[i]->verticemax.z) // Verifica em que quadrante a proteína irá se alocar
		{
			if (Arvore->filho[i]->nodoOuFolha == 0 && Arvore->filho[i]->filho[i] == NULL) // Se o filho da célula atual da árvore for definida como um nodo(0) e o filho desse nodo for NULL, aloca espaço para a proteina ficar nesse nodo
			{
				Arvore->filho[i]->conteudo = malloc(sizeof(OctreePonto));
				Arvore->filho[i]->conteudo->posicao.x = xprot;
				Arvore->filho[i]->conteudo->posicao.y = yprot;
				Arvore->filho[i]->conteudo->posicao.z = zprot;
				Arvore->filho[i]->nodoOuFolha = 1;
				break;
			}

			else if (Arvore->filho[i]->nodoOuFolha == 0 && Arvore->filho[i]->filho[i] != NULL) // Se o filho da célula atual da árvore for definida como um nodo(0), mas o filho desse nodo não for NULL, chama recursivamente essa função para buscar aonde a proteína será alocada
			{
				insereProteina(xprot, yprot, zprot, Arvore->filho[i]);
				break;
			}

			else if (Arvore->filho[i]->nodoOuFolha == 1) // Se o filho da célula atual da árvore for definida como uma folha(1), ou seja, que já contem uma proteína, cria mais 8 filhos dessa célula atual, calcula os mínimos e os máximos desses cubos e realoca a proteína que estava anteriormente em algum dos novos filhos e aloca a proteína da entrada atual em algum dos novos filhos também
			{				
				nasceFolha(Arvore->filho[i]);
				fazMinMaxFolhas(Arvore->filho[i]);
				insereProteina(Arvore->filho[i]->conteudo->posicao.x, Arvore->filho[i]->conteudo->posicao.y, Arvore->filho[i]->conteudo->posicao.z, Arvore->filho[i]);
				Arvore->filho[i]->nodoOuFolha = 0;
				insereProteina(xprot, yprot, zprot, Arvore->filho[i]);
				break;
			}
		}
	}
}

void criaCuboLigante(TCuboLig **Cubo) // Aloca o espaço necessário para o cubo que conterá o ligante
{
	(*Cubo) = malloc(sizeof(TCuboLig));
}

void montaCuboLigante(TCuboLig *Cubo, float arestaCubo) // Faz os cálculos necessários para achar os vértices mínimos e máximos do cubo do ligante
{
	Cubo->verticemin.x = Cubo->origem.x - (arestaCubo/2);
	Cubo->verticemin.y = Cubo->origem.y - (arestaCubo/2);
	Cubo->verticemin.z = Cubo->origem.z - (arestaCubo/2);
	Cubo->verticemax.x = Cubo->origem.x + (arestaCubo/2);
	Cubo->verticemax.y = Cubo->origem.y + (arestaCubo/2);
	Cubo->verticemax.z = Cubo->origem.z + (arestaCubo/2);
}

int verificaInteracao(TCuboLig *Cubo, Octree *Arvore) // Verifica se a proteína está no espaço delimitado pelo cubo do ligante, retornando 1 caso esteja e 0 caso não esteja
{
	if (Cubo->verticemin.x <= Arvore->conteudo->posicao.x && Cubo->verticemax.x >= Arvore->conteudo->posicao.x && Cubo->verticemin.y <= Arvore->conteudo->posicao.y && Cubo->verticemax.y >= Arvore->conteudo->posicao.y && Cubo->verticemin.z <= Arvore->conteudo->posicao.z && Cubo->verticemax.z >= Arvore->conteudo->posicao.z)
		return 1;
	else
		return 0;
}

int getPointsInsideBox(TCuboLig *Cubo, Octree *Arvore) // Função que faz a chamada das funções para que se calcule o número de interações de cada átomo do ligante com os átomos da proteína
{
	int i, contador = 0;

	for (i = 0; i < 8; i++)
	{
		if (Arvore->filho[i]->nodoOuFolha == 1) // Caso seja uma folha, chama a função de verificar a interação do ligante com aquela proteína
			contador += verificaInteracao(Cubo, Arvore->filho[i]);
		else if (Arvore->filho[i]->nodoOuFolha == 0) // Caso seja um nodo e tenha filhos, chama recursivamente essa função avançando para os filhos desse nodo
		{
			if (Arvore->filho[i]->filho[i] != NULL)
				contador += getPointsInsideBox(Cubo, Arvore->filho[i]);
		}
	}
	return contador; // Retorna um contador para a função leEntrada() para que seja armazenada o número de interações
}

void criaListaVazia(TLista **Lista) // Aloca o espaço necessário para uma lista encadeada que conterá o nome do ligante e o número de sua interação
{
	(*Lista) = malloc(sizeof(TLista));
	(*Lista)->Primeiro = malloc(sizeof(TLista));
	(*Lista)->Primeiro->Prox = NULL;
}

void insereLista(char *nomeLigante, int interacoes, TLista *Lista) // Insere na lista criada o nome do ligante e o numero de sua interação
{
	int i;
	if(Lista->Prox != NULL)
		insereLista(nomeLigante, interacoes, Lista->Prox);
	else
	{
		Lista->Prox = malloc(sizeof(TLista));
		for(i = 0; i <= 5; i++)
			Lista->Prox->ligante.nomeLigante[i] = nomeLigante[i];
		Lista->Prox->ligante.interacoes = interacoes;
		Lista->Prox->Prox = NULL;
	}
}

void ordenaLista(TLista *Lista, int contadorLista) // Deriva da lista encadeada um vetor das interações de todos os ligantes, de modo a ordenar esse vetor e utilizá-lo para imprimir em ordem crescente a saída do programa
{
	int i, *v;
	v = calloc(contadorLista, sizeof(int)); // Aloca o espaço necessário para essa lista de acordo com o número de ligantes contados na função leEntrada()
	Apontador p;

	p = Lista->Prox;
	i = 0;
	while(p != NULL && i < contadorLista) // Copia o número de interações para um vetor previamente alocado dinamicamente
	{
		v[i] = p->ligante.interacoes;
		p = p->Prox;
		i++;
	}

	// Início da ordenação no vetor pelo Método da Bolha : Foi escolhido esse método por ele ser de fácil implementação e ser um método muito utilizado para saídas menores
	int j, k, aux;
	for( j = 0 ; j < contadorLista-1 ; j++ )
	{
		for( k = 1 ; k < contadorLista-j ; k++ )
		{
			if ( v[k] < v[k-1] ) // Verifica se dois itens consecutivos tem diferença de tamanho, tal que o item k deve ser menor que o k-1. Com isso se troca a posição dos dois.
			{
				aux = v[k];
				v[k] = v[k-1];
				v[k-1] = aux;
			}
		}
	}
	// Fim da ordenação no vetor pelo Método da Bolha
	imprimeLista(Lista, contadorLista, v); // Chama a função que irá verificar a ordem do vetor e imprimir a saída
	free(v); // Libera o vetor utilizado para a ordenação e impressão da lista
}

void imprimeLista(TLista *Lista, int contadorLista, int *v) // Função para imprimir a lista com os nomes dos ligantes, de modo a utilizar como referência o vetor já ordenado para impressão do nome do ligante e as suas interações
{
	Apontador p;
	int i;

	for(i = 0; i < contadorLista; i++)
	{
		for(p = Lista->Prox; p != NULL; p = p->Prox)
		{
			if(v[i] == p->ligante.interacoes) // Usa o vetor ordenado para imprimir a saída na ordem certa
				printf("%s %d\n", p->ligante.nomeLigante, p->ligante.interacoes);
		}
	}
}

void liberaLista(TLista *Lista) // Função que dá free nas demais células da lista, além de dar free na cabeça da lista
{
	if (Lista->Prox != NULL)
	{
		liberaLista(Lista->Prox);
		free(Lista->Prox);
	}
}

void desintegraLigante(TCuboLig *Cubo) // Função que dá free no Tipo Abstrato de Dados Cubo que foi criado para armazenar o ligante e possibilitar os cálculos com as demais proteínas
{
	free(Cubo);
}

void podaArvore(Octree *Arvore) // Função que libera os filhos da árvore, exceto a raiz, que será utilizada posteriormente para alocar outros filhos
{
	int i;

	if (Arvore->nodoOuFolha == 1) // Se for folha, já libera essa folha e retorna
	{
		free(Arvore);
		return;
	}

	// Chamada recursiva para dar free em todos os filhos da árvore
	for (i = 0; i < 8; i++){
		if (Arvore->filho[i] != NULL)
			podaArvore(Arvore->filho[i]);
	}
}

void desmatamento(Octree *Raiz) // Função que libera a raiz da árvore ao final da execução do programa
{
	free(Raiz);
}

void leEntrada(Octree *Arvore) // Função "principal" para a execução do programa. É ela que faz todos os cálculos e chama as demais funções
{
	TCuboLig *CuboLigante; // Ponteiro para o TAD CuboLigante, que será usado para guardar um "cubo contendo o atual ligante" e será utilizado para o cálculo das interações
	TLista *Lista; // Ponteiro para o TAD Lista, que será usado para guardar uma lista encadeada com os nomes dos ligantes e suas respectivas interações
	criaListaVazia(&Lista); // Cria a lista que será usada para armazenar os nomes dos ligantes e suas respectivas interações, para imprimí-los depois
	float compArestaCubo; // Guarda o comprimento da aresta do cubo do ligante (1ª linha da entrada)
	char nNome[15], nomeLigante[5], nada[50];
	/*  
	* nNome[15] : Guarda a primeira palavra da entrada, que será chave para a execução das partes do programa
	* nomeLigante[5] : Guarda o nome do ligante em questão (2ª linha da entrada)
	* nada[50] : Variável usada para guardar as partes da entrada que não serão utilizadas em nada no programa
	*/
	float xprot, yprot, zprot; // Guarda a entrada das posições x, y e z da proteína
	int interacoes, contadorLista = 0; // Contadores do numero de interações e de quantos ligantes a lista terá
	
	scanf("%f", &compArestaCubo);
	
	while(1) // Loop de leitura da entrada
	{
		scanf("%s", nNome);
		if(strcmp(nNome, "-1") == 0) // Compara se a primeira palavra da linha atual da entrada é -1, para inserir na lista o último ligante e dar break no loop de entrada
		{
			insereLista(nomeLigante, interacoes, Lista->Primeiro);
			break;
		}

		else if(strcmp(nNome, "Nome:") == 0) // Compara se a primeira palavra da linha atual da entrada é Nome:
		{
			insereLista(nomeLigante, interacoes, Lista->Primeiro);
			contadorLista++;
			interacoes = 0;
			scanf("%s", nomeLigante);
			scanf("%f %f %f %f %f %f", &Arvore->verticemin.x, &Arvore->verticemin.y, &Arvore->verticemin.z, &Arvore->verticemax.x, &Arvore->verticemax.y, &Arvore->verticemax.z);
			Arvore->origem.x = (((Arvore->verticemin.x)+(Arvore->verticemax.x))/2);
			Arvore->origem.y = (((Arvore->verticemin.y)+(Arvore->verticemax.y))/2);
			Arvore->origem.z = (((Arvore->verticemin.z)+(Arvore->verticemax.z))/2);
			Arvore->metadeAresta.x = Arvore->origem.x;
			Arvore->metadeAresta.y = Arvore->origem.y;
			Arvore->metadeAresta.z = Arvore->origem.z;
			nasceFolha(Arvore);
			fazMinMaxFolhas(Arvore);
		}

		else if(strcmp(nNome, "PROTEINA") == 0)
		{
			scanf("%s %f %f %f", nada, &xprot, &yprot, &zprot);
			insereProteina(xprot, yprot, zprot, Arvore);
		}
		else if(strcmp(nNome, "LIGANTE") == 0)
		{
			criaCuboLigante(&CuboLigante);
			scanf("%s %f %f %f", nada, &CuboLigante->origem.x, &CuboLigante->origem.y, &CuboLigante->origem.z);
			montaCuboLigante(CuboLigante, compArestaCubo);
			interacoes += getPointsInsideBox(CuboLigante, Arvore);
			desintegraLigante(CuboLigante);
		}
	}
	ordenaLista(Lista->Primeiro->Prox, contadorLista); // Chama a função para ordenar a lista
	liberaLista(Lista->Primeiro); // Libera as células da lista dos ligantes e as suas interações
	free(Lista); // Libera o espaço alocado para o ponteiro para a lista utilizada para guardar os ligantes e as suas interações
}
