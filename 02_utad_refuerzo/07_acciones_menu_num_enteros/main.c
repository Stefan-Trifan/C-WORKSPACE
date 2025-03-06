/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: doing

	* 	Enunciado X
		Desarrolla un programa que muestre un menu con las siguientes opciones
		El programa debe repetir el menu hasta que el usuario eliga una opcion valuida
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int eleccion = 0;
    
    printf("Selecciona el tipo de operacion: \n"
	"1 Imprimir los primeros n numeros naturales (del 1 al n)\n"
	"2 Imprimir la suma de los numeros del 1 al n\n"
	"3 Calcular el n-esimo numero de la sicesion de Fibonacci usando recursion\n"
	"4 Salir.\n");
	scanf("%d", &eleccion);

	if(eleccion == 1){
	
	}	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}