/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    // int pares[TAM] = {0};

	int *p_pares = (int*)malloc(sizeof(int) * TAM);

	for(int i = 0; i < TAM; i++)
	{
		*(p_pares + i) = i * 2;
	}

	for(int i = 0; i < TAM; i++)
	{
		printf("Numero %d: %d\n", i, p_pares[i]);
	}

	free(p_pares);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}