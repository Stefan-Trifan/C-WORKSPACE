/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado X
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 20

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
	char nombre[TAM];
	char apellido[TAM];
    
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}