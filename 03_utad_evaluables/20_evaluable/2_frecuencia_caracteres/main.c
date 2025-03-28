/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 2 - Frecuencia de caracteres
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

typedef struct char_info_t
{
    char letra;
    int contador;
} char_info_t;

// Funciones del programa
int buscarCaracter(char_info_t *lista, int tam, char c);
int tamCadena(char *cadena);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables

    // Comprobamos que el usuario introduce al menos un caracter
    if (argc == 1)
    {
        printf(RED "Error: Tienes que introducir al menos un caracter\n"
                   "USO  : ./main a b a c d a b\n"
                   "\n_________________________________________EXIT_FAILURE\n\n" RESET);
        return EXIT_FAILURE;
    }

    // Guardamos los caracteres en un array de estructuras
    // Contamos los caracteres repetidos
    // Ignoramos aquellos valores que sean una cadena de más de un carácter.

    // Mostramos por pantalla los caracteres repetidos y sus frecuencias

    // Liberamos memoria reservada

    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 *  Función para buscar un carácter en la lista de tamanio tam
 */
int buscarCaracter(char_info_t *lista, int tam, char c) { return 0; }
/**
 * Función que se le pasa como parámetro una cadena y devuelve
 * el número de caracteres que tiene
 */
int tamCadena(char *cadena) { return 0; }

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n')
        ;
}