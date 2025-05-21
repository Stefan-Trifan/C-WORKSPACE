/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num_frases;
    char **mi_frase;
}
container_t;

// Funciones del programa

// Funciones auxiliares
char *mi_strcpy_dinamico(const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    container_t c_frases;
    c_frases.num_frases = 4;
    c_frases.mi_frase = (char **)malloc(sizeof(char *) * c_frases.num_frases);

    // Inicializamos las frases
    c_frases.mi_frase[0] = mi_strcpy_dinamico("La educación ayuda a la persona");
    c_frases.mi_frase[1] = mi_strcpy_dinamico("Dime y lo olvido");
    c_frases.mi_frase[2] = mi_strcpy_dinamico("En cuestiones de cultura y de saber");
    c_frases.mi_frase[3] = mi_strcpy_dinamico("Para viajar lejos no hay mejor nave");

    // Imprimimos las frases
    for(int i = 0; i < c_frases.num_frases; i++)
    {
        printf("c_frases.mi_frase[%d] = %s\n", i, c_frases.mi_frase[i]);
    }

    // Reordenamos las frases
    for(int i = 0; i < c_frases.num_frases - 1; i++)
    {
        for(int j = 0; j < c_frases.num_frases - i - 1; j++)
        {
            if(strcmp(c_frases.mi_frase[j], c_frases.mi_frase[j + 1]) > 0)
            {
                char *temp = c_frases.mi_frase[j];
                c_frases.mi_frase[j] = c_frases.mi_frase[j + 1];
                c_frases.mi_frase[j + 1] = temp;
            }
        }
    }

    // Imprimimos las frases alfabetizadas
    printf("\n\n");
    for(int i = 0; i < c_frases.num_frases; i++)
    {
        printf("c_frases.mi_frase[%d] = %s\n", i, c_frases.mi_frase[i]);
    }

    // Liberamos memoria
    for(int i = 0; i < c_frases.num_frases; i++)
    {
        free(c_frases.mi_frase[i]);
    }

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *mi_strcpy_dinamico(const char *origen)
{
    char *destino = NULL;
    int len;

    len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if(destino)
    {
        strcpy(destino, origen);
    }
    
    return destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}