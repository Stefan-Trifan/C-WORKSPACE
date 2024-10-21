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

// Transformamos el número a binario
void printBinary(int number, int positions) {
	// Assuming a 32-bit integer
	unsigned int mask = 1 << (positions - 1); // Start with the leftmost bit
	int i = 0;
	while (i < positions) {
		// Print '1' or '0' based on the current bit
		if (number & mask) {
			printf("1");
		} else {
			printf("0");
		}
		// Shift the mask to the right by one bit
		mask >>= 1;
		i++;
	}
	printf("\n");
}

int main(){

	// Declaramos las variables del programa
	unsigned int miEntero  = 0;
	unsigned int miBinario = 0;

	unsigned int parte4 = 0;
	unsigned int parte3 = 0;
	unsigned int parte2 = 0;
	unsigned int parte1 = 0;

	// Pedimos el número de 32 bits al usuario
	printf("Ingrese un número entero de 32 bits: ");
	scanf("%u", &miEntero);
	limpiar();

	// Convertimos el número a binario
	miBinario = printBinary(miEntero, 8);

	// Descomponemos el número en 4 partes de 8 números

	// Imprimos cada parte en binario
	printf("Parte 4 (bits 31-24): %u\n", parte4);
	printf("Parte 3 (bits 23-16): %u\n", parte3);
	printf("Parte 2 (bits 15-08): %u\n", parte2);
	printf("Parte 1 (bits 07-00): %u\n", parte1);
		
}