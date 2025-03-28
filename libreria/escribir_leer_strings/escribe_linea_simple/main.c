/*
        *	Autor
            Stefan Trifan

        *   Estado

        * 	Enunciado
            Esta funcion se queda solo con los caracteres necesarios
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 5
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char nombre[TAM]; 

    int i = 0;
    while (i < TAM - 1 && (nombre[i] = getchar()) != '\n')
    {
        i++; 
    }
    nombre[i] = '\0'; 
    clearBuffer();

    printf("Leido: %s\n", nombre);

    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}