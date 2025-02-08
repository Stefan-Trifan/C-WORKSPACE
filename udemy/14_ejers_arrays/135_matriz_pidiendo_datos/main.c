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
#define ROWS 2
#define COLS 2
void calcularSuma(int mtx1[15][15], int mtx2[15][15], int mtx_result[15][15], int tam_rows, int tam_cols);
void imprimirMatriz(int mtx[15][15], int tam_rows, int tam_cols); // TODO: Ordenar por nivel de abstraccion
void crearMatriz(int mtx[15][15], int tam_rows, int tam_cols);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int my_mtx_1[15][15],
		my_mtx_2[15][15],
		my_mtx_result[15][15],
		tam_rows = 1,
		tam_cols = 1;

	// Pedimos filas y columnas
	printf("PASO 1: Introduce el tamanio de las 2 matrices\n");
	printf("Numero de filas: \n");
	tam_rows = pedirEntero();
	printf("Numero de columnas: \n");
	tam_cols = pedirEntero();
	printf("\n");

	// Creamos las matrices
	printf("PASO 2: Creamos las 2 matrices\n");
	printf("my_mtx_1: \n");
	crearMatriz(my_mtx_1, tam_rows, tam_cols);
	printf("my_mtx_2: \n");
	crearMatriz(my_mtx_2, tam_rows, tam_cols);
	
	// Imprimimos las matrices
	printf("PASO 3: Creamos las 2 matrices\n");
	printf("my_mtx_1: \n");
	imprimirMatriz(my_mtx_1, tam_rows, tam_cols);
	printf("my_mtx_2: \n");
	imprimirMatriz(my_mtx_2, tam_rows, tam_cols);
	printf("\n");

	// Calculamos la suma de las matrices
	printf("PASO 4: Calculamos la suma\n");
	printf("my_mtx_1 + my_mtx_2 = \n");
	calcularSuma(my_mtx_1, my_mtx_2, my_mtx_result, tam_rows, tam_cols);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void calcularSuma(int mtx1[15][15], int mtx2[15][15], int mtx_result[15][15], int tam_rows, int tam_cols)
{
	for(int i = 0; i < tam_rows; i++)
	{
		for(int j = 0; j < tam_cols; j++)
		{
			mtx_result[i][j] = mtx1[i][j] + mtx2[i][j];
		}
	}
	imprimirMatriz(mtx_result, tam_rows, tam_cols);
}

void imprimirMatriz(int mtx[15][15], int tam_rows, int tam_cols)
{
	for(int i = 0; i < tam_rows; i++)
	{
		for(int j = 0; j < tam_cols; j++)
		{
			printf("[%4d] ", mtx[i][j]);
		}
		printf("\n");
	}
}

void crearMatriz(int mtx[15][15], int tam_rows, int tam_cols)
{
	for(int i = 0; i < tam_rows; i++)
	{
		for(int j = 0; j < tam_cols; j++)
		{
			printf("mtx[%d][%d] ", i + 1, j + 1);
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
				"\033[1;31mERROR: El tipo de dato introducido no es válido. "
				"Por favor, inténtelo de nuevo. \n\033[0m" 
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