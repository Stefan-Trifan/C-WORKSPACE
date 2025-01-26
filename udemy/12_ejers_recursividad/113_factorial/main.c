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
int pedirEntero();
int factorial(int num);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int num = 0, resultado = 0;
    
	printf("Introduce un numero \n");
	num = pedirEntero();

	resultado = factorial(num);

	printf("%i\n", resultado);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int factorial(int num)
{
	if(num == 0)
	{
		printf("= ");
		return 1;
	}
	else
	{	
		if(num > 1)
		{
			printf("%i * ", num);
			return num * factorial(num - 1);
		}
		else
		{
			printf("%i ", num);
			return num * factorial(num - 1);
		}

	}
		
}

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%i", &num);
		clearBuffer();
		if (esValido == 0 || num < 0)
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

void clearBuffer()
{
	while (getchar() != '\n');
}