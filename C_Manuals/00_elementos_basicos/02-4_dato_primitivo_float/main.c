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
		Los datos de Punto Flotante de Precisión Simple (float)
		- Ocupa menos memoria que double.
		- Un float puede representar aproximadamente 6 a 7 dígitos decimales de precisión.
		- Con números decimales grandes, como a partir del 16,777,217, pierde precisión

		* Ejemplos: 
			2.30, 3.5, -0.25
		* Tamaño: 
			- Por defecto: 32 bits (4 bytes)
		* Rango por defecto: 
			- Positivos : 1.175494e-38 a 3.402823e+38
			- Negativos : -3.402823e+38 a -1.175494e-38
	*/


	// Declaramos un float
	float num;

	return 0;
}