/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_TOTAL 20

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int arr_enteros[TAM_TOTAL] = {0},
		arr_pares[TAM_TOTAL]   = {0},
		arr_imapres[TAM_TOTAL] = {0},
		min                    = 1,
		max                    = 100,
		cont_pares             = 0,
		cont_impares           = 0;

	// semilla
	srand(time(NULL));

	// Rellenamos el array de numeros aleatorios
	printf("Todos los numeros: \n");
	for(int i = 0; i < TAM_TOTAL; i++)
	{
		arr_enteros[i] = min + rand() % (max - min + 1);
		printf("[%d]: %d\n", i, arr_enteros[i]);
	}
	printf("\n\n");

	for(int i = 0; i < TAM_TOTAL; i++)
	{
		if(arr_enteros[i] % 2 == 0)
		{
			arr_pares[cont_pares] = arr_enteros[i];
			cont_pares++;
		}
		else
		{
			arr_imapres[cont_impares] = arr_enteros[i];
			cont_impares++;
		}
	}

	printf("Pares: %d\n", cont_pares);
	for(int i = 0; i < cont_pares; i++)
	{
		printf("[%d]: %d\n", i, arr_pares[i]);
	}
	printf("\n\n");

	printf("Impares: %d\n", cont_impares);
	for(int i = 0; i < cont_impares; i++)
	{
		printf("[%d]: %d\n", i, arr_imapres[i]);
	}
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}