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
#define TAM_NOMBRE 10

union datos_u
{
	int edad;
	float peso;
	char nombre[TAM_NOMBRE];
};
struct datos_t
{
	int edad;
	float peso;
	char nombre[TAM_NOMBRE];
};

// Funciones del programa

// Funciones auxiliares
float pedirFloat();
void pedirCadena(char texto[], int tam);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	// Inicializamos union y struct
    union datos_u persona_eficiente;
	struct datos_t persona_ineficiente;

	// Recogemos datos
	printf("Introduce la edad mediante datos_u\n");
	persona_eficiente.edad = pedirEntero();

	printf("Introduce la edad mediante datos_t\n");
	persona_ineficiente.edad = pedirEntero();

	printf("Introduce el peso mediante datos_u\n");
	persona_eficiente.peso = pedirFloat();

	printf("Introduce el peso mediante datos_t\n");
	persona_ineficiente.peso = pedirFloat();

	printf("Introduce el nombre mediante datos_u\n");
	pedirCadena(persona_eficiente.nombre, TAM_NOMBRE);
	
	printf("Introduce el nombre mediante datos_t\n");
	pedirCadena(persona_ineficiente.nombre, TAM_NOMBRE);

	printf("\n\n");

	// Imprimimos la union
	printf(
		"DATOS union\n"
		"Edad:   %d\n"
		"Peso:   %f\n"
		"Nombre: %s\n"
		"Tamaño de datos_u: %lu bytes\n", 
		persona_eficiente.edad, 
		persona_eficiente.peso, 
		persona_eficiente.nombre, 
		sizeof(persona_eficiente));

	printf("\n\n");

	// Imprimimos la estructura
	printf(
		"DATOS struct\n"
		"Edad:   %d\n"
		"Peso:   %f\n"
		"Nombre: %s\n"
		"Tamaño de datos_t: %lu bytes\n", 
		persona_ineficiente.edad, 
		persona_ineficiente.peso, 
		persona_ineficiente.nombre, 
		sizeof(persona_ineficiente));
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa


// Funciones auxiliares
float pedirFloat()
{
	float num = 0;
	int esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. "
				"Por favor, intentelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}
int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. "
				"Por favor, intentelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}
void pedirCadena(char texto[], int tam)
{
	int esValido = 1, i = 0;
	char newChar;

	printf("Introduce la cadena (maximo %d caracteres):\n", tam - 1);
	printf("-> ");

	do
	{
		esValido = 1;
		i = 0;
		// Leer la entrada hasta '\n' o hasta que se llene el array (dejando espacio para '\0')
		while (((newChar = getchar()) != '\n') && (i < tam - 1))
		{
			texto[i] = newChar;
			i++;
		}
		texto[i] = '\0'; // Finalizar la cadena

		if (i == tam - 1 && newChar != '\n')
		{
			printf("\033[1;31mERROR: Has superado el tamaño. Por favor, intentelo de nuevo. \n\033[0m"
				   "\033[1;31m-> \033[0m");
			clearBuffer();
			esValido = 0;
		}
	} while (!esValido);
}
void clearBuffer()
{
	while (getchar() != '\n');
}