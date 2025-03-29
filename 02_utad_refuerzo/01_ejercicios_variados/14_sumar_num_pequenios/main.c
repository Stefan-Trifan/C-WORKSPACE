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
#define TAM 5
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	// todo inicializar el array en 0
    int array[TAM] = {19,5,42,2,77}, num1 = 0, num2 = 0, resultado;

	// Rellenamos el array
	printf("Introduce los valores del array: \n");
	for(int i = 0; i < TAM; i++)
	{
		printf("[%d]: ", i);
		array[i] = pedirEntero();
	}

	if(array[0] <= array[1])
	{
		num1 = array[0];
		num2 = array[1];
	}
	else if (array[1] <= array[0])
	{
		num2 = array[0];
		num1 = array[1];
	}
	
	for(int i = 2; i < TAM; i++)
	{
		if(array[i] <= num1)
		{
			num2 = num1;
			num1 = array[i];
		}
		else if(array[i] < num2)
		{
			num2 = array[i];
		}
	}

	printf(
		"num1 = %d\n"
		"num2 = %d\n"
		"suma = %d\n", num1, num2, num1 + num2);

    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int pedirEntero()
{
	int num = 0, esValido = 1;
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