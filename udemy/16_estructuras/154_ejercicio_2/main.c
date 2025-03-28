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
#define TAM 4

typedef struct asignatura_t
{
	char materia[30];
}asignatura_t;

typedef struct alumno_t
{
	asignatura_t asignaturas[5];
}alumno_t;
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	alumno_t Jorge, Juan;
	strcpy(Jorge.asignaturas[0].materia, "Matematicas");
	strcpy(Jorge.asignaturas[1].materia, "Fisica");
	strcpy(Jorge.asignaturas[2].materia, "Quimica");

	strcpy(Juan.asignaturas[0].materia, "Musica");
	strcpy(Juan.asignaturas[1].materia, "Tecnologia");
	strcpy(Juan.asignaturas[2].materia, "Religion");
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
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