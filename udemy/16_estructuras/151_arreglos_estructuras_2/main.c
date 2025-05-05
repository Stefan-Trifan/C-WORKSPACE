/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>
#define TAM 1
#define TAM_NOMBRE 3
#define TAM_NOMBRE_COMPLETO 3
typedef struct
{
	char nombre[TAM_NOMBRE];
	char nombre_completo[TAM_NOMBRE_COMPLETO];
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
	printf("\n_________________________________________START\n\n");
    
    persona_t alumnos[TAM];
	int j = 0;

	for(int i = 0; i < TAM; i++)
	{
		printf("Nombre persona %d\n-> ", i);
		while (j < TAM_NOMBRE - 1 && (alumnos[i].nombre[j] = getchar()) != '\n')
		{
			j++;
		}
		alumnos[i].nombre[j] = '\0';
		clearBuffer();

		printf("Nombre completo persona %d\n-> ", i);
		j = 0;
		while (j < TAM_NOMBRE_COMPLETO - 1 && (alumnos[i].nombre_completo[j] = getchar()) != '\n')
		{
			j++;
		}
		alumnos[i].nombre_completo[j] = '\0';
		clearBuffer();

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
    
	printf("\n_________________________________________EXIT\n\n");
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