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

#define ROW 2
#define COL 3

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    // Declaracion correcta del array
	int mtx[ROW][COL] = {
		{1, 2, 3}, 
		{4, 5, 6}
	};

	for (int i = 0; i < ROW; ++i){
		for (int j = 0 ; j < COL ; ++j){
			printf("%d ",mtx[i][j]);
		}
		printf("\n");
    }

	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}