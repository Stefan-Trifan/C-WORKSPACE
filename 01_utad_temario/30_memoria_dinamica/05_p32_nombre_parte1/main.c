/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado 23
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

// Funciones del programa
char *leeLineaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char *nombre;

	printf("Introduce tu nombre\n-> ");
	nombre = leeLineaDinamica();
	printf("Nombre es: %s\n", nombre);

	free(nombre);

	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *leeLineaDinamica()
{
	char *p_nombre_alumno = malloc(sizeof(char)), c;
	int i = 0;
	while((c = getchar()) != '\n')
	{
		p_nombre_alumno = realloc(p_nombre_alumno, (i + 1) * sizeof(char));
		*(p_nombre_alumno + i) = c;
		i++;
	}
	*(p_nombre_alumno + i) = '\0';

	return p_nombre_alumno;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}