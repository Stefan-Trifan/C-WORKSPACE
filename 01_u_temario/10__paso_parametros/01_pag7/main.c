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
		1. Repaso Punteros. Ejercicio
		Crear un programa implemente tres funciones:
		Función de cálculo del área de un círculo paso por valor
		Función de cálculo del área de un círculo paso por referencia
		Función de cálculo del área y de la longitud de la circunferencia de un círculo.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define PI 3.14

float calculoAreaValor(int radio);
float calculoAreaReferencia(int* radio);
float calculoAreaYCircunferencia(int radio);

void clearBuffer();
int pedirEntero();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int radio = 0, area = 0, circunferencia = 0;

	radio = pedirEntero();

	area = calculoAreaValor(radio);
	area = calculoAreaValor(radio);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float calculoAreaValor(int radio)
{
	return 0;
}

float calculoAreaReferencia(int* radio)
{
	return 0;
}

float calculoAreaYCircunferencia(int radio)
{
	return 0;
}


void clearBuffer()
{
	while (getchar() != '\n');
}

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("Introduce el radio: \n");
	printf("-> ");
	do
	{
		esValido = scanf("%i", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}