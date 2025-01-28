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
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 20

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
	char nombre[TAM];
	char apellido[TAM];

	printf("Ingrese su nombre: ");
	scanf("%s", nombre);
	printf("Su nombre es: %s\n", nombre);

	printf("Introduce su apellido: ");
	scanf("%s", apellido);
	printf("Su apellido es: %s\n", apellido);

    
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}