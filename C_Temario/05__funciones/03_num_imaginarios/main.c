/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado 22

		Codificar un programa en C que:

		Solicite dos números complejos al usuario, 
		Realice la suma, resta y multiplicación de los mismos.
		
		Debes generar un menú que incluya una entrada para cada operación
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
	printf("Introduce la parte natural del primer número:     ");
	scanf("%i", &a);

	printf("Introduce la parte imaginaria del segundo número: ");
	scanf("%i", &ai);
	printf("Tu primer número imaginario es:                   %i + %ii\n", a, ai);

	// Pedimos segundo num
	printf("Introduce la parte natural del segundo número:    ");
	scanf("%i", &b);

	printf("Introduce la parte imaginaria del segundo número: ");
	scanf("%i", &bi);
	printf("Tu segundo número imaginario es:                  %i + %ii\n", b, bi);

	// Preguntamos que operación deseamos realizar
	printf(
		"Introduce el tipo de operación que deseas realizar: \n"
		"1: suma \n"
		"2: resta \n"
		"3: multiplicacion \n"
		"Tipo operación: ");
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