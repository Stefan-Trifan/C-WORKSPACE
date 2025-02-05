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

//* strcpy(Destino, Fuente)
//* Permite copiar una cadena de texto en otra. Debes considerar que la dimensión del array
//* destino debe ser igual o mayor que el array origen y que además sobrescribe el contenido del
//* destino (de existir).

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h> // Nueva biblioteca

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	char arrayOrigen[20]  = "Cadena de origen";
	char arrayDestino[20] = ""; 

	// Ejemplo 1: Copiamos el contenido de una variable a otra

	strcpy(arrayDestino, arrayOrigen); // copiamos el contenido de la variable origen a la variable destino
	printf("%s\n", arrayDestino); // Devuelve "Cadena de origen"

	// Ejemplo 2: Copiamos el contenido una cadena a una variable

	strcpy(arrayDestino, "Hola Hola Hola"); // copiamos el contenido "Hola Hola Hola" a la variable destino
	printf("%s\n", arrayDestino);  // Devuelve "Hola Hola Hola
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}
