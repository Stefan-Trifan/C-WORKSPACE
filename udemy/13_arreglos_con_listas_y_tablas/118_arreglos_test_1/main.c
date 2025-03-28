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

/* 
	Array Unidimensional
	Es una secuencia de datos 

	Array o Arreglos Unidimensionales

	Arrays Enteros
	Arrays Flotantes
	Arrays de Caracter
	Arrays de String (Conjunto de Caracteres)

	Empiezan en el cero NUNCA EN UNO  
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define MAX_TAM 4


int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int num = 4;
    
    int array[MAX_TAM];

	for(int i = 0; i < MAX_TAM; i++)
	{	
		printf("Introduce el elemento %d del array \n", i);
		array[i] = pedirEntero();
		printf("\n");
	}

	for(int i = 0; i < MAX_TAM; i++)
	{
		printf("%d ", array[i]);
	}
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
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
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. Por favor, intentelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}