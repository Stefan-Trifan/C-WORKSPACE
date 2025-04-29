/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado
		./main Castro, Alfonso
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM_STR 50
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    if(argc < 3)
	{
		printf("\033[1;31mERROR: Faltan argumentos");
		printf("\n_________________________________________EXIT_FAILUREn\n");
		return 1;
	}

	int pos_string_coma   = 0,
	    pos_caracter_coma = 0;
	char nombre[TAM_STR] = {0};
	char apellido[TAM_STR] = {0};
	
	// Buscamos los indices de la coma
	for(int i = 1; i < argc; i++)
	{
		int j = 0;
		while(argv[i][j] != '\0')
		{
			if(argv[i][j] == ',')
			{
				pos_string_coma   = i;
				pos_caracter_coma = j;
			}
			j++;
		}
	}
	printf("pos_string_coma   : %d\n", pos_string_coma);
	printf("pos_caracter_coma : %d\n\n", pos_caracter_coma);

	// Guardamos dentro de nombre las palabras de despues de la coma
	{
		int k = 0;
		for(int i = pos_string_coma + 1; i < argc; i++)
		{
			int j = 0;
			while(argv[i][j] != '\0')
			{
				nombre[k] = argv[i][j];
				j++;
				k++;
			}
			if(i < argc - 1)
			{
				nombre[k] = ' ';
				k++;
			}
		}
		nombre[k] = '\0';
	}
	printf("NOMBRE   : %s\n", nombre);

	// Guardamos dentro de apellido las palabras de antes de la coma
	// ./main ape1\0 ape2\0, nombre1 nombre2
	{
		int k = 0;
		for(int i = 1; i <= pos_string_coma; i++)
		{
			int j = 0;
			while(argv[i][j] != '\0')
			{
				apellido[k] = argv[i][j];
				j++;
				k++;
			}
			if(i < pos_string_coma)
			{
				apellido[k] = ' ';
				k++;
			}
		}
		apellido[k - 1] = '\0';
	}
	
	printf("APELLIDO : %s\n\n", apellido);

	// Imprimimos nombre apellido
	printf("El nombre del alumno es %s, %s\n", nombre, apellido);
    
	printf("\n_________________________________________EXIT\n\n");
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