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
#define NUM_ROWS 2
#define NUM_COLS 1

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	// Inicializamos la matriz
    int matriz[NUM_ROWS][NUM_COLS] = {0};

	// Construimos la matriz
	for(int row = 0; row < NUM_ROWS; row++)
	{
		for(int col = 0; col < NUM_COLS; col++)
		{
			printf("M(%d,%d) = ", row + 1, col + 1);
			scanf("%6d", &matriz[row][col]);
		}
	}

	// Imprimimoos la matriz
	for(int row = 0; row < NUM_ROWS; row++)
	{
		for(int col = 0; col < NUM_COLS; col++)
		{
			printf("%6d ", matriz[row][col]);
		}
		printf("\n");
	}

	
	// Sumamos los elementos de la primera fila
	int sumaPrimeraFila = 0;
	for(int row = 0; row < 1; row++)
	{
		for(int col = 0; col < NUM_COLS; col++)
		{
			sumaPrimeraFila += matriz[row][col];
			
		}
	}
	printf("El resultado es: %d \n", sumaPrimeraFila);
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}