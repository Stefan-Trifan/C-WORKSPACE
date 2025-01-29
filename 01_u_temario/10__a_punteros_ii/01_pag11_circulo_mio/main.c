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

float calculoAreaValor(float radio);
float calculoAreaRef(float* radio);
void calculoAreaYCircunferencia(float radio, float* area, float* longitud);

float pedirFloat();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
	float miRadio     = 0,
	      miArea      = 0,
	      MiAreaRef   = 0,
	      MiAreaValor = 0,
	      MiLongCirc  = 0;

	// Pedimos el miRadio
	miRadio = pedirFloat();

	// Paso por valor
	MiAreaValor = calculoAreaValor(miRadio);
	printf("MiAreaValor: %i\n", MiAreaValor);

	// Paso por referencia
	MiAreaRef = calculoAreaRef(&miRadio);
	printf("MiAreaRef: %i\n", MiAreaRef);

	// Calculamos la longitud de la MiLongCirc
	calculoAreaYCircunferencia(miRadio, &miArea, &MiLongCirc);

	printf("Area por Valor de un circulo es %.2f\n", MiAreaValor);
    printf("Area por Referencia de un circulo es %.2f\n", MiAreaRef);
    printf("El area y la long de la circunferenicia de un circulo es %.2f\n ", MiAreaRef, MiLongCirc);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float calculoAreaValor(float radio)
{
	return PI * radio * radio;
}

float calculoAreaRef(float* radio)
{
	
	return 0;
}

void calculoAreaYCircunferencia(float radio, float* area, float* longitud)
{
	
	return 0;
}


void clearBuffer()
{
	while (getchar() != '\n');
}

float pedirFloat()
{
	float num = 0;
	int esValido = 1;
	printf("Introduce un numero flotante \n");
	printf("-> ");
	do
	{
		esValido = scanf("%f", &num);
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