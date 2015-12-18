#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "octree.h"
#include "lista.h"

int main()
{
	Octree *Raiz; // Declara um ponteiro para a raiz da árvore
	Raiz = plantaRaiz(); // Aloca o espaço necessário para a raiz da árvore como primeira célula da árvore
	leEntrada(Raiz); // Função que chama todas as outras funções contida no "funcoes.c"
	desmatamento(Raiz); // Função que dá free na raiz da árvore
	return 0;
}
