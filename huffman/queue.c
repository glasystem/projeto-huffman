#include "queue.h"

no_h* cria_no(unsigned char item,long int size, no_h* esquerda,no_h* direita)
{
    unsigned char n = item;
	no_h *aux = (no_h*) malloc(sizeof(no_h));
	aux->item = (unsigned char*)malloc(sizeof(unsigned char));
    aux->item = &n;
	aux->frequency = size;
	aux->esquerda = esquerda;
	aux->direita = direita;
    aux->proximo = NULL;
	return aux;
}

fila* criar_fila()
{
    fila *aux = (fila*) malloc(sizeof(fila));
    aux -> first = NULL;
    aux->last = NULL;
    aux -> size = 0;
    return aux;
}   

int esta_vazia(fila *n_fila)
{
	return (n_fila->size == 0);
}

void enfileirar_fim( fila *n_fila, unsigned char item)
{
    n_fila->size++;
    no_h *newNode = cria_no(item,0,NULL,NULL);
    if ( n_fila->first == NULL)
    {
        n_fila->first = newNode;
        n_fila->last = newNode;
    }

    else
    {
        n_fila->last->proximo = newNode;
        n_fila->last = newNode;
    }
}

void enfileirar_ordenado(fila *fila, no_h* newNode)
{
    if(esta_vazia(fila))
    {
        fila -> first = newNode;
        newNode-> proximo = NULL;
    }
    else if(newNode->frequency <= fila -> first->frequency )
    {
        newNode -> proximo = fila -> first;
        fila -> first = newNode;
    }
    else
    {
        no_h *antecessor, *atual =  fila->first;
        while(atual != NULL && newNode->frequency > atual->frequency );
        {
            antecessor =atual;
           atual =atual->proximo;
        }

        newNode->proximo =atual;
        antecessor->proximo = newNode;
    }
    fila->size ++;
}

unsigned char desenfileirar(fila *n_fila)
{
    no_h *aux = n_fila->first;
    n_fila->first = aux->proximo;
    unsigned char a = *(unsigned char*)aux->item;
    free(aux);
    n_fila->size--;
    return a;
}

no_h* cria_arvore(fila* n_fila)
{
    while(n_fila->size > 1)
    {
        no_h *esquerda = n_fila->first;
        no_h *direita = esquerda->proximo;
        n_fila->first = direita->proximo;
        enfileirar_ordenado(n_fila,cria_no('*',esquerda->frequency+direita->frequency, esquerda,direita));
        n_fila->size -= 2;
    }
    return n_fila->first;
}

no_h* frequencia(unsigned char *arquivo, long int tamanho)
{
    long int *array = (long int*) malloc(256 * sizeof(long int));
    long int i;
    fila* fila = criar_fila();
    for(i = 0; i < 256; i++) array[i] = 0;

    for(i = 0; i < tamanho; i++) array[arquivo[i]] ++;

    for(i = 0; i < 256; i++) 
    {
        if(array[i] > 0) enfileirar_ordenado(fila,cria_no(i,array[i],NULL,NULL));
    }

  return cria_arvore(fila);
}



