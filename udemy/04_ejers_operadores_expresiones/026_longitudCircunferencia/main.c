/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define PI 3.1416

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
	// Declaracion de variables
	float radio = 0, circunferencia = 0;

	// Solicitar al usuario que introduzca el radio
	printf("Introduce el radio: ");
	scanf("%f", &radio);

	// Calcular la circunferencia
	circunferencia = 2 * PI * radio;

	// Mostrar el resultado
	printf("Circunferencia es: %f", circunferencia);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}