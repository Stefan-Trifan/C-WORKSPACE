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
#include <string.h>
#define TAM_ARR 5

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	char arr1[TAM_ARR],
	     arr2[TAM_ARR];

	printf("arr1: ");
	gets(arr1);
	strcpy(arr2,arr1);
	printf("arr2: %s\n", arr2);

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}