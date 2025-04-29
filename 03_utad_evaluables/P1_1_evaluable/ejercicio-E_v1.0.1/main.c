/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado

		* Ejercicio E - Descomposicion de un Numero Entero de 32 Bits en Partes de 8 Bits -> ver en README.md

*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

// Transformamos el numero a binario
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

int main(int argc, char *argv[]){

	// Declaramos las variables que utilizaremos
	unsigned int miNumero = 0;
	unsigned int parte1 = 0;
	unsigned int parte2 = 0;
	unsigned int parte3 = 0;
	unsigned int parte4 = 0;


	// Pedmos el numero que vamos a transformar
	printf("Introduce el numero: ");
	scanf("%u", &miNumero);
	printf("Mi numero es: %u\n", miNumero);

	// Transofrmamos el numero a binario
	printf("Mi numero en binario es: ");
	printBinary(miNumero, 32);

	// Definimos las 4 partes del numero
	parte4 = miNumero >> 24;
	parte3 = miNumero >> 16;
	parte2 = miNumero >> 8;
	parte1 = miNumero;
	
	// Imprimimos las 4 partes por consola
	printf("La parte 4 es: ");
	printBinary(parte4, 8);

	printf("La parte 3 es: ");
	printBinary(parte3, 8);

	printf("La parte 2 es: ");
	printBinary(parte2, 8);

	printf("La parte 1 es: ");
	printBinary(parte1, 8);
	
	
	

}