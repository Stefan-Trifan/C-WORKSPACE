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
		- Hacer un programa que pida al usuario dos números enteros (a y b) y que a
		continuación invoque una función que haga la suma de los términos
		comprendidos entre dichos números.

		- La función recibirá como parámetros los dos números leídos del usuario, a y b que
		se corresponden con el valor inicial de la serie y el valor final de la serie.

		- La función devolverá como resultado un número entero que será la suma de los
		términos de la serie comprendidos entre a y b (incluyendo dichos números).
*/

#include <stdio.h>

// Inicializamos la función
int sumaNumComprendidos(int a,int b);

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	int a = 0;
	int b = 0;
	int resultado = 0;

	// Pedimos los 2 números
	printf("Introduce el primer número: ");
	scanf("%i", &a);
	printf("El primer número es %i\n", a);

	printf("Introduce el segundo número: ");
	scanf("%i", &b);
	printf("El segundo número es %i\n", b);

	// Imprimimos el resultado
	resultado = sumaNumComprendidos(a, b);
	printf("Resultado es: %i\n", resultado);
}

// Declaramos la función

int sumaNumComprendidos(int a, int b){

	int suma = 0;
	int numVueltas = 0;
	
	// Buscamos cuantos números hay comprendidos
	if ( a < b ){
		numVueltas = b - a;
		printf("Hay %i números comprendidos\n", numVueltas);

		// Hacemos la suma de los números comprendidos
		for(int i = a; i <= b; i++){
			suma = suma + i;
		}

	}

	if ( a > b ){
		numVueltas = a - b;
		printf("Hay %i números comprendidos\n", numVueltas);

		// Hacemos la suma de los números comprendidos
		for(int i = b; i <= a; i++){
			suma = suma + i;
		}
	}

	return suma;

}