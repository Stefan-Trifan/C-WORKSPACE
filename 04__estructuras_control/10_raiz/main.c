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
		Calcular las raíces reales de un polinomio de grado 2, 
		Expresado por el producto de tres térmimos 
		cada uno integrado:
			producto de un coeficiente y las potencias de x elevadas a 2, 1 y 0.
			a x^2 + b x + c = 0

		Usar la función sqrt de la librería math.h cuyo prototipo es double sqrt(double x); Returns the square root of x
*/

// No funciona bien

#include <stdio.h>
#include <math.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	
	// Declaramos las variables
	double a, b, c;
	double resultado1 = 0;
	double resultado2 = 0;
	double radicando = 0;
	
	// Pedimso el valor
	printf("Introduce el valor de a: ");
	scanf("%lf", &a);
	limpiar();

	// Pedimso el valor
	printf("Introduce el valor de b: ");
	scanf("%lf", &b);
	limpiar();

	// Pedimso el valor
	printf("Introduce el valor de c: ");
	scanf("%lf", &c);
	limpiar();

	radicando = b * b - 4 * a * c;

	if (radicando >= 0){

		resultado1 = (-b + sqrt(radicando)) / (2 * a);
		resultado2 = (-b - sqrt(radicando)) / (2 * a);
		printf("Los resutlados son %lf y %lf", resultado1, resultado2);

	} else {

		printf("No exiten resultados");

	}



}