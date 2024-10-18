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

		* Ejercicio E - Descomposición de un Número Entero de 32 Bits en Partes de 8 Bits

		Escribe un programa en **C** que solicite al usuario un número entero de 32 bits y luego imprima las cuatro partes de 8 bits de ese número. El programa debe utilizar desplazamientos de bits y operaciones AND para extraer y mostrar cada parte de 8 bits por separado. Usa la función printBinary proporcionada para imprimir cada parte en binario.

		* Requisitos:
		1. Solicitar al usuario que ingrese un número entero de 32 bits.
		2. Descomponer el número en cuatro partes de 8 bits utilizando desplazamientos de bits y operaciones AND.
		3. Usar la función `printBinary` para imprimir cada parte en binario.

		* Función Proporcionada:
		
		Asignar 8 al parámetro positions, si se desean mostrar los 8
		bits menos significativos. Asignar 32 si se desea ver el número
		de 32 bits completo.
		
		void printBinary(int number, int positions) {
			/// Asumiendo un entero de 32 bits
			unsigned int mask = 1 << (positions - 1); /// Start with the leftmost bit
			int i = 0;
			while (i < positions) {
				/// Print '1' or '0' based on the current bit
				if (number & mask) {
					printf("1");
				} else {
					printf("0");
				}
				/// Shift the mask to the right by one bit
				mask >>= 1;
				i++;
			}
			printf("\n");
		}

		* Ejemplo de Ejecución:

		* Entrada:

		Ingrese un número entero de 32 bits: 305419896

		* Salida:

		Parte 1 (bits 31-24): 00010010
		Parte 2 (bits 23-16): 00101100
		Parte 3 (bits 15-8): 01001101
		Parte 4 (bits 7-0): 01101000

 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

}