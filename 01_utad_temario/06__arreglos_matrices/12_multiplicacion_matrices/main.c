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

	* 	Enunciado
		Arrays Multidimensionales: Multiplicacion matrices
		Escribir un programa que calcule la multiplicacion de dos matrices. Comprobad los resultados con la multiplicacion de una matriz de 3x3 con una de 3x2.
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

	printf("La multiplicacion es: ");
	for (int i = 0; i < 3; i++) { // Filas
        for (int j = 0; j < 2; j++) { // Columnas
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }	

    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}