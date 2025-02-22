/*
        *	Autor
                Stefan Trifan

        *   Estado

        * 	Enunciado X
                LoremIpsum
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

    printf("Leído: %s\n", nombre);

    printf("\n_________________________________________END\n\n");
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