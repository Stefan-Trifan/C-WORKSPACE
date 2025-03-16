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
#define ROWS 2
#define COLS 2
void calcularSuma(int mtx1[ROWS][COLS], int mtx2[ROWS][COLS], int mtx_result[ROWS][COLS]);
void imprimirMatriz(int arreglo[ROWS][COLS]); // TODO: Ordenar por nivel de abstraccion
void crearMatriz(int arreglo[ROWS][COLS]);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int my_mtx_1[ROWS][COLS],
		my_mtx_2[ROWS][COLS],
		my_mtx_result[ROWS][COLS];

	// Creamos las matrices
	printf("my_mtx_1: \n");
	crearMatriz(my_mtx_1);
	printf("my_mtx_2: \n");
	crearMatriz(my_mtx_2);
	
	// Imprimimos las matrices
	printf("my_mtx_1: \n");
	imprimirMatriz(my_mtx_1);
	printf("my_mtx_2: \n");
	imprimirMatriz(my_mtx_2);

	// Calculamos la suma de las matrices
	printf("my_mtx_1 + my_mtx_2 = \n");
	calcularSuma(my_mtx_1, my_mtx_2, my_mtx_result);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void calcularSuma(int mtx1[ROWS][COLS], int mtx2[ROWS][COLS], int mtx_result[ROWS][COLS])
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			mtx_result[i][j] = mtx1[i][j] + mtx2[i][j];
		}
	}
	imprimirMatriz(mtx_result);
}

void imprimirMatriz(int mtx[ROWS][COLS])
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			printf("[%4d] ", mtx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void crearMatriz(int mtx[ROWS][COLS])
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			printf("mtx[%d][%d] ", i, j);
			mtx[i][j] = pedirEntero();
		}
	}
	printf("\n");
}

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. "
				"Por favor, intentelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}