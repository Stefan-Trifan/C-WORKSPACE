/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado
		Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

typedef enum estaciones_t 
{
	primavera, verano, otonio, invierno, error
}
estaciones_t;

// Funciones del programa
void compararCadena(char estacion_usuario[10], estaciones_t *estacion_actual);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	if(argc != 2)
	{
		printf(RED"Error: Debes introducr 1 estacion");
		printf("\n_________________________________________EXIT_FAILURE\n\n"RESET);
		return 1;
	}

	estaciones_t estacion_actual;
	char estacion_usuario[10] = {0};

	strcpy(estacion_usuario, argv[1]);

	compararCadena(estacion_usuario, &estacion_actual);

	switch (estacion_actual)
	{
		case primavera: 
			printf("La naturaleza renace con colores vibrantes y días más cálidos");;
			break;
		case verano: 
			printf("El sol brilla intensamente y las vacaciones traen diversión y descanso.");
			break;
		case otonio: 
			printf("Las hojas caen, el aire se enfría y los paisajes se tiñen de tonos dorados.");
			break;
		case invierno:
			printf("El frio abraza el paisaje mientras la nieve y la calidez del hogar se disfrutan.");
			break;
		case error:
			return 1;
	}

	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
void compararCadena(char estacion_usuario[10], estaciones_t *estacion_actual)
{
	if(
		estacion_usuario[0] == 'p' && 
		estacion_usuario[1] == 'r' &&
		estacion_usuario[2] == 'i' && 
		estacion_usuario[3] == 'm' &&
		estacion_usuario[4] == 'a' && 
		estacion_usuario[5] == 'v' &&
		estacion_usuario[6] == 'e' && 
		estacion_usuario[7] == 'r' &&
		estacion_usuario[8] == 'a')
	{
		*estacion_actual = primavera;
	}
	else if(
		estacion_usuario[0] == 'v' && 
		estacion_usuario[1] == 'e' &&
		estacion_usuario[2] == 'r' && 
		estacion_usuario[3] == 'a' &&
		estacion_usuario[4] == 'n' && 
		estacion_usuario[5] == 'o')
	{
		*estacion_actual = verano;
	}
	else if(
		estacion_usuario[0] == 'o' && 
		estacion_usuario[1] == 't' &&
		estacion_usuario[2] == 'o' && 
		estacion_usuario[3] == 'n' &&
		estacion_usuario[4] == 'i' && 
		estacion_usuario[5] == 'o')
	{
		*estacion_actual = otonio;
	}
	else if(
		estacion_usuario[0] == 'i' && 
		estacion_usuario[1] == 'n' &&
		estacion_usuario[2] == 'v' && 
		estacion_usuario[3] == 'i' &&
		estacion_usuario[4] == 'e' && 
		estacion_usuario[5] == 'r' &&
		estacion_usuario[6] == 'n' && 
		estacion_usuario[7] == 'o')
	{
		*estacion_actual = invierno;
	}
	else
	{
		printf(YELLOW"Opciones: primavera, verano, otonio, invierno\n");
		*estacion_actual = 4;
		printf("\n_________________________________________EXIT_SUCCESS\n\n"RESET);
	}

}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}