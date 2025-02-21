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
#include <string.h>
#define TAM 20
typedef struct persona_t
{
	char nombre[TAM];
	int edad;
}persona_t;
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int i = 0;
    
    persona_t persona1 = {"Steve", 19};
	persona_t persona2, persona3;

	printf("Introduce nombre persona2: ");
	while(i < TAM - 1 && ((persona2.nombre[i] = getchar()) != '\n'))
	{
		i++;
	}
	persona2.nombre[i] = '\0';

	strcpy(persona3.nombre, "Guille");

	persona2.edad = 2; 
	persona3.edad = 2; 
	printf("Nombre: %s\n", persona1.nombre);
	printf("Edad:   %d\n", persona1.edad);
	printf("Nombre: %s\n", persona2.nombre);
	printf("Edad:   %d\n", persona2.edad);
	printf("Nombre: %s\n", persona3.nombre);
	printf("Edad:   %d\n", persona3.edad);
	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}