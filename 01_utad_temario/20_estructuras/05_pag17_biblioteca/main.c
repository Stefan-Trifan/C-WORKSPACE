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

#define MAX_LIBROS 100

#define TAM_TITULO 21
#define TAM_ISBN 14
#define TAM_EDITORIAL 21
#define TAM_AUTOR_NOMBRE 11
#define TAM_AUTOR_APELLIDO 11
#define TAM_AUTOR_NACIONALIDAD 11

struct autor_t
{
	char nombre[TAM_AUTOR_NOMBRE];
	char apellido[TAM_AUTOR_APELLIDO];
	char nacionalidad[TAM_AUTOR_NACIONALIDAD];
};
struct libro_t
{
	char titulo [TAM_TITULO];
	char ISBN[TAM_ISBN];
	int nPags;
	char editorial[TAM_EDITORIAL];
	struct autor_t autor;
};

// Funciones del enunciado
void imprimirLibro(struct libro_t biblioteca[MAX_LIBROS], int i);
void introducirLibro(struct libro_t biblioteca[MAX_LIBROS], int *contadorLibros);
void verLibros(struct libro_t biblioteca[MAX_LIBROS], int *contadorLibros);
void buscarLibros(struct libro_t biblioteca[MAX_LIBROS], int *contadorLibros);
// Funciones auxiliares
void pedirCadena(char texto[], int tam);
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int opcion         = 0,
	    contadorLibros = 0;
	struct libro_t biblioteca[MAX_LIBROS];
    
    do
	{
		// Menu
		printf(
			"\n********** MENu PRINCIPAL **********\n"
			"Por favor, introduce la opcion que deseas realizar a contunuacion: \n"
			"1. Introducir nuevo libro\n"
			"2. Ver libros\n"
			"3. Buscar Libro\n"
			"4. Salir\n");
		opcion = pedirEntero();

		switch (opcion)
		{
			case 1: 
				introducirLibro(biblioteca, &contadorLibros);
				break;
			case 2: 
				verLibros(biblioteca, &contadorLibros);
				break;
			case 3:
				buscarLibros(biblioteca, &contadorLibros);
				break;
			default: 
				printf("Saliendo del programa...\n");;
				break;
		}
	} 
	while (opcion != 4);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void imprimirLibro(struct libro_t biblioteca[MAX_LIBROS], int i)
{
	printf("LIBRO %d\n\n", i + 1);
	printf("Titulo libro:       %s\n", biblioteca[i].titulo);;
	printf("ISBN libro:         %s\n", biblioteca[i].ISBN);
	printf("Nr. Paginas libro:  %d\n", biblioteca[i].nPags);
	printf("Editorial libro:    %s\n", biblioteca[i].editorial);
	printf("Nombre autor:       %s\n", biblioteca[i].autor.nombre);
	printf("Apellido autor:     %s\n", biblioteca[i].autor.apellido);
	printf("Nacionalidad autor: %s\n", biblioteca[i].autor.nacionalidad);
	printf("_________________________________________ \n\n");
}

void introducirLibro(struct libro_t biblioteca[MAX_LIBROS], int *contadorLibros)
{
	printf("Has elegido la opcion \"Introducir libro\"\n\n");

	printf("Titulo libro: \n");
	pedirCadena(biblioteca[*contadorLibros].titulo, TAM_TITULO);
	printf("ISBN libro: \n");
	pedirCadena(biblioteca[*contadorLibros].ISBN, TAM_ISBN);
	printf("Nr. Paginas libro: \n");
	biblioteca[*contadorLibros].nPags = pedirEntero();
	printf("Editorial libro: \n");
	pedirCadena(biblioteca[*contadorLibros].editorial, TAM_EDITORIAL);
	printf("Nombre autor: \n");
	pedirCadena(biblioteca[*contadorLibros].autor.nombre, TAM_AUTOR_NOMBRE);
	printf("Apellido autor: \n");
	pedirCadena(biblioteca[*contadorLibros].autor.apellido, TAM_AUTOR_APELLIDO);
	printf("Nacionalidad autor: \n");
	pedirCadena(biblioteca[*contadorLibros].autor.nacionalidad, TAM_AUTOR_NACIONALIDAD);

	(*contadorLibros)++;
	printf("Nr. actual de libros en la bilbioteca: %d\n", *contadorLibros);
	printf("\n\n\n");
}

void verLibros(struct libro_t biblioteca[MAX_LIBROS], int *contadorLibros)
{
	printf("Has elegido la opcion \"Ver libros\"\n\n");

	printf("_________________________________________ \n\n");
	for(int i = 0; i < *contadorLibros; i++)
	{
		imprimirLibro(biblioteca, i);
	}

	printf("\n\n\n");
}

void buscarLibros(struct libro_t biblioteca[MAX_LIBROS], int *contadorLibros)
{
	char autorUsuario[TAM_AUTOR_NOMBRE] = {0};
	int encontrado = 0;

	printf("Has elegido la opcion \"Buscar libros\"\n\n");
	printf("Introduce el nombre del autor que quieres buscar \n");
	pedirCadena(autorUsuario, TAM_AUTOR_NOMBRE);

	printf("_________________________________________ \n\n");
	for(int i = 0; i < *contadorLibros; i++)
	{
		if (strcasestr(biblioteca[i].autor.nombre, autorUsuario) != NULL)
		{
			imprimirLibro(biblioteca, i);
			encontrado = 1;
		}
	}

	if(!encontrado)
	{
		printf("No se han encontrado coincidencias\n");
	}

	printf("\n\n\n");
}

// Funciones auxiliares
void pedirCadena(char texto[], int tam)
{
	int esValido = 1, i = 0;
	char newChar;

	printf("(Max. %d caracteres) -> ", tam - 1);

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

void clearBuffer()
{
	while (getchar() != '\n');
}
