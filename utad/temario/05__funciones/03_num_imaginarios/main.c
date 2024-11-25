/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado 22

		Codificar un programa en C que:

		Solicite dos numeros complejos al usuario, 
		Realice la suma, resta y multiplicacion de los mismos.
		
		Debes generar un menu que incluya una entrada para cada operacion
		Debes codificar las operaciones en funciones

*/

#include <stdio.h>

int suma(int a, int b);
int resta(int a, int b);
int multi(int a, int b);

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Variables
	int a  = 0;
	int ai = 0;
	int b  = 0;
	int bi = 0;
	int resultado = 0;
	int operacion = 0;

	int c  = 0;
	int ci = 0;

	// Pedimos primer num
	printf("Introduce la parte natural del primer numero:     ");
	scanf("%i", &a);

	printf("Introduce la parte imaginaria del segundo numero: ");
	scanf("%i", &ai);
	printf("Tu primer numero imaginario es:                   %i + %ii\n", a, ai);

	// Pedimos segundo num
	printf("Introduce la parte natural del segundo numero:    ");
	scanf("%i", &b);

	printf("Introduce la parte imaginaria del segundo numero: ");
	scanf("%i", &bi);
	printf("Tu segundo numero imaginario es:                  %i + %ii\n", b, bi);

	// Preguntamos que operacion deseamos realizar
	printf(
		"Introduce el tipo de operacion que deseas realizar: \n"
		"1: suma \n"
		"2: resta \n"
		"3: multiplicacion \n"
		"Tipo operacion: ");
	scanf("%i", &operacion);

	switch(operacion){
		case 1: c = suma(a, b);
				ci = suma(a, b);
			    break;
		case 2: c = resta(a, b);
				ci = resta(a, b);
			    break;
		case 3: c = multi(a, b);
				ci = multi(a, b);
			    break;
	}

	printf("El resultado es: %i + %ii", c, ci);
	
}

int suma(int a, int b){
	int c = 0;
	c = a + b;

	return c;
}

int resta(int a, int b){
	int c = 0;
	c = a - b;

	return c;
}

int multi(int a, int b){
	int c = 0;
	c = a * b;

	return c;
}