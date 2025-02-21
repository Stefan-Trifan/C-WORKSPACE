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

    char str[TAM]; // 5 caracteres + '\0'
    int i = 0;

    while (i < TAM - 1 && (str[i] = getchar()) != '\n')
    {
        i++; // Incrementa i solo si el carácter es válido
    }
    str[i] = '\0'; // Agregar el terminador nulo

    printf("Leído: %s\n", str);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n')
        ;
}