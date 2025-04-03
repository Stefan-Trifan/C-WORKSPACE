/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: doing

	* 	Enunciado
		Escribe un programa que le pida al usuario los valores de una matriz cuadrada
		3x3, la presente por pantalla, y luego muestre la suma de todos los numeros de
		la diagonal principal.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int sumaDiagonal(int matriz[3][3]);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	//Declaramos la matriz de 3x3
    int matriz[3][3];

	for (int fila = 0; fila < 3; fila++) { // Recorre las filas
		for (int col = 0; col < 3; col++) { // Recorre las columnas
			printf("Introduce un valor para [%d][%d]: ", fila, col);
			scanf("%d", &matriz[fila][col]); // Lee cada valor
		}
	}

	for (int fila = 0; fila < 3; fila++) { // Recorre las columnas originales
		for (int col = 0; col < 3; col++){ // Recorre las filas originales
			printf("%d ", matriz[fila][col]); // Imprime traspuesta
		}
    	printf("\n"); // Salto de linea al final de cada columna
	}
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int sumaDiagonal(int matriz[3][3]){
	int suma = 0;

	for (int fila = 0; fila < 3; fila++) { // Recorre las filas
		for (int col = 0; col < 3; col++) { // Recorre las columnas
			if (fila == col){
				suma += matriz[fila][col];
			}
		}
	}

	return suma;
}

void clearBuffer()
{
	while (getchar() != '\n');
}