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
		Los tipos de datos void

		- Es un tipo e dato especial (vacío)
		- Representa la ausencia de tipo
		- Se utiliza en funciones apra especificar que no devuelven ningun valor

		* Pseudocodigo para declarar void:
			void function(void);
	*/

	return 0;
}