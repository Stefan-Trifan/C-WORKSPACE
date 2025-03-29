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
// Escribe un programa en el cual se solicite al usuario llenar un arreglo de 10 elementos 
// (unicamente 0 y 1). Una vez que el usuario llene el arreglo con el numero binario, 
// podra seleccionar entre alguna codificacion:

// a) binario puro
// b) Punto fijo (6 bit entero y 4 bit decimal)
// c) complemento a 2

// El programa realizara la conversion y como salida mostrara 
// el resultado en representacion decimal

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_ARRAY 10
void binarioPuro(int arreglo[]);
void puntoFijo(int arreglo[]);
void complementoA2(int arreglo[]);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
	int arreglo[TAM_ARRAY] = {0},
		opcion             = 1;

	printf(
		"Este programa hace conversiones de binario a tres diferentes tipos de codificacion\n"
		"SOLO USA 0 y 1\n\n"
	);

	// void crearArreglo(arreglo)
	printf("Primero llena el arreglo de %d elementos\n", TAM_ARRAY);
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
				"\033[1;31mERROR: El tipo de dato introducido no es valido."
				"Por favor, intentelo de nuevo. \n\033[0m"
			);
		printf("\n");

		switch (opcion)
		{
			case 1: 
				printf("Seleccionaste Binario Puro\n");
				binarioPuro(arreglo);
				break;
			case 2: 
				printf("Seleccionaste Punto Fijo\n");
				puntoFijo(arreglo);
				break;
			case 3: 
				printf("Seleccionaste Complemento A2\n");
				complementoA2(arreglo);
				break;
			default: 
				printf("Gracias por utilizar el programa :)");
				break;
		}
	} 
	while (opcion >= 1 && opcion <= 3);

	
	
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void binarioPuro(int arreglo[])
{
	int valor = 512, suma = 0;
	for(int i = 0; i < 10; i++)
	{
		if(arreglo[i] == 1)
		{
			suma += valor;
		}
		valor /= 2;
	}
	printf("El valor en decimal es: %d\n\n", suma);
}

void puntoFijo(int arreglo[])
{
	int valor = 32, suma = 0;
	float sumaDecimal = 0, valorDecimal = 0.5;
	// Parte entera
	for(int i = 0; i < 10; i++)
	{
		if(arreglo[i] == 1)
		{
			suma += valor;
		}
		valor /= 2;
	}
	//Parte decimal
	for(int i = 6; i < 10; i++)
	{
		if(arreglo[i] == 1)
		{
			sumaDecimal += valorDecimal;
		}
		valorDecimal /= 2;
		
	}
	printf("El valor del numero en punto fijo es %.4f\n\n", suma + sumaDecimal);
}

void complementoA2(int arreglo[])
{
	int posicion = 9; // Inicializar la variable posicion
	for(int i = 0; i < 10; i++)
	{
		if(arreglo[i] == 1)
		{
			arreglo[i] = 0;
		}
		else
		{
			arreglo[i] = 1;
		}
	}
	while(arreglo[posicion] == 1)
	{
		arreglo[posicion] = 0;
		posicion--;
		if(arreglo[posicion] == 0)
		{
			arreglo[posicion] = 1;
			break;
		}
	}
	if(arreglo[posicion] == 0)
	{
		arreglo[posicion] = 1;
	}
	for(int i = 0; i < 10; i++)
	{
		printf("[%d]\n", arreglo[i]);
	}
	printf("\n");
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
				"\033[1;31mERROR: El tipo de dato introducido no es valido. "
				"Por favor, intentelo de nuevo. \n\033[0m" 
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
