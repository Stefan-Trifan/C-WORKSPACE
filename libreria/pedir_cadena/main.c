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
#define TAM 3
// Funciones del programa

// Funciones auxiliares
void pedirCadena(char texto[], int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char mi_nombre[10] = {0};

	printf("Introduce tu nombre\n");
	pedirCadena(mi_nombre, TAM);

	printf("Nombre: %s\n", mi_nombre);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char texto[], int tam)
{
	int esValido = 1, i = 0;
	char newChar;

	printf("Max. %d caracteres -> ", tam - 1);

	do
	{
		// Leer la entrada hasta '\n' o hasta que se llene el array (dejando espacio para '\0')
		while (((newChar = getchar()) != '\n') && (i < tam - 1))
		{
			texto[i] = newChar;
			i++;
		}
		texto[i] = '\0'; // Finalizar la cadena

		if (i == tam - 1 && newChar != '\n')
		{
			printf(
				"\033[1;31mERROR: Has superado el tamaño.\n\033[0m"
				"\033[1;31mPor favor, inténtelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m");
			clearBuffer();
			esValido = 0;
		}
	} while (!esValido);
}
void clearBuffer()
{
	while (getchar() != '\n');
}