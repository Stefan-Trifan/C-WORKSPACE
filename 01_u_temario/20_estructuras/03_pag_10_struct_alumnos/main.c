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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>

#define TAM 50

struct alumnos_t 
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

	struct alumnos_t nuevo_alumno[TAM];

	nuevo_alumno[0].edad = 20;
	nuevo_alumno[0].altura = 1.80;
	strcpy(nuevo_alumno[0].nombre, "Santiago");
	strcpy(nuevo_alumno[0].apellido, "Castillo");


	printf("Edad:     %d\n", nuevo_alumno[0].edad);
	printf("Altura:   %.2f\n", nuevo_alumno[0].altura);
	printf("Nombre:   %s\n", nuevo_alumno[0].nombre);
	printf("Apellido: %s\n", nuevo_alumno[0].apellido);


    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}