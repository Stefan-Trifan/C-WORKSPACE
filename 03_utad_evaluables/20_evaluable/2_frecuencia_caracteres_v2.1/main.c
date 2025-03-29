/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 2 - Frecuencia de caracteres

    *   Testing
        ./main a b a c d a b
        ./main uno dos tres a b a c d a b
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
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

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n___________________________START\n\n");

    // Comprobamos que el usuario introduce al menos un caracter
    if (argc == 1)
    {
        printf(RED "Error: Tienes que introducir al menos un caracter\n"
                    "USO  : ./main a b a c d a b\n"
                    "\n_________________________________________EXIT_FAILURE\n\n" RESET);
        return EXIT_FAILURE;
    }

    // Declaracion de variables
    char_info_t *lista_caracteres;
    int cont_letras = 0,
        es_caracter = 0,
        es_repetido = 0;

    // Reservamos memoria para el primer elemento
    lista_caracteres = (char_info_t *)malloc(sizeof(char_info_t));
    if(lista_caracteres == NULL)
    {
        printf(
            "Error al reservar memoria\n"
            "\n_________________________________________EXIT_FAILURE\n\n" RESET);
        return EXIT_FAILURE;
    }

    // Guardamos los caracteres en un array de estructuras
    for(int i = 1; i < argc; i++)
    {
        // Ignoramos los string
        es_caracter = tamCadena(argv[i]); 

        // Comprobamos si el caracter esta repetido
        es_repetido = buscarCaracter(lista_caracteres, cont_letras, *argv[i]); 

        // Guardamos en nuestra lista solo caracteres que no son strings y no estén repetidos
        if(es_caracter && es_repetido == -1) // No es repetido
        {
            lista_caracteres[cont_letras].letra = *argv[i];
            lista_caracteres[cont_letras].contador = 1; 
            cont_letras++;
            lista_caracteres = realloc(lista_caracteres, (cont_letras + 1) * sizeof(char_info_t));
        }
        // Si está repetido, incrementamos las repeticiones de ese caracter
        if(es_caracter && es_repetido != -1) // Es repetido
        {
            lista_caracteres[es_repetido].contador++;
        }
    }

    // Mostramos por pantalla los caracteres repetidos y sus frecuencias
    printf("Caracteres repetidos y sus frecuencias: \n\n");
    for(int i = 0; i < cont_letras; i++)
    {
        if(lista_caracteres[i].contador > 1)
            printf(
                "'%c' aparece %d veces\n", 
                lista_caracteres[i].letra, lista_caracteres[i].contador);
        if(lista_caracteres[i].contador == 1)
            printf(
                "'%c' aparece %d vez\n", 
                lista_caracteres[i].letra, lista_caracteres[i].contador);
    }

    // Liberamos memoria reservada
    free(lista_caracteres);

    printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 *  Función para buscar un carácter en la lista de tamanio tam
 *  - Si el caracter no se repite retorna -1
 *  - Si el caracter se reptite, retorna el indice donde se repite
 */
int buscarCaracter(char_info_t *lista, int tam, char c) 
{ 
    int i_caracter_repetido = -1;
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].letra == c)
        {
            i_caracter_repetido = i;
            break;
        }
    }
    return i_caracter_repetido;
} 

/**
 * Función que se le pasa como parámetro una cadena y 
 * comprueba si la cadena tiene más de un carácter
 * - Devuelve 1 si hay solo un caracter
 * - Devuelve 0 si hay un string
 */
int tamCadena(char *cadena) 
{ 
    int hay_un_caracter = 0;
    if(cadena[1] != '\0')
        hay_un_caracter = 0;
    else
        hay_un_caracter = 1;

    return hay_un_caracter;
}

// Funciones auxiliares