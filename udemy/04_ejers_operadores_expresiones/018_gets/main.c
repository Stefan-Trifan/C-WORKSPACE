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

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */


int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	// Declara una cadena de caracteres para el nombre
	char nombre[40];
	
	// Solicita al usuario que introduzca su nombre
	printf("Introduce tu nombre: \n");
	
	// Lee el nombre introducido por el usuario
	gets(nombre);
	
	// Imprime el nombre introducido por el usuario
	printf("Tu nombre es: %s", nombre);
	
	// Retorna 0 indicando que el programa termino correctamente
	return 0;
}



/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}