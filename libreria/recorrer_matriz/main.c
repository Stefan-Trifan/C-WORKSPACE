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

#define NUMFILAS 2
#define NUMCOL 3

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    // Declaración correcta del array
	int elementos[NUMFILAS][NUMCOL] = {{1, 2, 3}, {4, 5, 6}};

	int indiceFila, indiceCol;
	for (indiceFila = 0; indiceFila < NUMFILAS; ++indiceFila){
		for (indiceCol=0 ; indiceCol < NUMCOL ; ++indiceCol){
			printf("%d\n",elementos[indiceFila][indiceCol]);
		}
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