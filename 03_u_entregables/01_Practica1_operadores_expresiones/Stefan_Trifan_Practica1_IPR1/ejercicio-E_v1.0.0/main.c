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

	// Declaramos las variables del programa
	unsigned int miEntero  = 0;
	unsigned int parte4 = 0,  parte3 = 0, parte2 = 0, parte1 = 0;

	// Pedimos el numero de 32 bits al usuario
	printf("Ingrese un numero entero menor o igual a 4 294 967 295: ");
	scanf("%u", &miEntero);

	// Pasamos el numero de decimal a binario
	printf("El numero binario tuyo es: ");
	printBinary(miEntero, 32);

	// Descomponemos el numero en 4 partes de 8 bits
	parte4 = (miEntero >> 24) & 0xFF;  // Bits 31-24
	parte3 = (miEntero >> 16) & 0xFF;  // Bits 23-16
	parte2 = (miEntero >> 8) & 0xFF;   // Bits 15-08
	parte1 = miEntero & 0xFF;          // Bits 07-00
	

	// Imprimos cada parte en binario
	printf("Parte 4 (bits 31-24): ");
	printBinary(parte4, 8);

	printf("Parte 3 (bits 23-16): ");
	printBinary(parte3, 8);

	printf("Parte 2 (bits 15-08): ");
	printBinary(parte2, 8);
	
	printf("Parte 1 (bits 07-00): ");
	printBinary(parte1, 8);

}