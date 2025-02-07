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
#define NUM_ROW 2
#define NUM_COL 2
void calcularSuma(int matriz1[NUM_ROW][NUM_COL], int matriz2[NUM_ROW][NUM_COL], int mi_matriz_resultado[NUM_ROW][NUM_COL]);
void imprimirMatriz(int arreglo[NUM_ROW][NUM_COL]); // TODO: Ordenar por nivel de abstraccion
void crearMatriz(int arreglo[NUM_ROW][NUM_COL]);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int mi_matriz_1[NUM_ROW][NUM_COL],
		mi_matriz_2[NUM_ROW][NUM_COL],
		mi_matriz_resultado[NUM_ROW][NUM_COL];

	// Creamos las matrices
	printf("mi_matriz_1: \n");
	crearMatriz(mi_matriz_1);
	printf("mi_matriz_2: \n");
	crearMatriz(mi_matriz_2);
	
	// Imprimimos las matrices
	printf("mi_matriz_1: \n");
	imprimirMatriz(mi_matriz_1);
	printf("mi_matriz_2: \n");
	imprimirMatriz(mi_matriz_2);

	// Calculamos la suma de las matrices
	printf("mi_matriz_1 + mi_matriz_2 = \n");
	calcularSuma(mi_matriz_1, mi_matriz_2, mi_matriz_resultado);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void calcularSuma(int matriz1[NUM_ROW][NUM_COL], int matriz2[NUM_ROW][NUM_COL], int matriz_resultado[NUM_ROW][NUM_COL])
{
	for(int i = 0; i < NUM_ROW; i++)
	{
		for(int j = 0; j < NUM_COL; j++)
		{
			matriz_resultado[i][j] = matriz1[i][j] + matriz2[i][j];
		}
	}
	imprimirMatriz(matriz_resultado);
}

void imprimirMatriz(int matriz[NUM_ROW][NUM_COL])
{
	for(int i = 0; i < NUM_ROW; i++)
	{
		for(int j = 0; j < NUM_COL; j++)
		{
			printf("[%4d] ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void crearMatriz(int matriz[NUM_ROW][NUM_COL])
{
	for(int i = 0; i < NUM_ROW; i++)
	{
		for(int j = 0; j < NUM_COL; j++)
		{
			printf("matriz[%d][%d] ", i, j);
			matriz[i][j] = pedirEntero();
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