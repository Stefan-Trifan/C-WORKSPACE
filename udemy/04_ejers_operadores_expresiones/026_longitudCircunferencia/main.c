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

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define PI 3.1416

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
	// Declaración de variables
	float radio = 0, circunferencia = 0;

	// Solicitar al usuario que introduzca el radio
	printf("Introduce el radio: ");
	scanf("%f", &radio);

	// Calcular la circunferencia
	circunferencia = 2 * PI * radio;

	// Mostrar el resultado
	printf("Circunferencia es: %f", circunferencia);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}