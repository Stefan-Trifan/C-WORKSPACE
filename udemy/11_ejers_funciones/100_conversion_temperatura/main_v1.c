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
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int convertirCelsiusAKelvin(int gradosCelsius);
int convertirCelsiusAFahrenheit(int gradosCelsius);

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	// Declaracion de variables
	int   opcion           = 0;
	float gradosCelsius    = 0,
	      gradosFahrenheit = 0,
	      gradosKelvin     = 0,
	      resultado        = 0;

    do
	{
		printf("Este programa convierte grados Celsius a grados Fahrenheit y a grados Kelvin.\n");
		printf("Introduce el valor de los grados Celsius a continuación: ");
		if(scanf("%f", &gradosCelsius) != 1)
		{
			printf("Entrada no válida. Por favor, introduce un número.\n\n");
			clearBuffer();
			gradosCelsius = 0;
			continue;
		}
		
		printf("\n");

		printf(
			"Que deseas hacer?\n"
			"1) Conversion a Kelvin\n"
			"2) Conversion a Fahrenheit\n"
			"3) Salir\n"
			"-> ");
			
		if(scanf("%d", &opcion) != 1)
		{
			printf("Entrada inválida. Por favor introduce un número.\n\n");
			clearBuffer();
			continue;
		}

		switch (opcion)
		{
			case 1: 
				resultado = convertirCelsiusAKelvin(gradosCelsius);
				printf("El resultado es: %f\n\n", resultado);
				break;
			case 2: 
				resultado = convertirCelsiusAFahrenheit(gradosCelsius);
				printf("El resultado es: %f\n\n", resultado);
				break;
			default: 
				break;
		}
	} 
	while (opcion != 3);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int convertirCelsiusAKelvin(int gradosCelsius)
{
	return gradosCelsius + 273.15;
}

int convertirCelsiusAFahrenheit(int gradosCelsius)
{
	return gradosCelsius * (9 / 5) + 32;
}

void clearBuffer()
{
	while (getchar() != '\n');
}