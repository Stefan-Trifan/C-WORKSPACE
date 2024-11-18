/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir despues de scanf
		limpiar()

	* 	Enunciado X
		LoremIpsumDummyText
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){while (getchar() != '\n');}

// Declaramos/inicializamos la funcion
void Mundo();

int main(){
	printf("\n________________________________________________\n\n");

	// Llamamos la funcion
	Mundo();

	printf("\n________________________________________________\n\n");
	return 0;
}

// Funcion
void Mundo()
{
	printf("Hola Mundo\n");
}