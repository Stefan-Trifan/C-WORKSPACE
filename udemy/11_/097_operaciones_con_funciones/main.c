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

void  menu        (int *opcion, float *num1, float *num2);
float sumar       (float num1, float num2);
float restar      (float num1, float num2);
float multiplicar (float num1, float num2);
float dividir     (float num1, float num2);
void  clearBuffer ();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int   opcion    = 0;
	float num1      = 0,
	      num2      = 0,
	      resultado = 0;

	menu(&opcion, &num1, &num2);

	switch (opcion)
	{
		case 1: 
			resultado = sumar(num1, num2);
			break;
		case 2: 
			resultado = restar(num1, num2);
			break;
		case 3: 
			resultado = multiplicar(num1, num2);
			break;
		case 4: 
			resultado = dividir(num1, num2);
			break;
	}
    
	printf("El resultado es: %f", resultado);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void menu(int *opcion, float *num1, float *num2)
{
	do {
		printf(
			"Introduce el tipo de operacion: \n"
			"1. Sumar\n"
			"2. Restar\n"
			"3. Multiplicar\n"
			"4. Dividir\n"
			"-> ");
		scanf("%i", opcion);
		printf("\n");
	} while (*opcion < 1 || *opcion > 4);

	printf("Introduce el numero 1: ");
	scanf("%f", num1);
	printf("Introduce el numero 2: ");
	scanf("%f", num2);
}

float sumar(float num1, float num2)
{
	return num1 + num2;
}

float restar(float num1, float num2)
{
	return num1 - num2;
}

float multiplicar(float num1, float num2)
{
	return num1 * num2;
}

float dividir(float num1, float num2)
{
	return num1 / num2;
}


void clearBuffer()
{
	while (getchar() != '\n');
}