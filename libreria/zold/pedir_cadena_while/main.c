/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 2
// Funciones del programa
void pedirCadena(char *text, int tam);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char nombre[TAM] = {0};

	printf("Escribe tu nombre\n");
	pedirCadena(nombre, TAM);
	printf("\n");

	printf("Nombre completo es: %s\n", nombre);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char *text, int tam)
{
	int esValido = 0, i = 0;

	printf("Max. %d caracteres -> ", tam - 1);

	do
	{
		i = 0;
		while(i < tam)
		{
			text[i] = getchar();
			if(text[i] == '\n' && i < tam)
			{
				text[i] = '\0';
				esValido = 1;
				break;
			}
			i++;
		}
	
		if (i == tam)
		{
			printf(
				"\033[1;31mERROR: Has superado el tamanio.\n\033[0m"
				"\033[1;31mPor favor, intentelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m");
			clearBuffer();
			esValido = 0;
		}
	} 
	while (esValido != 1);
}
void clearBuffer()
{
	while (getchar() != '\n');
}
