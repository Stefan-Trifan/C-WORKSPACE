/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: done

	* 	Enunciado X
		Escribe un programa que inicialice una matriz de orden 3 por 4, por filas
		y posteriormente la escriba por columnas (traspuesta)
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
	//Declaramos la matriz de 3x4
    int matriz[3][4];

	for (int fila = 0; fila < 3; fila++) { // Recorre las filas
		for (int col = 0; col < 4; col++) { // Recorre las columnas
			printf("Introduce un valor para [%d][%d]: ", fila, col);
			scanf("%d", &matriz[fila][col]); // Lee cada valor
		}
	}

	for (int col = 0; col < 4; col++) { // Recorre las columnas originales
		for (int fila = 0; fila < 3; fila++) { // Recorre las filas originales
			printf("%d ", matriz[fila][col]); // Imprime traspuesta
		}
    printf("\n"); // Salto de línea al final de cada columna
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