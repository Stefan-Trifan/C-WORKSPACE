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

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	/*  
		Los datos Punto Flotante Precision Doble (double)
		- Ocupa mas memoria
		- Un double puede representar aproximadamente 15 a 17 digitos decimales de precision.

		* Ejemplos: 
			234343.3043
		* Tamaño: 
			- Por defecto : 64 bits (8 bytes)
		* Rango por Defecto: 
			- Positivos : 2.225074e-308 a 1.797693e+308
			- Negativos : -1.797693e+308 a -2.225074e-308
	*/

	// Declaramos un double
	double num;

	return 0;
}