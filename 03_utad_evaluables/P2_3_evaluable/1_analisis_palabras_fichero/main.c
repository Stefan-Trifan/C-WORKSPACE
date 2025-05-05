/*
    *   Autor
        Stefan Trifan
    
    *   Testing
        ./main datos.txt Hola
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Estructura para almacenar la información de las palabras que se van a buscar
typedef struct 
{
    char *palabra;
    int num_ocurrencias;
    int *numeros_de_linea;
} 
palabra_info_t;

// Estructura para almacenar la lista de información
typedef struct 
{
    palabra_info_t *lista_palabras;
    int num_palabras;
} 
lista_palabras_t;

// Funciones del programa
void examinaLinea(char *linea_aux, int num_linea, lista_palabras_t lista_palabras);
void escribirResultado(lista_palabras_t lista, char *nombre_fichero_origen);

// Funciones auxiliares
char *leeLineaDinamicaFile(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd_in;
    FILE *fd_out;

    // Comprobamos el numero de parametros
    if(argc < 3) 
    {
        printf(RED"Error. Uso: ./main <Nombre de fichero> <Palabras a buscar>\n"RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Comprobamos si el archivo existe
    fd_in = fopen(argv[1], "r");
    if(fd_in == NULL)
    {
        printf(RED"ERROR: El archivo no se ha encontrado"RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Creamos el archivo de salida
    fd_out = fopen(strcat(argv[1], ".out"), "w");

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
void examinaLinea(char *linea_aux, int num_linea, lista_palabras_t lista_palabras)
{

}

/**
 * Abre el fichero de escritura obteniendo el nombre a partir del nombre 
 * del fichero origen y escribe para cada palabra encontrada: la palabra, 
 * el número de ocurrencias y las líneas en las que aparece, si una 
 * palabra aparece varias veces en una línea aparecerá duplicada en la lista
 */
void escribirResultado(lista_palabras_t lista, char *nombre_fichero_origen)
{

}

// Funciones auxiliares
/**
 * Esta función obtiene la siguiente línea de un fichero ya abierto y devuelve 
 * un puntero a la cadena con memoria reservada dinámicamente. Utiliza fgetc
 */
char *leeLineaDinamicaFile(FILE *fd)
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    while ((c = fgetc(fd)) != EOF)
    {
        if (i == memoria_actual - 1)
        {
            memoria_actual += TAM_BLOQUE;
            p_texto_destino = realloc(p_texto_destino, memoria_actual * sizeof(char));
        }
        p_texto_destino[i] = c;
        i++;
    }
    p_texto_destino[i] = '\0';

    return p_texto_destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}