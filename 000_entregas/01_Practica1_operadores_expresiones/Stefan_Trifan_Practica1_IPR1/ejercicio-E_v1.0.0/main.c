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

		* Ejercicio E - Descomposición de un Número Entero de 32 Bits en Partes de 8 Bits -> ver en README.md

*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables del programa
	float parte4 = 0;
	float parte3 = 0;
	float parte2 = 0;
	float parte1 = 0;

	// Pedimos el número de 32 bits al usuario

	// Transformamos el número a binario

	// Descomponemos el número en 4 partes de 8 números

	// Imprimos cada parte en binario
	printf("Parte 4 (bits 31-24): %f\n", parte4);
	printf("Parte 3 (bits 23-16): %f\n", parte3);
	printf("Parte 2 (bits 15-08): %f\n", parte2);
	printf("Parte 1 (bits 07-00): %f\n", parte1);
		
}