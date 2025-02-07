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
// #DEFINE NUM_ROW 2
// #DEFINE NUM_COL 2
void crearMatriz(int arreglo[]);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int matriz1[2][2],
		matriz2[2][2],
		matriz_resultado[2][2];

	// Creamos las matrices
	// Posteriormente moverlas a funcion aparte
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("matriz1[%d][%d] ", i, j);
			matriz1[i][j] = pedirEntero();
		}
	}
	printf("\n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("matriz2[%d][%d] ", i, j);
			matriz2[i][j] = pedirEntero();
		}
	}
	printf("\n");
	
	// Imprimimos las matrices
	printf("matriz1\n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("[%d] ", matriz1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("matriz2\n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("[%d] ", matriz2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// Calculamos la suma de las matrices
	printf("matriz1 + matriz2 = \n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			matriz_resultado[i][j] = matriz1[i][j] + matriz2[i][j];
			printf("[%d] ", matriz_resultado[i][j]);
		}
		printf("\n");
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void crearMatriz(int arreglo[])
{
	
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