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
#include <stdlib.h>

// Funciones del programa

// Funciones auxiliares
int pedirEnteroPositivo();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	float edad_minima = 0,
	      suma_edades = 0,
	      edad_maxima = 0,
	      num_alumnos = 0;

	// Pedimos el num de alumnos
	printf("Introduce el num de alumnos\n-> ");
	num_alumnos = pedirEnteroPositivo();
	printf("\n");
    
    int* p_alumnos = (int*)malloc(sizeof(int) * num_alumnos);

	// Asignamos las edades
	for(int i = 0; i < num_alumnos; i++)
	{
		printf("Edad Alumno %d\n-> ", i + 1);
		*(p_alumnos + i) = pedirEnteroPositivo();
		suma_edades += *(p_alumnos + i);

		// Menor y mayor de las edades
		edad_minima = *p_alumnos;
		edad_maxima = *p_alumnos;
		// Buscamos la edad minima
		if(*(p_alumnos + i) < edad_minima)
		{
			edad_minima = *(p_alumnos + i);
		}
		// Buscamos la edad maxima
		if(*(p_alumnos + i) > edad_maxima)
		{
			edad_maxima = *(p_alumnos + i);
		}
	}

	// Edad media
	printf("\nLa edad media es: %.2f\n\n", suma_edades / num_alumnos);


	for(int i = 0; i < num_alumnos; i++)
	{

	}
	printf("La edad minima es: %.2f\n", edad_minima);
	printf("La edad maxima es: %.2f\n", edad_maxima);
	printf("\n");

	// Imprimimos las edades
	printf("Las edades son: \n");
	for(int i = 0; i < num_alumnos; i++)
	{
		printf("Edad Alumno %d: %d\n",i + 1, *(p_alumnos + i));
	}
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
int pedirEnteroPositivo()
{
	int num = 0, esValido = 0;
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0 || num < 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido.\n"
				"-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}
void clearBuffer()
{
	while (getchar() != '\n');
}