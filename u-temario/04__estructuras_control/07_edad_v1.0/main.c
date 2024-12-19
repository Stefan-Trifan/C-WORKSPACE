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
		Pide al usuario que introduzca su edad e imprimela por pantalla. ¿Que ocurre si introducimos un caracter?
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
			printf("No has introducido un numero. Introduce un numero\n");
			while(getchar() != '\n');
		} else {
			printf("Tienes %i anos\n", edad);
		}

	}
	
}
