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
int  pedirEntero();
void clearBuffer();
int  fibonacci(int num);

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	int num = 0, resultado = 0;
    
    printf("Introduce un numero \n");
	num = pedirEntero();

	for(int i = 0; i <= num; i++)
	{
		resultado = fibonacci(i);
		if(i == num)
			printf("%d", resultado);
		else
			printf("%d, ", resultado);
		
	}

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int fibonacci(int num)
{
	if(num == 0)
		return 0; 
	else if(num == 1)
		return 1; 
	else 
		return fibonacci(num - 1) + fibonacci(num - 2);
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
				"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo. \n\033[0m"
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