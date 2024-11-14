/*
*	Autor
		Stefan Trifan

*	Compilar
		mac    : gcc main.c -o main
		windows: gcc main.c -o main.exe
			   : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado
		Escribir un código que muestre si el tercer bit (contando desde la derecha) de un número entero de 8 bits sin signo leído por terminal, es un 1 o un 0.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	unsigned char dato       = 0;
	unsigned char tercerBit  = 0;
	unsigned int  esUno      = 0;

	printf("Introduzca un número entero de 8 bits válido\n");
	scanf("%c",&dato);

	tercerBit = 1 << 2;  /* desplazar 2 posiciones el 00000001 */
						/* en tercerBit quedaría el 00000100 */

	esUno = tercerBit & dato; // hacemos un "and" bit a bit
	esUno = esUno >> 2;
	printf("El resultado del and bit a bit es:%d\n", esUno);
}