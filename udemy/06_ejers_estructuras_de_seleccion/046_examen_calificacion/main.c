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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char nota = ' ';

	do {
		printf("Introduce la calificacion (A, B, C, D, F): ");
		scanf(" %c", &nota);
	} while (nota < 'A' || nota > 'F');
	
	switch (nota) {
		case 'A': 
			printf("Excelente");
			break;
		case 'B': 
			printf("Notable");
			break;
		case 'C': 
			printf("Aprobado");
			break;
		case 'D': 
		case 'F': 
			printf("Reprobado");
			break;
		default: 
			printf("Nota no válida");
			break;
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}