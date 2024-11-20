/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: todo

	* 	Enunciado X
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	int eleccion = 0;
    
    printf("Selecciona el tipo de operacion: \n"
	"1 Imprimir los primeros n numeros naturales (del 1 al n)\n"
	"2 Imprimir la suma de los numeros del 1 al n\n"
	"3 Calcular el n-esimo numero de la sicesion de Fibonacci usando recursion\n"
	"4 Salir.\n");
	scanf("%i", &eleccion);

	if(eleccion == 1){
	
	}	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}