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
#include <string.h>
#define TAM 2
typedef struct
{
	char nombre[6];
	char nombre_completo[11];
	int edad;
}persona_t;
// Funciones del programa

// Funciones auxiliares
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    persona_t alumnos[TAM];

	for(int i = 0; i < TAM; i++)
	{
		printf("Nombre persona %d\n-> ", i);
		scanf("%5s", alumnos[i].nombre);
		clearBuffer();

		printf("Nombre completo persona %d\n-> ", i);
		fgets(alumnos[i].nombre_completo, sizeof(alumnos[i].nombre_completo), stdin);
		// Eliminar el '\n' que fgets() almacena automaticamente
		int tam = strlen(alumnos[i].nombre_completo);
		if (alumnos[i].nombre_completo[tam - 1] == '\n') 
		{
			alumnos[i].nombre_completo[tam - 1] = '\0';
		}

		printf("Edad persona %d\n-> ", i);
		alumnos[i].edad = pedirEntero();
	}
	printf("\n\n");

	for(int i = 0; i < TAM; i++)
	{
		printf("Persona %d\n", i);
		printf("Nombre persona         : %s\n", alumnos[i].nombre);
		printf("Nombre completo persona: %s\n", alumnos[i].nombre_completo);
		printf("Edad persona           : %d\n", alumnos[i].edad);
		printf("\n\n");
	}
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
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
				"\033[1;31mERROR: El tipo de dato introducido no es valido.\n"
				"Por favor, intentelo de nuevo.\n"
				"-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}