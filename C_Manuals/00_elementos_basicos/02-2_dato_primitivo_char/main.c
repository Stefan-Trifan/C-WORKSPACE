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
		Los datos carácter (char)
		- Su tamaño y rango varían ligeramente según si es con signo o sin signo.

		* Ejemplos:
			'A', 'b', '1', '@', '\n' (nueva línea)

		* Tamaño:
			- Por defecto: 8 bits (1 byte) 

		* Rango por defecto:
			El valor por defecto depende del compilador
			- signed char: -128 a 127
			- unsigned char: 0 a 255
	*/


	// Declaramos un char
	char letraASCII = 67;
	printf("%c\n", letraASCII);

	char letra = 'c';
	printf("%c\n", letra);

	unsigned char myChar = 255; // Declaración de char sin signo
    printf("El valor de myChar es: %u\n", myChar); // %u para imprimir sin signo

	return 0;
}