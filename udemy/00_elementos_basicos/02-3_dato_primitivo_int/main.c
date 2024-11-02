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

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	/*  
		Los datos enteros (int) 
		- Si quiero almacenar un número mayor que 2,147,483,647 tengo que declarar otro tipo de dato

		* Ejemplos: 
			..., -2, -1, 0, 1, 2, 3, 4, 5, ...
		* Tamaño: 
			Mínimo  : 16 bits (2 bytes)
			Defecto : 32 bits (4 bytes)
		* Rango Mínimo (16 bits):
			−32,768 a 32,767
		* Rango por defecto (32 bits):
			−2,147,483,648 a 2,147,483,647
	*/

	// Declaramos un int
	// num es el identificador
	int num = 5;

	return 0;
}