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

#define TAM 50

struct alumnos_padre 
{
	int edad;
	float altura;
	char nombre[TAM];
	char apellido[TAM];
};

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	struct alumnos_padre nuevo_alumno[TAM] = {
		{21, 1.81, "Steve", "Trifan"},
		{22, 2.81, "Carlos", "Trifan"}
	};

	nuevo_alumno[2].edad = 23;
	nuevo_alumno[2].altura = 3.80;
	strcpy(nuevo_alumno[2].nombre, "Santiago");
	strcpy(nuevo_alumno[2].apellido, "Trifan");


	printf("Edad:     %d\n", nuevo_alumno[0].edad);
	printf("Altura:   %.2f\n", nuevo_alumno[0].altura);
	printf("Nombre:   %s\n", nuevo_alumno[0].nombre);
	printf("Apellido: %s\n", nuevo_alumno[0].apellido);
	printf("\n");
	printf("Edad:     %d\n", nuevo_alumno[1].edad);
	printf("Altura:   %.2f\n", nuevo_alumno[1].altura);
	printf("Nombre:   %s\n", nuevo_alumno[1].nombre);
	printf("Apellido: %s\n", nuevo_alumno[1].apellido);
	printf("\n");
	printf("Edad:     %d\n", nuevo_alumno[2].edad);
	printf("Altura:   %.2f\n", nuevo_alumno[2].altura);
	printf("Nombre:   %s\n", nuevo_alumno[2].nombre);
	printf("Apellido: %s\n", nuevo_alumno[2].apellido);


    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}