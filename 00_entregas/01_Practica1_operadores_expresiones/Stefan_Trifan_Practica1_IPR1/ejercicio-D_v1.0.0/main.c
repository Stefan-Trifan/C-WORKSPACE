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

		* Ejercicio D - Operaciones aritméticas, lógicas y relacionales

		Escriba un programa en C que solicite al usuario que ingrese dos números enteros. 
		Luego, el programa debe usar operadores relacionales y lógicos para realizar lo siguiente:

		1. Verificar e imprimir si el primer número es mayor o igual que el segundo número.
		2. Verificar e imprimir si el primer número es menor que 100 y el segundo número es mayor que 50.
		3. Verificar e imprimir si alguno de los números es igual a 0 o si ambos números son pares.
		4. Verificar e imprimir si los dos números no son iguales.
		5. Verificar e imprimir si los dos números son pares.

		* Ejemplo de ejecución:

		* Entrada:
		
		Introduce el primer número: 75
		Introduce el segundo número: 60

		* Salida:

		El primer número es mayor o igual que el segundo número: Sí
		El primer número es menor que 100 y el segundo número es mayor que 50: Sí
		Uno de los números es 0 o ambos son pares: No
		Los dos números son diferentes: Sí
		Los dos números son pares: No
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declramos las variables
	int num1 = 0;
	int num2 = 0;

	// Pedimos 2 números enteros
	printf("Introduce el primer número: ");
	scanf("%i", &num1);
	
	printf("Introduce el segundo número: ");
	scanf("%i", &num2);

	// Verificamos e imprimimos si el primer número es mayor o igual que el segundo número.
	if(num1 >= num2)
		printf("El primer número es mayor o igual que el segundo número: Sí\n");
	else
		printf("El primer número es mayor o igual que el segundo número: No\n");

	// Verificamos e imprimimos si el primer número es menor que 100 y el segundo número es mayor que 50.
	if((num1 < 100) && (num2 > 50))
		printf("El primer número es menor que 100 y el segundo número es mayor que 50: Sí\n");
	else
		printf("El primer número es menor que 100 y el segundo número es mayor que 50: No\n");

	// Verificamos e imprimimos si alguno de los números es igual a 0 o si ambos números son pares.
	if(((num1 == 0) || (num2 == 0)) || (( num1 % 2 == 0) && (num2 % 2 == 0)))
		printf("Uno de los números es 0 o ambos son pares: Si\n");
	else
		printf("Uno de los números es 0 o ambos son pares: No\n");

	// Verificamos e imprimimos si los dos números no son iguales.
	if(num1 != num2)
		printf("Los dos números son diferentes: Sí\n");
	else
		printf("Los dos números son diferentes: No\n");

	// Verificamos e imprimimos si los dos números son pares.
	if(( num1 % 2 == 0) && (num2 % 2 == 0))
		printf("Los dos números son pares: Si\n");
	else
		printf("Los dos números son pares: No\n");

}