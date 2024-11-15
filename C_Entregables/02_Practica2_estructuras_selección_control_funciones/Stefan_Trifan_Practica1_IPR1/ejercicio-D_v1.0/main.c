/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado - Suma recursiva de los dígitos impares
		Realiza un programa que utilice una función recursiva para sumar los dígitos de posición impar
		(contando como posición 1 el dígito menos significativo) de un número entero.
		El programa debe funcionar tanto para números positivos como negativos.

		Se tiene que implementar la siguiente función:
			int sumaDigitosImpares(int num){
				Función que de manera recursiva calcula la suma
				Como condición base si el número es igual a 0 la suma es 0
				La llamada recursiva se debe hacer descartando los dígitos pares
			}	
*/
/*  
	# Ejemplo de ejecución
	
	Número positivo
	Introduce un numero: 12345
	La suma es 9

	Número negativo
	Introduce un numero: 12345
	La suma es 9
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n________________________________________________START\n\n");
    
    
    
	printf("\n________________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definición de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}