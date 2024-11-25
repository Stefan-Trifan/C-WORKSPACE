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

		* Ejercicio C - Entero de tres cifras

		Desarrolla un programa que pida al usuario un numero entero positivo de tres cifras. 
		El programa debe clasificar el numero en funcion de sus digitos.

		* Reglas:

		- Si el numero tiene tres digitos diferentes, debe mostrar:  
			"El numero tiene tres digitos unicos."

		- Si el numero tiene dos digitos iguales, debe mostrar:  
			"El numero tiene dos digitos iguales."

		- Si los tres digitos son iguales, debe mostrar:  
			"El numero tiene tres digitos iguales."

		* Ejemplo de ejecucion:

		$ ./digits.exe
		Introduce un numero entero positivo de 3 digitos: 100
		El numero tiene dos digitos iguales.

		$ ./digits.exe
		Introduce un numero entero positivo de 3 digitos: 123
		El numero tiene tres digitos unicos.
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

	// Pedimos el numero entero de 3 cifras
	printf("Introduce un numero entero positivo de 3 digitos: ");
	scanf("%i", &numero);
	limpiar();

	// Extraemos los 3 digitos del numero
	digito1 = numero / 100;
	digito2 = (numero / 10) % 10;
	digito3 = numero % 10;

	// Comprobamos si no hay digitos que se repiten
	if( (digito1 != digito2) && (digito1 != digito3) && (digito2 != digito3) )
		printf("El numero tiene tres digitos unicos.\n");

	// Comprobamos si hay 2 digitos iguales pero hay 2 digitos diferentes
	if( ((digito1 == digito2) || (digito1 == digito3) || (digito2 == digito3)) && ((digito1 != digito2) || (digito1 != digito3) || (digito2 != digito3)))
		printf("El numero tiene dos digitos iguales.\n");

	// Comprobamos si hay 3 digitos iguales
	if( (digito1 == digito2) && (digito1 == digito3) && (digito2 == digito3) )
		printf("El numero tiene tres digitos iguales.\n");

	return 0;
}