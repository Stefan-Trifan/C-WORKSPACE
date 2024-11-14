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

		* Ejercicio C - Entero de tres cifras

		Desarrolla un programa que pida al usuario un número entero positivo de tres cifras. 
		El programa debe clasificar el número en función de sus dígitos.

		* Reglas:

		- Si el número tiene tres dígitos diferentes, debe mostrar:  
			"El número tiene tres dígitos únicos."

		- Si el número tiene dos dígitos iguales, debe mostrar:  
			"El número tiene dos dígitos iguales."

		- Si los tres dígitos son iguales, debe mostrar:  
			"El número tiene tres dígitos iguales."

		* Ejemplo de ejecución:

		$ ./digits.exe
		Introduce un número entero positivo de 3 dígitos: 100
		El número tiene dos dígitos iguales.

		$ ./digits.exe
		Introduce un número entero positivo de 3 dígitos: 123
		El número tiene tres dígitos únicos.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	int numero  = 0;
	int digito1 = 0;
	int digito2 = 0;
	int digito3 = 0;

	// Pedimos el número entero de 3 cifras
	printf("Introduce un número entero positivo de 3 dígitos: ");
	scanf("%i", &numero);
	limpiar();

	// Extraemos los 3 dígitos del número
	digito1 = numero / 100;
	digito2 = (numero / 10) % 10;
	digito3 = numero % 10;

	// Comprobamos si no hay dígitos que se repiten
	if( (digito1 != digito2) && (digito1 != digito3) && (digito2 != digito3) )
		printf("El número tiene tres dígitos únicos.\n");

	// Comprobamos si hay 2 dígitos iguales pero hay 2 dígitos diferentes
	if( ((digito1 == digito2) || (digito1 == digito3) || (digito2 == digito3)) && ((digito1 != digito2) || (digito1 != digito3) || (digito2 != digito3)))
		printf("El número tiene dos dígitos iguales.\n");

	// Comprobamos si hay 3 dígitos iguales
	if( (digito1 == digito2) && (digito1 == digito3) && (digito2 == digito3) )
		printf("El número tiene tres dígitos iguales.\n");

	return 0;
}