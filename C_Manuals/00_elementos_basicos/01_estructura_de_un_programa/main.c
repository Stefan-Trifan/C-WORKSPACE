/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado X
		LoremIpsumDummyText
*/

/* 	
	#include <stdio.h>

	- El simbolo # significa que vamos a importar una libreria
	- Las siglas vienen de Standard Imput Output
	- .h es el tipo de archivo
	- Tambien incluye funciones como la suma (1+1)
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

// Funcion principal

int main(){

	printf("Hola Mundo\n");

	return 0;
}