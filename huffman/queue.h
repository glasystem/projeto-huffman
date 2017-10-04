#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef fila_h
#define fila_h


typedef struct _no_h no_h;

typedef struct _fila fila;

struct _no_h
{
	long int frequency;
	void *item;
	no_h *proximo;
	no_h *esquerda;
	no_h *direita;
};

struct _fila
{
	no_h *first;
	no_h *last;
	int size;
};

// Aloca um nó e retorna um nó
no_h* cria_no(unsigned char item,long int size, no_h* esquerda,no_h* direita);

// cria uma fila 
fila* criar_fila();

// Verifica se a fila esta vazia
int esta_vazia(fila *n_fila);

// Enfileira no fim da fila 
void enfileirar_fim( fila *n_fila, unsigned char item);

// Enfileira e ordena a fila 
void enfileirar_ordenado(fila *fila, no_h* newNode);

// Desenfileira um objeto da fila 
unsigned char desenfileirar(fila *n_fila);

no_h* cria_arvore(fila* n_fila);

no_h* frequencia(unsigned char *arquivo, long int tamanho);


#endif //fila_h
