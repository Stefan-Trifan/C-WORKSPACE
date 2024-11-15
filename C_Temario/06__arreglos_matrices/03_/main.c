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

/* _________________________________________
   Inicio cabecera del programa */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n________________________________________________START\n\n");



	printf("\n________________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definición de funciones */