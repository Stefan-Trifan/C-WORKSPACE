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
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define NUM_ROWS 2
#define NUM_COLS 3
void clearBuffer();
int pedirEntero();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
	// Inicializamos la matriz
    int arreglo[NUM_ROWS][NUM_COLS] = {0};

	// Construimos la matriz
	printf("Por favor, introduce los elementos uno por uno de la matriz M(%i,%i) \n\n", NUM_ROWS, NUM_COLS);
	for(int i = 0; i < NUM_ROWS; i++)
	{
		for(int j = 0; j < NUM_COLS; j++)
		{
			printf("M(%i,%i) = ", i + 1, j + 1);

			arreglo[i][j] = pedirEntero();
			
		}
	}

	// Imprimimos la matriz
	printf("\nM[%i][%i] = \n", NUM_ROWS, NUM_COLS);
	printf("{\n");
	for(int i = 0; i < NUM_ROWS; i++)
	{
		printf("   {");
		for(int j = 0; j < NUM_COLS; j++)
		{
			printf("%6d ", arreglo[i][j]);
			if(j < NUM_COLS - 1)
			{
				printf(",");
			}
		}
		printf("}");
		if(i < NUM_ROWS - 1)
		{
			printf(",");
		}
		printf("\n");
	}
	printf("}");

	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("Introduce un numero entero \n");
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}
