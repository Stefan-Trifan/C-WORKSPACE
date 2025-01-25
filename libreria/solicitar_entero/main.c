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
void clearBuffer();

int solicitarEntero();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int num = 0;

    printf("Introduce un numero entero \n");
    num = solicitarEntero();

    printf("Numero es: %i", num);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int solicitarEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{	
		if(esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
		}
		esValido = scanf("%i", &num);
		clearBuffer();
	} 
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}