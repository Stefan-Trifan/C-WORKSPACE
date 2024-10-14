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
		Pide al usuario que introduzca su edad e imprímela por pantalla. ¿Qué ocurre si introducimos un carácter?
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	int edad = 0;
	int resultadoScanf = 0;

	printf("Introduce tu edad\n");

	while (resultadoScanf == 0){

		resultadoScanf = scanf("%i", &edad);
		printf("El resultado de scanf es: %i\n", resultadoScanf);

		if (resultadoScanf == 0){
			printf("No has introducido un número. Introduce un número\n");
			while(getchar() != '\n');
		} else {
			printf("Tienes %i anos\n", edad);
		}

	}
	
}
