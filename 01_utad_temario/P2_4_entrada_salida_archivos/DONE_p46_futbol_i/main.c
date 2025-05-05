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

typedef struct
{
    char *nombre_completo;
    int   num_camiseta;
    int   num_goles;
}
datos_jugador_t;

// Funciones del programa

// Funciones auxiliares
char *pedirCadenaDinamica();
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    datos_jugador_t jugador;
    FILE *fd;
    int opcion = 0;
    jugador.num_camiseta = 1;

    // Abrimps el fichero
    fd = fopen("datosjugadores.txt", "a");
	if(fd == NULL)
	{
		printf("Error al abrir el archivo\n");
		printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
	}

    // Introducimos jugadores
    do
    {
        // Pedimos los datos
        printf("Introduce el nombre del jugador\n-> ");
        jugador.nombre_completo = pedirCadenaDinamica();

        printf("Introduce el numero de goles\n-> ");
        jugador.num_goles = pedirEnteroPos();
        
        // Escribimos los datos en el fichero
        fprintf(fd, "%s,%d,%d\n", jugador.nombre_completo,jugador.num_camiseta,jugador.num_goles);
        
        free(jugador.nombre_completo);

        printf("Quieres introducir otro usuario?\n[1] Si\n[0] No\n-> ");
        opcion = pedirEnteroPos();
        if(opcion != 0)
        {
            jugador.num_camiseta++;
        }   
    } 
    while (opcion != 0);

    fclose(fd);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *pedirCadenaDinamica()
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
    {
        if (i == memoria_actual)
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

int pedirEnteroPos()
{
    int num = 0, esValido = 0;
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if (esValido == 0 || num < 0)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
    }
    while (esValido != 1);
    return num;
}

void clearBuffer()
{
    while (getchar() != '\n');
}