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
		- Hacer un programa que pida al usuario dos numeros enteros (a y b) y que a
		continuacion invoque una funcion que haga la suma de los terminos
		comprendidos entre dichos numeros.

		- La funcion recibira como parametros los dos numeros leidos del usuario, a y b que
		se corresponden con el valor inicial de la serie y el valor final de la serie.

		- La funcion devolvera como resultado un numero entero que sera la suma de los
		terminos de la serie comprendidos entre a y b (incluyendo dichos numeros).
*/

#include <stdio.h>

// Inicializamos la funcion
int sumaNumComprendidos(int a,int b);

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(int argc, char *argv[]){

	// Declaramos las variables
	int a = 0;
	int b = 0;
	int resultado = 0;

	// Pedimos los 2 numeros
	printf("Introduce el primer numero: ");
	scanf("%d", &a);
	printf("El primer numero es %d\n", a);

	printf("Introduce el segundo numero: ");
	scanf("%d", &b);
	printf("El segundo numero es %d\n", b);

	// Imprimimos el resultado
	resultado = sumaNumComprendidos(a, b);
	printf("Resultado es: %d\n", resultado);
}

// Declaramos la funcion

int sumaNumComprendidos(int a, int b){

	int suma = 0;
	int numVueltas = 0;
	
	// Buscamos cuantos numeros hay comprendidos
	if ( a < b ){
		numVueltas = b - a;
		printf("Hay %d numeros comprendidos\n", numVueltas);

		// Hacemos la suma de los numeros comprendidos
		for(int i = a; i <= b; i++){
			suma = suma + i;
		}

	}

	if ( a > b ){
		numVueltas = a - b;
		printf("Hay %d numeros comprendidos\n", numVueltas);

		// Hacemos la suma de los numeros comprendidos
		for(int i = b; i <= a; i++){
			suma = suma + i;
		}
	}

	return suma;

}