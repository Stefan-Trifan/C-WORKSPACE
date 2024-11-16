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
		Pide un caracter b, r, n, v y devuelve un color que empieza por ese caracter o un mensaje indicando que no hay ningun color asignado. Realizar el ejemplo mediante un switch-case.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Decaramos las variables
	char letra;

	printf("Introduce la letra 'b', 'r', 'n', 'v'\n");
	scanf("%c", &letra);
	limpiar();

	switch(letra){
		case 'b': printf("Tu color es Bazul");
				break;
		case 'B': printf("Tu color es Bazul");
				break;
		case 'r': printf("Tu color es Ramarillo");
				break;
		case 'R': printf("Tu color es Ramarillo");
				break;
		case 'n': printf("Tu color es Niligo");
				break;
		case 'N': printf("Tu color es Niligo");
				break;
		case 'v': printf("Tu color es Varron");
				break;
		case 'V': printf("Tu color es Varron");
				break;
	}
}