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

#include <stdlib.h>
#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char * argv[])
{
	printf("\n_________________________________________START\n\n");

	float contNumeros = 0, sumaNumeros = 0, resultadoMedia = 0;

	for(int i = 1; i < argc; i++)
	{
		if(*argv[i] >= '0' && *argv[i] <= '9')
		{
			float temp =  strtol(argv[i], NULL, 10);
			sumaNumeros += temp;
			contNumeros++;
		}
	}

	resultadoMedia = sumaNumeros / contNumeros;

	printf("La media es: %.2f\n", resultadoMedia);

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}