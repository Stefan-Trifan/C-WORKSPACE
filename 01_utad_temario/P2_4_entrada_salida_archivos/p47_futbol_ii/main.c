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

typedef enum
{
    AGREGAR = 1, MOSTRAR, GUARDAR, SALIR
}
opcion_t;

typedef struct
{
    char *nombre_completo;
    int num_camiseta;
    int num_goles;
} 
datos_jugador_t;

// Funciones del programa
void agregarJugador(datos_jugador_t **jugador, int *num_jugadores);
void mostrarGoleadores(datos_jugador_t *jugador, int num_jugadores);
void guardarJugadores(datos_jugador_t *jugador, int num_jugadores);
void liberarMemoria(datos_jugador_t *jugador, int num_jugadores);
void menu();

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
    datos_jugador_t *jugador;
    FILE *fd;
    int opcion = 0;
    int num_jugadores = 0;

    // Abrimps el fichero
    fd = fopen("datosjugadores.txt", "a");
    if (fd == NULL)
    {
        printf("Error al abrir el archivo\n");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Introducimos jugadores
    do
    {
        menu();
        opcion = pedirEnteroPos();

        switch (opcion)
        {
            case AGREGAR: 
                agregarJugador(&jugador, &num_jugadores);
                break;
            case MOSTRAR: 
                mostrarGoleadores(jugador, num_jugadores);
                break;
            case GUARDAR: 
                guardarJugadores(jugador, num_jugadores);
                break;
            case SALIR: 
                liberarMemoria(jugador, num_jugadores);
                printf("Saliendo del programa...\n");
                break;
        }
    } 
    while (opcion != 4);

    fclose(fd);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * 
 * Al introducir un jugador, se deberá pedir los datos (nombre/apellidos y goles) al usuario, 
 * y se deberá almacenar enuna lista reservada de forma dinámica.
 */
void agregarJugador(datos_jugador_t **jugador, int *num_jugadores)
{
    // Incrementamos el numero de jugadores
    (*num_jugadores)++;

    // Reservamos espacio para el nuevo jugador
    if(*num_jugadores == 1)
    {
        *jugador = malloc(sizeof(datos_jugador_t));
    }
    else if(*num_jugadores >= 2)
    {
        *jugador = realloc(*jugador, *num_jugadores * sizeof(datos_jugador_t));
    }

    
}

/**
 * Al elegir esta opción, se pedirá un número de goles mínimo al usuario, y se deberán 
 * mostrar todos los jugadores almacenados anteriormente con un número de goles superior al introducido.
 */
void mostrarGoleadores(datos_jugador_t *jugador, int num_jugadores)
{

}

/**
 * Al elegir esta opción se guardarán en un fichero (datosjugadores.txt) 
 * los datos de los jugadores que se hayan introducido y no se hayan guardado previamente
 */
void guardarJugadores(datos_jugador_t *jugador, int num_jugadores)
{

}

void liberarMemoria(datos_jugador_t *jugador, int num_jugadores)
{

}

void menu()
{
    printf(
        "============== Selecciona una opcion ==============\n"
        "[1] Introducir Jugador\n"
        "[2] Mostrar Goleadores\n"
        "[3] Guardar\n"
        "[4] Salir\n"
        "-> ");
}

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
            printf("\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                   "-> \033[0m");
            esValido = 0;
        }
    } while (esValido != 1);
    return num;
}

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}