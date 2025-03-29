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
#include <string.h>

#define TAM_STRUCT 10
#define TAM_STRING 50

struct alumnos_padre 
{
	int edad;
	float altura;
	char nombre[TAM_STRING];
	char apellido[TAM_STRING];
};
void imprimirDatosAlumnoValor(struct alumnos_padre nuevo_alumno[TAM_STRUCT]);
void imprimirDatosAlumnoReferencia(struct alumnos_padre *nuevo_alumno);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	struct alumnos_padre nuevo_alumno[TAM_STRUCT] = {
		{21, 1.81, "Steve", "Trifan"},
		{22, 2.81, "Carlos", "Apellido"},
		{23, 3.81, "Pablo", "Apellido"},
		{24, 4.81, "Hugo", "Apellido"},
		{25, 5.81, "Alfredo", "Apellido"},
		{26, 6.81, "Alfonso", "Apellido"}
	};

	imprimirDatosAlumnoValor(nuevo_alumno);
	imprimirDatosAlumnoReferencia(nuevo_alumno);

	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void imprimirDatosAlumnoValor(struct alumnos_padre nuevo_alumno[TAM_STRUCT])
{
	printf("IMPRIME MIEMBROS DE LA ESTRUCTURA POR VALOR\n\n");
	printf("Edad valor     : %d\n", nuevo_alumno[0].edad);
	printf("Altura valor   : %.2f\n", nuevo_alumno[0].altura);
	printf("Nombre valor   : %s\n", nuevo_alumno[0].nombre);
	printf("Apellido valor : %s\n", nuevo_alumno[0].apellido);
	printf("\n");
	printf("Edad valor     : %d\n", nuevo_alumno[1].edad);
	printf("Altura valor   : %.2f\n", nuevo_alumno[1].altura);
	printf("Nombre valor   : %s\n", nuevo_alumno[1].nombre);
	printf("Apellido valor : %s\n", nuevo_alumno[1].apellido);
	printf("\n\n");
}

void imprimirDatosAlumnoReferencia(struct alumnos_padre *nuevo_alumno)
{
	printf("IMPRIME MIEMBROS DE LA ESTRUCTURA POR REFERENCIA\n\n");
	for(int i = 0; i < TAM_STRUCT; i++)
	{
		printf("Edad referencia     : %d\n", (nuevo_alumno + i)->edad);
		printf("Altura referencia   : %.2f\n", (nuevo_alumno + i)->altura);
		printf("Nombre referencia   : %s\n", (nuevo_alumno + i)->nombre);
		printf("Apellido referencia : %s\n", (nuevo_alumno + i)->apellido);
		printf("\n");
	}
}

void clearBuffer()
{
	while (getchar() != '\n');
}