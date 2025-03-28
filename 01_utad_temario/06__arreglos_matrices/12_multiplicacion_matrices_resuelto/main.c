/*
    *   Autor
        Stefan Trifan

    *   Compilar
        mac     : comp
                  run
                  brun
        windows : gcc main.c -o main.exe
                : ./main.exe

    *   Estado: doing

    *   Enunciado
        Arrays Multidimensionales: Multiplicacion matrices
        Escribir un programa que calcule la multiplicacion de dos matrices. Comprobad los resultados con la multiplicacion de una matriz de 3x3 con una de 3x2.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define MAX_ROW_3 3
#define MAX_COL_2 2

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]) {
    printf("\n_________________________________________START\n\n");

    // Declaramos las matrices
    int matriz1[MAX_ROW_3][MAX_ROW_3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriz2[MAX_ROW_3][MAX_COL_2] = {
        {1, 4},
        {2, 5},
        {3, 6}
    };

    int resultado[MAX_ROW_3][MAX_COL_2] = {0}; // Inicializamos con ceros

    // Multiplicacion de las matrices
    for (int row = 0; row < MAX_ROW_3; row++) {
        for (int col = 0; col < MAX_COL_2; col++) {
            resultado[row][col]=0; // Reinicializamos los valores
            for (int indice = 0; indice < MAX_ROW_3; indice++) {
                resultado[row][col] += matriz1[row][indice] * matriz2[indice][col];
            }
        }
    }

    // Mostramos el resultado de la multiplicacion
    printf("El resultado de la multiplicacion es:\n");
    for (int row = 0; row < MAX_ROW_3; row++) {
        for (int col = 0; col < MAX_COL_2; col++) {
            printf("%d ", resultado[row][col]);
        }
        printf("\n");
    }

    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer() {
    while (getchar() != '\n');
}
