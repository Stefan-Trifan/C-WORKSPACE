/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
typedef struct alumno_t
{
	int id;
	int edad;
	float altura;
}
alumno_t;

// Funciones del programa

// Funciones auxiliares
float pedirFloat();
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int num_alumnos     = 0,
	    edad_menor      = 0,
	    altura_mas_alta = 0;

	printf("Introduce el numero de alumnos\n-> ");
	num_alumnos = pedirEnteroPos();

	alumno_t* p_alumno = (alumno_t*)malloc(sizeof(alumno_t) * num_alumnos);

	// Pedimos la edad de cada alumno
	for(int i = 0; i < num_alumnos; i++)
	{
		(p_alumno + i)->id = i + 1;
		printf("Alumno %d - Introduce la edad\n->", i + 1);
		(p_alumno + i)->edad = pedirEnteroPos();
	}

	// Pedimos la altura
	for(int i = 0; i < num_alumnos; i++)
	{
		printf("Alumno %d - Introduce la altura en cm\n->", i + 1);
		(p_alumno + i)->altura = pedirFloat();
	}

	// Buscamos el alumno con mayor altura
	altura_mas_alta = (p_alumno + 0)->altura;
	for(int i = 1; i < num_alumnos; i++)
		if((p_alumno + i)->altura > altura_mas_alta)
			altura_mas_alta = (p_alumno + i)->altura;

	// Buscamos el alumno con la edad mas pequenia
	edad_menor = (p_alumno + 0)->edad;
	for(int i = 1; i < num_alumnos; i++)
		if((p_alumno + i)->edad < edad_menor)
			edad_menor = (p_alumno + i)->edad;

	printf("\n\n");

	// Imprimimos los mas altos
	printf("=== ALUMNOS MAS ALTOS ===\n");
	for(int i = 0; i < num_alumnos; i++)
	{
		if((p_alumno + i)->altura == altura_mas_alta)
		{
			printf(
				"ID     : %d\n"
				"Edad   : %d\n"
				"Altura : %2f\n", 
				(p_alumno + i)->id, (p_alumno + i)->edad, (p_alumno + i)->altura);
				printf("\n");
		}
	}

	// Imprimimos los mas jovenes
	printf("=== ALUMNOS MAS JOVENES ===\n");
	for(int i = 0; i < num_alumnos; i++)
	{
		if((p_alumno + i)->edad == edad_menor)
		{
			printf(
				"ID     : %d\n"
				"Edad   : %d\n"
				"Altura : %2f\n", 
				(p_alumno + i)->id, (p_alumno + i)->edad, (p_alumno + i)->altura);
		}
	}
		
    free(p_alumno);

	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
float pedirFloat()
{
	float num = 0;
	int esValido = 0;
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. \n"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

int pedirEnteroPos()
{
	int num = 0, esValido = 0;
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0 || num < 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
				"-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}