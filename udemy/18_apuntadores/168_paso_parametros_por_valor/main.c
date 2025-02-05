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
void agregar(int a);
void clearBuffer();
int pedirEntero();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int numero;
	numero = pedirEntero();

	// Valor antes de la funcion
	printf("Valor 1: %d\n", numero);

	agregar(numero);

	printf("Valor 2: %d\n", numero);

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void agregar(int a)
{
	a += 10;
}

void clearBuffer()
{
	while (getchar() != '\n');
}

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("Introduce un numero entero \n");
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
