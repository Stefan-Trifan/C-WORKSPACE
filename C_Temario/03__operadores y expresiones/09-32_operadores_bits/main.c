/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado
		Define una variable tipo caracter, entera y float. 
		Asignales un valor y escribe su valor y la direccion de memoria que ocupan.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	char Caracter  = 's';
	int Entero     = 0;
	float Racional = 0.0;

	printf ("Caracter vale %c y ocupa la direccion %p \n", Caracter, &Caracter);
	printf ("Entero vale %d y ocupa la direccion %p \n", Entero, &Entero);
	printf ("Racional vale %f y ocupa la direccion %p \n", Racional, &Racional);
}