/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 10
typedef struct
{
	int edad;
}
persona_t;
// Funciones del programa

// Funciones auxiliares
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    persona_t personas[TAM] = {0};

	printf("Introduce las 2 edades: \n");	
	printf("Edad persona 1: ");
	personas[0].edad = pedirEntero();
	printf("Edad persona 2: ");
	personas[1].edad = pedirEntero();

	printf("%d\n", personas[0].edad);
	printf("%d\n", personas[1].edad);
    
	printf("\n_________________________________________END\n\n");
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
		if(esValido != 1)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
				"Por favor, inténtelo de nuevo.\n"
				"-> \033[0m"
			);
		}
	} 
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}
