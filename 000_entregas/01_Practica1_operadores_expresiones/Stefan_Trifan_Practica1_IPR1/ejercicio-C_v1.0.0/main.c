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

		Desarrolla un programa que pida al usuario un número entero positivo de tres cifras. El programa debe clasificar el número en función de sus dígitos.

		* Reglas:
		- Si el número tiene **tres dígitos diferentes**, debe mostrar:  
		`"El número tiene tres dígitos únicos."`
		- Si el número tiene **dos dígitos iguales**, debe mostrar:  
		`"El número tiene dos dígitos iguales."`
		- Si los **tres dígitos son iguales**, debe mostrar:  
		`"El número tiene tres dígitos iguales."`

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

}