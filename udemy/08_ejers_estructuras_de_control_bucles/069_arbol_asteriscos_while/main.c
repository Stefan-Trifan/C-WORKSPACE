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
		*
		**
		***
		****
		*****
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

	int numFilas = 0, numEstrellasFila = 0;
    
    printf("Cuantas filas de asteriscos quieres: ");
	scanf("%d", &numFilas);

	// Bucle que se encarga de crear las filas de una en una
	for(int filaActual = 0; filaActual <= numFilas; filaActual++)
	{
		
		// Bucle que se encarga de imprimir las estrellas en la fila actual
		while(numEstrellasFila < filaActual)
		{
			printf("*");
			numEstrellasFila++;
		}

		// Al final de cada fila, insertamos salto de linea y reseteamos las estrellas
		numEstrellasFila = 0;
		printf("\n");
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