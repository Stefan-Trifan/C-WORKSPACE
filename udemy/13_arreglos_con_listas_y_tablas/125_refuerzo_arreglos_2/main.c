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
#define TAM_ARRAY 10

void crear(int *arreglo);
void imprimirArray(int *arreglo);
void sumatorioElementos(int arreglo[]);
void productorioElementos(int *arreglo);
void sumatorioMultiplosDeTres(int *arreglo);
void multiplicarPorTresCadaElemento(int *arreglo);
int  pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	int arreglo[TAM_ARRAY] = {0},
	    opcion             = 0;

	crear(arreglo);
	imprimirArray(arreglo);
	printf("\n\n");

	do
	{
		printf(
			"Escoje una opcion: \n"
			"1) Ingresar o modificar elementos del arreglo\n"
			"2) Mostrar la Suma de los elementos\n"
			"3) Realizar la multiplicacion de los elementos\n"
			"4) Realizar la suma solo de los elementos divisibles entre 3\n"
			"5) Multiplicar por 3 cada elemento del arreglo\n"
			"6) Salir\n"
		);
		opcion = pedirEntero();
		if(opcion < 1 || opcion > 7)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. "
				"Por favor, inténtelo de nuevo. \n\033[0m");
		}
			
		switch (opcion)
		{
			case 1: 
				imprimirArray(arreglo);
				crear(arreglo);
				imprimirArray(arreglo);
				break;
			case 2: 
				imprimirArray(arreglo);
				sumatorioElementos(arreglo);
				break;
			case 3: 
				imprimirArray(arreglo);
				productorioElementos(arreglo);
				break;
			case 4: 
				imprimirArray(arreglo);
				sumatorioMultiplosDeTres(arreglo);
				break;
			case 5: 
				multiplicarPorTresCadaElemento(arreglo);
				imprimirArray(arreglo);
				break;
			case 6: 
				break;
			default: 
				break;
		}
		printf("\n\n");
	} 
	while (opcion != 6);

	printf("Muchas gracias por su visita");
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void crear(int *arreglo)
{
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		printf("Introduce el elemento %d \n", i);
		arreglo[i] = pedirEntero();
	}
}

void imprimirArray(int *arreglo)
{
	printf("Los elementos de tu aray son: \n");
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		printf("[%d]: %d \n",i, arreglo[i]);
	}
}

void sumatorioElementos(int arreglo[])
{
	int resultado = 0;
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		resultado += arreglo[i];
	}
	printf("Resultado sumatorio: %d\n", resultado);
}

void productorioElementos(int *arreglo)
{
	int resultado = 1;
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		resultado *= arreglo[i];
	}
	printf("Resultado productorio: %d\n", resultado);
}

void sumatorioMultiplosDeTres(int *arreglo)
{
	int resultado = 0;
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		if(arreglo[i] % 3 == 0)
		{
			resultado += arreglo[i];
		}
	}
	printf("Resultado productorio multiplos de 3: %d\n", resultado);
}

void multiplicarPorTresCadaElemento(int *arreglo)
{
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		arreglo[i] *= 3;
	}
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

