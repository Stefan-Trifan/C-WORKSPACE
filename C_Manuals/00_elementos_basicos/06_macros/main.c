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


// Ejemplos de librerías
#include <stdio.h> // Esta librería sirve para pedir y devolver datos por pantalla
#include <string.h>
#include <math.h>
#include <stdlib.h>

// También podemos definir macros (parecido a constantes)
#define PI 3.1414

int y = 5; // Variable Global

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	int x = 10; // Variable local

	// Instanciamos en 0 para reservar un espacio de memoria
	float suma = 0;

	suma = PI + x;

	// Con %.4f limitamos la salida a 2 decimales
	printf("La suma es: %.4f\n", suma);

	return 0;
}