/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir después de scanf
		limpiar()

	* 	Enunciado X
		LoremIpsumDummyText
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar()
{
	while (getchar() != '\n')
		;
}

// Declaramos/inicializamos la funcion
int sumar(int a, int b);

int main()
{
	printf("\n________________________________________________\n\n");

	int a = 5;
	int b = 10;

	// Llamamos la función
	printf("%d", sumar(a, b));

	printf("\n________________________________________________\n\n");
	return 0;
}

// Función
int sumar(int a, int b)
{
	int resultado = 0;
	resultado = a + b;
	return resultado;
}