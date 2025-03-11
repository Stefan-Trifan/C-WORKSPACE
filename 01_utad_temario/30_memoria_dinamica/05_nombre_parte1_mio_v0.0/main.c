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

	char nombre_alumno = 0;
	char *p_nombre_alumno = &nombre_alumno;
	int num_caracteres_usuario = 0, i = 0;
    char c;

	printf("Introduce tu nombre\n-> ");
	do
	{
		c = getchar();

		if(c == '\n') break;

		char* p_nombre_alumno = (char *)malloc(sizeof(char));
		*(p_nombre_alumno + i) = c;
	} 
	while (c != '\n');
	*(p_nombre_alumno + i) = '\0';

	printf("Nombre es: %s\n", p_nombre_alumno);
	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
char *leeLineaDinamica()
{
	return 0;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}