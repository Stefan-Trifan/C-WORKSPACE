/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

typedef struct direccion
{
    char *nombre_calle;
    char *piso;
    char puerta;
}
direccion_t;

typedef struct ciudadano
{
    char *nombre;
    int edad;
    direccion_t direccion;
}
ciudadano_t;

// Funciones del programa

// Funciones auxiliares
char *leerFicheroDinamicoTodo(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // TODO Falta recibir parametros argc

    // Declaracion de variables
    char *p_nombre_fichero = "addrress.json.txt";
    FILE *fd = fopen(p_nombre_fichero, "r");
    ciudadano_t ciudadano[2];
    char *texto_fichero;

    // Guardamos el texto del fichero
    texto_fichero = leerFicheroDinamicoTodo(fd);

    // Imprimimos el texto del fichero
    printf("%s", texto_fichero);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *leerFicheroDinamicoTodo(FILE *fd)
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