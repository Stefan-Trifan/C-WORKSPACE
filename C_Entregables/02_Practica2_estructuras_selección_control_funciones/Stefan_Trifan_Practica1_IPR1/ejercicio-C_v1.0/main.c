/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir después de scanf
		limpiar()

	* 	Enunciado - Calculadora de Potencia con Validación de Exponente
		El objetivo de este ejercicio es crear un programa que calcule la potencia de un número entero
		elevado a un exponente entero positivo. El programa debe solicitar al usuario un número base
		y un exponente, y mostrar el resultado solo si el exponente es positivo.
		
		Normas:
			1. La función calcular_potencia debe realizar la validación del exponente para
			asegurarse de que sea positivo.
			2. Si el exponente es positivo, calcular_potencia realiza el cálculo de la potencia y
			retornar 1 para indicar que la operación fue exitosa. El resultado debe almacenarse en
			el puntero *resultado.
			3. Si el exponente no es positivo, calcular_potencia debe retornar 0.
			4. La función principal deberá mostrar el resultado o un mensaje de error en función del
			valor retornado por calcular_potencia.

		Condiciones:
			1. Si el cálculo se realiza correctamente, el programa debe mostrar el resultado de la potencia.
			2. Si el exponente es menor o igual a 0, el programa debe mostrar un mensaje de error: "Error: el exponente debe ser positivo”.

		Se tiene que implementar la siguiente función:
			int calcular_potencia(int base, int exponente, int *resultado){
				1. Calcula la potencia de la base elevada al exponente usando un bucle y asigna el resultado a la variable resultado.
				2. Valida si el exponente es positivo. Devuelve un 1 si el cálculo se realiza correctamente o un 0 si el exponente no es positivo
			}
*/
/* 
	# Ejemplo de ejecución

	Caso correcto:
		Ingrese la base: 3
		Ingrese el exponente: 4
		Resultado: 81

	Caso incorrecto:
		Ingrese la base: 3
		Ingrese el exponente: -2
		Error: el exponente debe debe ser positivo
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

int main(){
	printf("\n________________________________________________\n\n");
	
	
	
	printf("\n________________________________________________\n\n");
	return 0;
}