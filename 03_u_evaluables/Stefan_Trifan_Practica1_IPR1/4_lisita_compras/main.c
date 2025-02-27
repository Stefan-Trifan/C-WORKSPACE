/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 4 
        Lista de la compra

    *   Testing
        
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM_ARR 10
#define TAM_STR 16

typedef struct ingrediente_t
{

}ingrediente_t;

// Funciones del programa
void introducirIngrediente();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    ingrediente_t ingrediente[TAM_ARR][TAM_STR];

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * 
 */
void listarIngredientes()
{
    
}
/**
 * 
 */
void introducirIngrediente()
{

}
/**
 * 
 */
void eliminarIngrediente()
{

}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}