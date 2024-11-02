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
		Los datos compuestos: apuntadores
		- Almacenan direcciones de memoria de otras variables
		- Se utilizan & y *
		- Se declaran utilizando el tipo de dato al que apuntan
			Ejemplo: Apuntadores a enteros, caracteres, float, boleanos, double, etc

		* Tamaño: 
			4 bytes
		
	*/

	// Declaramos un apuntador
	// a es una variable de tipo apuntador que apunta a una variable de tipo int
	int *a;

	return 0;
}