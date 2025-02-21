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
struct persona
{
	char nombre[20];
	int edad;
};
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    struct persona persona1 = {"Steve", 19}, persona2;

	persona2.nombre = "Marcos"; 
	persona2.edad = 2; 

	printf("Nombre: %s\n", persona1.nombre);
	printf("Edad:   %d\n", persona1.edad);
	printf("Nombre: %s\n", persona2.nombre);
	printf("Edad:   %d\n", persona2.edad);
    
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