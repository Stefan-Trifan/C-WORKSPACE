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
		Crear un programa que pida un dato en formato coma flotante, y muestre el resultado de convertirlo a flotante.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	// Declaramos variables
	float flotante   = 0;
	int entero     = ' ';

	printf("Introduce un numero flotante \n");
	scanf("%f", &flotante);

	entero = (int)flotante;
	printf("%i\n", entero);

}