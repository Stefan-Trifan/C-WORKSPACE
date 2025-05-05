/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 5

// Funciones del programa

// Funciones auxiliares
char *leerCadenaDinamicaFichero(FILE *fd);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    char *texto;
    FILE *fd;

    // Abrimos el fichero en modo lectura
    fd = fopen("datos.txt", "r");

    // Llamamos a la funcion
    texto = leerCadenaDinamicaFichero(fd);

    // Imprimimos el texto
    printf("Texto en fichero: \n%s", texto);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *leerCadenaDinamicaFichero(FILE *fd)
{
    // Declaracion de variables
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    while ((c = fgetc(fd)) != EOF)
    {
        if(i == memoria_actual - 1) 
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