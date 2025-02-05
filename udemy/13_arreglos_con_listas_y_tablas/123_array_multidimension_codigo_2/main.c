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
#define NUM_DIM3 2
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
    int arreglo_3D[NUM_DIM3][NUM_ROWS][NUM_COLS] = 
	{
		{
			{ 1, 2, 3},
			{ 4, 5, 6}},
		{
			{ 7, 8, 9}, 
			{10,11,12}
		}
	};

	// Pedmimos los elementos
	printf("Introduce los elementos para la matriz M(%i,%i,%i) \n", NUM_DIM3, NUM_ROWS, NUM_COLS);
	for(int h = 0; h < NUM_DIM3; h++)
	{
		for(int i = 0; i < NUM_ROWS; i++)
		{
			for(int j = 0; j < NUM_COLS; j++)
			{
				printf("M(%i,%i,%i) = ", h, i, j);
				arreglo_3D[h][i][j] = pedirEntero();
			}
		}
	}

	// Mostramos por pantalla
	printf("\n\nM(%i,%i,%i) = \n", NUM_DIM3, NUM_ROWS, NUM_COLS);
	printf("{\n");
	for(int h = 0; h < NUM_DIM3; h++)
	{
		for(int i = 0; i < NUM_ROWS; i++)
		{
			for(int j = 0; j < NUM_COLS; j++)
			{
				if(h < NUM_DIM3 - 1 || i < NUM_ROWS - 1 || j < NUM_COLS - 1)
					printf("%6d ,", arreglo_3D[h][i][j]);
				else
					printf("%6d  ", arreglo_3D[h][i][j]);
			}
			printf("\n");
		}
		if(h < NUM_DIM3 - 1)
		{
			printf("\n");
		}
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