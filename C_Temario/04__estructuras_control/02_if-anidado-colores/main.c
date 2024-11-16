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
		Pide un numero entero de tres cifras por teclado. 
		Comprueba si la tercera cifra (centena) del numero es 1, 2 , 3 o 5 escribiendo por pantalla que la centena del numero es 1, 2, 3 o 5. 
		Si no es asi, el programa debera escribir que la centena no es 1, 2, 3 o 5.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Decaramos las variables
	char letra = ' ';

	printf("Introduce la letra 'b', 'r', 'n', 'v'\n");
	scanf("%c", &letra);

	if (letra == 'b' || letra == 'B')
		printf("Bazul");
	else if (letra == 'r' || letra == 'R')
		printf("Ramarillo");
	else if (letra == 'n' || letra == 'N')
		printf("niligo");
	else if (letra == 'v' || letra == 'V')
		printf("varron");
	else 
		printf("Has introducido la letra incorrecta\n");
}