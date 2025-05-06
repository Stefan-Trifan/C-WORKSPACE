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
void examinaLinea(char *linea_aux, int num_linea, lista_palabras_t caja_lista_palabras);
void escribirResultado(lista_palabras_t caja_lista_palabras, char *nombre_fichero_origen);

// Funciones auxiliares
char *leerLineaDinamicaFichero(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    lista_palabras_t caja_lista_palabras;
    FILE *fd_entrada;
    FILE *fd_salida;
    char *nombre_fichero_salida;

    // Comprobamos el numero de parametros
    if(argc < 3) 
    {
        printf(RED"Error. Uso: ./main <Nombre de fichero> <Palabras a buscar>\n"RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Comprobamos si el archivo existe
    fd_entrada = fopen(argv[1], "r");
    if(fd_entrada == NULL)
    {
        printf(RED"ERROR: El archivo no se ha encontrado"RESET);
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Creamos el archivo de salida
    nombre_fichero_salida = malloc((strlen(argv[1]) + 5) * sizeof(char));
    strcpy(nombre_fichero_salida, argv[1]);
    strcat(nombre_fichero_salida, ".out");
    fd_salida = fopen(nombre_fichero_salida, "w");

    // Iniciamos la lista de palabras
    caja_lista_palabras.num_palabras = argc - 2;
    caja_lista_palabras.lista_palabras = malloc(caja_lista_palabras.num_palabras * sizeof(palabra_info_t));
    for(int i = 0; i < caja_lista_palabras.num_palabras; i++)
    {
        // Guardamos las palabras
        caja_lista_palabras.lista_palabras[i].palabra = malloc(sizeof(char) * (strlen(argv[i+2]) + 1));
        strcpy(caja_lista_palabras.lista_palabras[i].palabra, argv[i + 2]);
        caja_lista_palabras.lista_palabras[i].num_ocurrencias = 0;
        caja_lista_palabras.lista_palabras[i].numeros_de_linea = NULL;
    }
    
    

    // Liberamos la memoria asignada

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
void escribirResultado(lista_palabras_t caja_lista_palabras, char *nombre_fichero_origen)
{

}

// Funciones auxiliares
/**
 * Esta función obtiene la siguiente línea de un fichero ya abierto y devuelve 
 * un puntero a la cadena con memoria reservada dinámicamente. Utiliza fgetc
 */
char *leerLineaDinamicaFichero(FILE *fd)
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