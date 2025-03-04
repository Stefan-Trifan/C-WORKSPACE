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
float convertirCelsiusAKelvin(float gradosCelsius);
float convertirCelsiusAFahrenheit(float gradosCelsius);

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
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
		// Pedimos grados Celsius
		printf("Este programa convierte grados Celsius a grados Fahrenheit y a grados Kelvin.\n");
		printf("Introduce el valor de los grados Celsius a continuacion: ");
		if(scanf("%f", &gradosCelsius) != 1)
		// Nos cercionamos de que el tipo de dato introducido por el usuario es valido
		{
			printf("Entrada no valida. Por favor, introduce un numero.\n\n");
			clearBuffer();
			gradosCelsius = 0;
			continue;
		} 
		printf("\n");

		// Pedmos la opcion a realizar
		printf(
			"Que deseas hacer?\n"
			"1) Conversion a Kelvin\n"
			"2) Conversion a Fahrenheit\n"
			"3) Salir\n");
		// Nos cercionamos de que el tipo de dato introducido por el usuario es valido
		do
		{
			printf("-> ");
			scanf("%d", &opcion);
			clearBuffer();
		} 
		while (opcion < 1 || opcion > 3); 

		// Ejecitamos lo que pide el usuario
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

float convertirCelsiusAKelvin(float gradosCelsius)
{
	return gradosCelsius + 273.15;
}

float convertirCelsiusAFahrenheit(float gradosCelsius)
{
	return gradosCelsius * 9 / 5 + 32;
}

void clearBuffer()
{
	while (getchar() != '\n');
}