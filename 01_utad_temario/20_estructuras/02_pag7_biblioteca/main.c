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

struct autor_t
{
	char nombre[50];
	char apellido[50];
	char nacionalidad[50];
};

struct libro_t
{
	char titulo[50];
	char isbn[13];
	int  numPaginas;
	char editorial[20];
	struct autor_t autor;
};


void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    struct autor_t Steve;
	struct libro_t Curso_de_0_a_experto;
	
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}


