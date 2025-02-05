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
#define PI 3.14

float calculoAreaValor(float Radio);
float calculoAreaReferencia(float *Radio);
void calculoAreaLongCirc(float Radio, float *Area, float *LongCirc);

void clearBuffer();
float pedirFloat();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    float MiRadio     = 0;
    float MiArea      = 0;
    float MiAreaValor = 0;
	float MiAreaRef   = 0;
    float MiLongCirc  = 0;
    int   ResultScanf = 0;

    // Pedimos el radio
    MiRadio = pedirFloat();

	// Paso por valor
    MiAreaValor = calculoAreaValor(MiRadio);
	
	// Paso por referencia
    MiAreaRef = calculoAreaReferencia(&MiRadio);

	// Calculamos la longitud de la circunferencia
    calculoAreaLongCirc(MiRadio, &MiArea, &MiLongCirc);

    printf("Area por Valor de un circulo es %.2f\n", MiAreaValor);
    printf("Area por Referencia de un circulo es %.2f\n", MiAreaRef);
    printf("El area y la long de la circunferenicia de un circulo es %.2f\n ", MiAreaRef, MiLongCirc);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float calculoAreaValor(float Radio) 
{ 
	return (PI * Radio * Radio); 
}

float calculoAreaReferencia(float *Radio) 
{ 
	return (PI * (*Radio) * (*Radio)); 
}

void calculoAreaLongCirc(float Radio, float *Area, float *LongCirc)
{
    *Area = PI * Radio * Radio;
    *LongCirc = 2 * PI * Radio;
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
		if (esValido == 0 || num < 0)
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









