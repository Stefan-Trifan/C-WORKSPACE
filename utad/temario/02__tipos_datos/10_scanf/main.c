/*
	Autor: Stefan Trifan

	Compilar (dentro de la carpeta): gcc main.c -o main

	Enunciado: Codificar un programa que le pida al usuario que introduzca un entero y compruebe que el usuario ha introducido un entero.
*/


#include <stdio.h>

int main(){
	
	int numeroEntero, result;

	printf("Introduce un numero entero: ");
	// El & solo lo usamos en el scanf
	// scanf devuelve un 1 (si es true) o un 0 (si es false)
	// Guardamos el 0 o el 1 dentro de result
	result = scanf("%i", &numeroEntero);
	// Sacamos por pantalla
	printf("Tu numero es %i", numeroEntero);

	// Comprobamos si el numero introducido por el usuario es entero o no
	if (result != 1)
		printf("\n No es un numero entero. Adios");
	else	
		printf("\n Felicidades!! Has introducido un numero entero");
	return 0;
}