/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado
		- Solicitar al usuario que introduzca por teclado un conjunto de números enteros.
		- Estos deben irse almacenando mientras que sean menores que el primero introducido.
		- En el momento que esta condición no se cumpla no se deben pedir más números al usuario 
		y deben escribirse todos los que haya introducido hasta ese momento.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa

// Funciones auxiliares
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int *p_num, primer_num, cont = 1;
	p_num = (int *)malloc(sizeof(int));

	// Pedimos el primer numero
	printf("Introduce el primer numero\n-> ");
	*p_num = pedirEntero();
	primer_num = *p_num;

	// Pedimos numeros hasta que sea menor que primer_num
	do
	{
		cont++;
		// Aumentamos la memoria de nuestro punero
		int *temp;
		temp = (int *)realloc(p_num, cont * sizeof(int));
		if(temp == NULL)
		{
			printf("No hay suficiente memoria\n");
			return 1;
		}
		p_num = temp;

		// Pedimos otro numero
		printf("Introduce otro numero\n-> ");
		*(p_num + (cont - 1)) = pedirEntero();
	} 
	while (*(p_num + (cont - 1)) < primer_num);
	
	// Imprimimos los numeros
	printf("\n\nTus numeros son:\n");
	for(int i = 0; i < cont; i++)
	{
		printf("*(p_num + %d) = %d\n",i, *(p_num + i));
	}
	
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
int pedirEntero()
{
	int num = 0, esValido = 0;
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
				"-> \033[0m"
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