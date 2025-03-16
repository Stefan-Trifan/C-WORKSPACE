/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado
		▪ Solicitar al usuario que introduzca por teclado un conjunto de números
		enteros.
		▪ Estos deben irse almacenando mientras que sean menores que el
		primero introducido.
		▪ En el momento que esta condición no se cumpla no se deben pedir más
		números al usuario y deben escribirse todos los que haya introducido
		hasta ese momento.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");



	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}