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
		Escriba un programa en C que solicite al usuario ingresar el numero total de estudiantes en un curso de Algoritmos. 
		Luego, el programa debera pedir uno por uno el sexo de cada estudiante, permitiendo las opciones "hombre", "mujer" y cualquier otro valor como "indeterminado". 
		Finalmente, el programa debe mostrar cuantos estudiantes son hombres, cuantos son mujeres y cuantos tienen un sexo no especificado correctamente.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define SEXO 6
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
	int num_alumnos        = 0,
	    num_mujeres        = 0,
	    num_hombres        = 0,
	    num_indeterminados = 0;
	char alumnos[50][SEXO] = {0};

	printf("Introduce un numero de alumnos (maximo 50): \n");
	num_alumnos = pedirEntero();
	printf("\n");

	// Pedimos el genero de cada alumno
	printf("Introduce el genero para cada alumno (man OR woman)\n");
	for(int i = 0; i < num_alumnos; i++)
	{
		printf("Genero alumno[%d]: ", i + 1);
		for(int j = 0; j < SEXO; j++)
		{
			alumnos[i][j] = getchar();
			if(alumnos[i][j] == '\n')
			{
				alumnos[i][j] = '\0';
				break;
			}
		}
	}
	printf("\n");

	// Recorremos el array comprobando elemento por elemento si es hombre o mujer
	for(int i = 0; i < num_alumnos; i++)
	{
		if(
			alumnos[i][0] == 'w' && 
			alumnos[i][1] == 'o' && 
			alumnos[i][2] == 'm' && 
			alumnos[i][3] == 'a' && 
			alumnos[i][4] == 'n')
		{
			num_mujeres++;
		}
		else if(
			alumnos[i][0] == 'm' && 
			alumnos[i][1] == 'a' && 
			alumnos[i][2] == 'n')
		{
			num_hombres++;
		}
		else
		{
			num_indeterminados++;
		}
	}

	printf(
		"Hombres:        %d\n"
		"Mujeres:        %d\n"
		"Indeterminados: %d", num_hombres, num_mujeres, num_indeterminados);

    printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0 || num <= 0 || num > 50)
		{
			printf(
				"\033[1;31mERROR: El numero debe estar comprendido entre 1 y 50\n\033[0m"
				"\033[1;31m--> \033[0m"
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