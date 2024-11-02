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
#include <stdbool.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	/*  
		Los datos Booleano (bool)
		- Representa valores de verdad: verdadero o falso.
		- Disponible desde C99 mediante el uso de `stdbool.h`.

		* Ejemplos:
			true, false

		* Tamaño:
			- Por defecto: 1 byte (8 bits)

		* Rango por defecto:
			- Valores posibles: 0 (false) y 1 (true)
	*/


	// Declaramos un booleano
	bool esVerdad = 1;

	return 0;
}