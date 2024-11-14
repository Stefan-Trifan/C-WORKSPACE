/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado X
		LoremIpsumDummyText
 */

/* 	
	#include <stdio.h>

	- El símbolo # significa que vamos a importar una librería
	- Las siglas vienen de Standard Imput Output
	- .h es el tipo de archivo
	- También incluye funciones como la suma (1+1)
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

// Función principal

int main(){

	printf("Hola Mundo\n");

	return 0;
}