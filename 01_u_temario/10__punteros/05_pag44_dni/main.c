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

#include <stdlib.h>
#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	int numeroDni = 0, resto;
	char letrasDNI[23] = 
	{
		'T','R','W','A','G','M','Y','F','P','D',
		'X','B','N','J','Z','S','Q','V','H','L',
		'C','K','E'
	};

	if(argc != 2)
	{
		printf("Ha ocurrido un error. Por favor, intentelo de nuevo.\n\n\n");
		return 1;
	}

	numeroDni = strtol(argv[1], NULL, 10);
	resto = numeroDni % 23;
	char miLetra = letrasDNI[resto];
	
	printf("%d%c\n", numeroDni, miLetra);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}