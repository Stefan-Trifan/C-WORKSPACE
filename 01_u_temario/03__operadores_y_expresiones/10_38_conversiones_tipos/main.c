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
		Convertir un numero entero introducido por teclado a caracter e imprimirlo por pantalla
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	// Declaramos variables
	int entero   = 0;
	char caracter = ' ';

	printf("Introduce un numero entero \n");
	scanf("%d", &entero);

	caracter = (char)entero;
	printf("%c\n", caracter);

}