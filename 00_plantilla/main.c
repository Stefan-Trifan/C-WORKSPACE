/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
				  ./main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado X
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n________________________________________________START\n\n");
    
    
    
	printf("\n________________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definición de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}