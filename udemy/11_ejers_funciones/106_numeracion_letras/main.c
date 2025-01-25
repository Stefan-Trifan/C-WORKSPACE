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
void comprobarNumero(int num);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int num = 0;
    
    printf("Introduce un numero \n");
	num = pedirEntero();

	comprobarNumero(num);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int pedirEntero()
{
	int esValido = 1, num = 0;
	printf("-> ");
	do
	{
		esValido = scanf("%i", &num);
		clearBuffer();
		if(esValido == 0 || num < 1 || num > 5)
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

void comprobarNumero(int num)
{
	switch (num)
	{
		case 1: printf("Uno");    break;
		case 2: printf("Dos");    break;
		case 3: printf("Tres");   break;
		case 4: printf("Cuatro"); break;
		case 5: printf("Cinco");  break;
		default: break;
	}
}

void clearBuffer()
{
	while (getchar() != '\n');
}