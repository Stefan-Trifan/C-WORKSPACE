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

float solicitarFloat();
int   solicitarEntero();
void  menuCalculadora();
void  sumar();
void  restar();
void  multiplicar();
void  dividir();
void  clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	menuCalculadora();
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float solicitarFloat()
{
	float num = 0;
	int esValido = 1;
	printf("-> ");
	do
	{	
		if(esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. Por favor, intentelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
		}
		esValido = scanf("%f", &num);
		clearBuffer();
	} 
	while (esValido != 1);
	return num;
}

int solicitarEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{	
		if(esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. Por favor, intentelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
		}
		esValido = scanf("%d", &num);
		clearBuffer();
	} 
	while (esValido != 1);
	return num;
}

void menuCalculadora()
{
	int opcion = 0;
	int resultado = 0;

	do
	{
		printf(
			"Introduce una opcion a realizar: \n"
			"1. Sumar\n"
			"2. Restar\n"
			"3. Multiplicar\n"
			"4. Dividir\n"
			"5. Salir\n");
		opcion = solicitarEntero();

		switch (opcion)
		{
			case 1: 
				sumar();
				break;
			case 2: 
				restar();
				break;
			case 3: 
				multiplicar();
				break;
			case 4: 
				dividir();
				break;
			case 5: 
				printf("Hasta luego!");
				break;
			default: 
				printf("Opcion invalida, introduce un numero del 1 al 5.\n\n");
				break;
		}
	} 
	while (opcion != 5);
}

void sumar()
{
	float num1 = 0, num2 = 0, resultado = 0;
	printf("Introduce el primer numero: \n");
	num1 = solicitarFloat();
	printf("Introduce el segundo numero: \n");
	num2 = solicitarFloat();
	resultado = num1 + num2;
	printf("%f + %f = %f\n\n", num1, num2, resultado);

}

void restar()
{
	float num1 = 0, num2 = 0, resultado = 0;
	printf("Introduce el primer numero: \n");
	num1 = solicitarFloat();
	printf("Introduce el segundo numero: \n");
	num2 = solicitarFloat();
	resultado = num1 - num2;
	printf("%f - %f = %f\n\n", num1, num2, resultado);

}

void multiplicar()
{
	float num1 = 0, num2 = 0, resultado = 0;
	printf("Introduce el primer numero: \n");
	num1 = solicitarFloat();
	printf("Introduce el segundo numero: \n");
	num2 = solicitarFloat();
	resultado = num1 * num2;
	printf("%f * %f = %f\n\n", num1, num2, resultado);

}

void dividir()
{
	float num1 = 0, num2 = 0, resultado = 0;
	printf("Introduce el primer numero: \n");
	num1 = solicitarFloat();
	printf("Introduce el segundo numero: \n");
	num2 = solicitarFloat();
	resultado = num1 / num2;
	printf("%f / %f = %f\n\n", num1, num2, resultado);

}

void clearBuffer()
{
	while (getchar() != '\n');
}