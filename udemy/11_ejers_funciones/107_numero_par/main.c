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

void compruebaPar(int num);
int  solicitarEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int num = 0;
    num = solicitarEntero();
    compruebaPar(num);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void compruebaPar(int num)
{
	if(num % 2 == 0)
		printf("Numero es par");
	else
		printf("Numero es impar");
}

int solicitarEntero()
{
	int num = 0, esValido = 1;
	printf("Introduce un numero entero \n");
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if(esValido != 1)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
		}
	} 
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}