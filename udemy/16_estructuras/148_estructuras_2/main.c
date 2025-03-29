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
#define TAM 20
typedef struct persona_t
{
	char nombre[TAM];
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

	int i = 0;
    
    persona_t persona1, persona3;


	printf("Escribe tu nombre\n-> ");
	fgets(persona1.nombre, sizeof(persona1.nombre), stdin);
	persona1.nombre[strcspn(persona1.nombre, "\n")] = '\0';
	printf("Escribe tu edad\n-> ");
	persona1.edad = pedirEntero();

	printf("Escribe tu nombre\n-> ");
	fgets(persona3.nombre, sizeof(persona3.nombre), stdin);
	persona3.nombre[strcspn(persona3.nombre, "\n")] = '\0';
	printf("Escribe tu edad\n-> ");
	persona3.edad = pedirEntero();
	
	printf("Nombre: %s\n", persona1.nombre);
	printf("Edad:   %d\n", persona1.edad);
	printf("Nombre: %s\n", persona3.nombre);
	printf("Edad:   %d\n", persona3.edad);
	
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
int pedirEntero()
{
	int esValido = 0, num;
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if(esValido != 1)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido.\n"
				"Por favor, intentelo de nuevo.\n"
				"-> \033[0m"
			);
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