/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar la información de las palabras que se van a buscar
typedef struct 
{
    char *palabra;
    int ocurrencias;
    int *numeros_de_linea;
} 
palabraInfo_t;

// Estructura para almacenar la lista de información
typedef struct 
{
    palabraInfo_t *lista_palabras;
    int num_palabras;
} 
listaPalabras_t;

// Funciones del programa
void examinaLinea(char *lineaAux, int numLinea, listaPalabras_t listaPalabras);
char *leeLineaDinamicaFile(FILE *fd);
void escribirResultado(listaPalabras_t lista, char *nombreFichOrigen);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    if(argc < 3)
    {
        printf("USO: ./main <Nombre de fichero> <Palabras a buscar>\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Declaracion de variables


    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Esta función recibe una línea y el número de línea y modifica 
 * la lista de palabras para añadir la información encontrada. 
 */
void examinaLinea(char *lineaAux, int numLinea, listaPalabras_t listaPalabras)
{

}

/**
 * Esta función obtiene la siguiente línea de un fichero ya abierto y devuelve 
 * un puntero a la cadena con memoria reservada dinámicamente. Utiliza fgetc
 */
char *leeLineaDinamicaFile(FILE *fd)
{
    char *c;
    return c;
}

/**
 * Abre el fichero de escritura obteniendo el nombre a partir del nombre 
 * del fichero origen y escribe para cada palabra encontrada: la palabra, 
 * el número de ocurrencias y las líneas en las que aparece, si una 
 * palabra aparece varias veces en una línea aparecerá duplicada en la lista
 */
void escribirResultado(listaPalabras_t lista, char *nombreFichOrigen)
{

}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}