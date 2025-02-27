/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 3 
        Lista de objetos
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

typedef struct objeto_t
{
    int id;
    float peso;
    char categoria;
}objeto_t;

// Funciones del programa
int procesarObjetos();
int guardarObjetos();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    objeto_t objeto[10];

    // Comprobamos el formato de los argumentos

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Comprobamos
 * - El formato de los argumentos es correcto
 * - El usuario no supera el limite de objetos
 */
int procesarObjetos()
{
    return 0;
}
/**
 * Guardamos los objetos en nuestro array de estructuras
 * 
 */
int guardarObjetos()
{
    return 0;
}


// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}