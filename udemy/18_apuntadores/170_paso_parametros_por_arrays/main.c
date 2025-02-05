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

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_MAX 5

void llenarArray(int Array[], int dimension);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int miArray[TAM_MAX];

	llenarArray(miArray, TAM_MAX);

	// Recuerda que por defecto el array se hace con paso de parametros por referencia
	// esto nos permite editarlo desde otra funcion

	for(int i = 0; i < TAM_MAX; i++)
	{
		printf("Posicion %d valor %d\n", i, miArray[i]);
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

/**
 * Esta funcion recibe un Array y lo llena
 * No se indica el numero de indices que recibira, se hace con otra variable
 */
void llenarArray(int Array[], int dimension)
{
	for(int i = 0; i < dimension; i++)
	{
		printf("Introduce la posicion %d el array: ", i);
		scanf("%d", &Array[i]);
	}
}

void clearBuffer()
{
	while (getchar() != '\n');
}