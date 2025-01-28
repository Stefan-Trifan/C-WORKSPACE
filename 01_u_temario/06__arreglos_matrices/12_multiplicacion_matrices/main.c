/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: tbd

	* 	Enunciado X
		Arrays Multidimensionales: Multiplicación matrices
		Escribir un programa que calcule la multiplicación de dos matrices. Comprobad los resultados con la multiplicación de una matriz de 3x3 con una de 3x2.
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
    
    #include <stdio.h>

    int matriz1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

	int matriz2[3][2] = {
        {1, 2},
        {4, 5},
        {7, 8}
    };

	int matriz3[3][2];

    // Mostrar la matriz
    printf("La matriz1 es:\n");
    for (int i = 0; i < 3; i++) { // Filas
        for (int j = 0; j < 3; j++) { // Columnas
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }

    // Mostrar la matriz
    printf("La matriz2 es:\n");
    for (int i = 0; i < 3; i++) { // Filas
        for (int j = 0; j < 2; j++) { // Columnas
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }	

	printf("La multiplicación es: ");
	for (int i = 0; i < 3; i++) { // Filas
        for (int j = 0; j < 2; j++) { // Columnas
            printf("%d ", matriz2[i][j]);
        }
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