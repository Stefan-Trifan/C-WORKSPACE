/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado
		Pide un número por pantalla, cuenta los caracteres que tiene y devuelve el resultado
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	int numero = 0;
	int caracteres = 0;

	// Pedimos el número
	printf("Introduce un número del 0 al 999999999\n");
	scanf("%i", &numero);

	while( numero > 0 ){
		numero = numero / 10;
		caracteres = caracteres + 1;
	}

	printf("El número de caracteres es %i", caracteres);
}