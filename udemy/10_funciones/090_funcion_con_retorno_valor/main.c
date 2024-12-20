/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir despues de scanf
		limpiar()

	* 	Enunciado X
		LoremIpsumDummyText
*/

#include <stdio.h>
#include <unistd.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

// Declaramos/inicializamos la funcion
int sumar(int a, int b);

int main(){
	printf("\n________________________________________________\n\n");

	int a = 5;
	int b = 10;

	// Llamamos la funcion
	printf("Resultado es: %d", sumar(a, b));

	printf("\n________________________________________________\n\n");
	return 0;
}

// Funcion
int sumar(int a, int b)
{
	int resultado = 0;
	resultado = a + b;
	return resultado;
}