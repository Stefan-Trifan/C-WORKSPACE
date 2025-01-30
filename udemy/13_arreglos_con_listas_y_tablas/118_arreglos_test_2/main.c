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

int main()
{
	printf("\n_________________________________________START\n\n");

	char a[20];

	printf("Escribe tu nombre\n");
	gets(a);
	printf("Tu nombre es: %s", a);
    
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
	printf("-> ");
	do
	{
		esValido = scanf("%i", &num);
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