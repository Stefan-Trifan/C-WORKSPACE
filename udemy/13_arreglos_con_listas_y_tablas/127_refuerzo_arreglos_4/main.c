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
// Escribe un programa en el cual se solicite al usuario llenar un arreglo de 10 elementos 
// (únicamente 0 y 1). Una vez que el usuario llene el arreglo con el número binario, 
// podrá seleccionar entre alguna codificación:

// a) binario puro
// b) Punto fijo (6 bit entero y 4 bit decimal)
// c) complemento a 2

// El programa realizará la conversión y como salida mostrará 
// el resultado en representación decimal

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_ARRAY 3
void binarioPuro(int arreglo[]);
void puntoFijo(int arreglo[]);
void complementoA2(int arreglo[]);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	int arreglo[TAM_ARRAY] = {0},
		opcion             = 1;

	printf(
		"Este programa hace conversiones de binario a tres diferentes tipos de codificacion\n"
		"SOLO USA 0 y 1\n\n"
	);

	// void crearArreglo(arreglo)
	printf("Primero llena el arreglo de %i elementos\n", TAM_ARRAY);
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		printf("Elemento %d ", i);
		arreglo[i] = pedirEntero();
		
	}
	printf("\n");

	// void imprimirArreglo(arreglo)
	printf("Tu arreglo es: \n");
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		printf("[%d]: %d\n", i, arreglo[i]);
	}
	printf("\n");

	//void imprimirMenu(arreglo)
	do
	{
		//int pedirOpcion(opcion)
		printf(
			"Escribe la opcion que deseas realizar: \n"
			"1) binario puro\n"
			"2) Punto fijo\n"
			"3) Complemento a 2\n"
			"4) Salir\n"
		);
		opcion = pedirEntero();
		if(opcion < 1 || opcion > 3)
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido."
				"Por favor, inténtelo de nuevo. \n\033[0m"
			);
		printf("\n");

		switch (opcion)
		{
			case 1: 
				printf("Seleccionaste Binario Puro");
				binarioPuro(arreglo);
				break;
			case 2: 
				printf("Seleccionaste Punto Fijo");
				puntoFijo(arreglo);
				break;
			case 3: 
				printf("Seleccionaste Complemento A2");
				complementoA2(arreglo);
				break;
			default: 
				printf("Gracias por utilizar el programa :)");
				break;
		}
	} 
	while (opcion >= 1 || opcion <= 3);

	
	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void binarioPuro(int arreglo[])
{

}

void puntoFijo(int arreglo[])
{

}

void complementoA2(int arreglo[])
{

}


int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. "
				"Por favor, inténtelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}
