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

		* Ejercicio D - Operaciones aritmeticas, logicas y relacionales

		Escriba un programa en C que solicite al usuario que ingrese dos numeros enteros. 
		Luego, el programa debe usar operadores relacionales y logicos para realizar lo siguiente:

		1. Verificar e imprimir si el primer numero es mayor o igual que el segundo numero.
		2. Verificar e imprimir si el primer numero es menor que 100 y el segundo numero es mayor que 50.
		3. Verificar e imprimir si alguno de los numeros es igual a 0 o si ambos numeros son pares.
		4. Verificar e imprimir si los dos numeros no son iguales.
		5. Verificar e imprimir si los dos numeros son pares.

		* Ejemplo de ejecucion:

		* Entrada:
		
		Introduce el primer numero: 75
		Introduce el segundo numero: 60

		* Salida:

		El primer numero es mayor o igual que el segundo numero: Si
		El primer numero es menor que 100 y el segundo numero es mayor que 50: Si
		Uno de los numeros es 0 o ambos son pares: No
		Los dos numeros son diferentes: Si
		Los dos numeros son pares: No
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

	// Pedimos 2 numeros enteros
	printf("Introduce el primer numero: ");
	scanf("%i", &num1);
	
	printf("Introduce el segundo numero: ");
	scanf("%i", &num2);

	// Verificamos e imprimimos si el primer numero es mayor o igual que el segundo numero.
	if(num1 >= num2)
		printf("El primer numero es mayor o igual que el segundo numero: Si\n");
	else
		printf("El primer numero es mayor o igual que el segundo numero: No\n");

	// Verificamos e imprimimos si el primer numero es menor que 100 y el segundo numero es mayor que 50.
	if((num1 < 100) && (num2 > 50))
		printf("El primer numero es menor que 100 y el segundo numero es mayor que 50: Si\n");
	else
		printf("El primer numero es menor que 100 y el segundo numero es mayor que 50: No\n");

	// Verificamos e imprimimos si alguno de los numeros es igual a 0 o si ambos numeros son pares.
	if(((num1 == 0) || (num2 == 0)) || (( num1 % 2 == 0) && (num2 % 2 == 0)))
		printf("Uno de los numeros es 0 o ambos son pares: Si\n");
	else
		printf("Uno de los numeros es 0 o ambos son pares: No\n");

	// Verificamos e imprimimos si los dos numeros no son iguales.
	if(num1 != num2)
		printf("Los dos numeros son diferentes: Si\n");
	else
		printf("Los dos numeros son diferentes: No\n");

	// Verificamos e imprimimos si los dos numeros son pares.
	if(( num1 % 2 == 0) && (num2 % 2 == 0))
		printf("Los dos numeros son pares: Si\n");
	else
		printf("Los dos numeros son pares: No\n");

}