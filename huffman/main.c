#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



int main()
{
	FILE *arquivo = fopen("teste.txt","r"); // le o arquivo
	unsigned char *array; // 
	fseek(arquivo,0,SEEK_END); //coloco o cursor para o final do arquivo
	long int tamanho = ftell(arquivo); // coloca o tamanho do arquivo em 'tamanho'
	rewind(arquivo); // volta pro inicio do arquivo

	array = (unsigned char*) malloc(tamanho * sizeof(unsigned char)); // aloca um espaço na memoria equivalente ao tamanho do arquivo

	fread(array,sizeof(unsigned char),tamanho,arquivo); // le o arquivo e grava no array

	fclose(arquivo); // fecha o arquivo

	frequencia(array,tamanho);

	return 0;
}




