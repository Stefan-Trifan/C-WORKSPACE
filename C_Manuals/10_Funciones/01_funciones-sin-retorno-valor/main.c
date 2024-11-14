/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir después de scanf
		limpiar()

	* 	Enunciado X
		LoremIpsumDummyText
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){while (getchar() != '\n');}

// Declaramos/inicializamos la funcion
void Mundo();

int main()
{
	printf("\n________________________________________________\n\n");

	// Llamamos la función
	Mundo();

	printf("\n________________________________________________\n\n");
	return 0;
}

// Función
void Mundo()
{
	printf("Hola Mundo\n");
}