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

// Declaracion de la funcion para limpiar el buffer de entrada
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
	
	// Declaracion de variables para el precio inicial y final
	float precioInicial = 0, precioFinal = 0;

	// Solicita al usuario que introduzca el precio inicial
	printf("Introduce el precio Inicial: ");
	scanf("%f", &precioInicial);

	// Calcula el precio final aplicando un descuento del 15%
	precioFinal = precioInicial - 0.15*precioInicial;

	// Muestra el precio final
	printf("Precio Final es: %f", precioFinal);

	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Definicion de la funcion para limpiar el buffer de entrada
void clearBuffer()
{
	while (getchar() != '\n');
}