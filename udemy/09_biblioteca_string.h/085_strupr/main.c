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

// strupr(Cadena)
// Contrario a strlwr, esta función convierte a mayúsculas las letras de una cadena.
//! En Linux no funciona

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char texto[100];

	printf("Introduce la cadena para convertir a mayusculas: ");
	scanf("%s", texto);

	strupr(texto);

	printf("El nuevo en mayusculas es el siguiente: %s", texto);

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}