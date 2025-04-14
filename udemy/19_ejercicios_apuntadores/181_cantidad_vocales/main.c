/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa
int vocalA(char *);
int vocalE(char *);
int vocalI(char *);
int vocalO(char *);
int vocalU(char *);
// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char palabra[100];
    fgets(palabra, 99, stdin);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
int vocalA(char *)
{

}

int vocalE(char *)
{

}

int vocalI(char *)
{

}

int vocalO(char *)
{

}

int vocalU(char *)
{

}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}