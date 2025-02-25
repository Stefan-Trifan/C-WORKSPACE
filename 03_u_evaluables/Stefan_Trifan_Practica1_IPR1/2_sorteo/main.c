/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 2 
        Sorteo

    *   Testing
        Con numero:
        ./main 3 Megan Pepe Steve Ana Val Carlos Jack Guada Gyan Mate (10 jugadores, argc = 12)
        ./main 3 Megan Pepe Steve Ana Val Carlos Jack Guada Gyan Mate Juan (11 jugadores)

        Sin numero:
        ./main Megan Pepe Steve Ana Val Carlos Jack Guada Gyan Mate (10 jugadores, argc = 11)
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define MAX_JUGADORES 10
#define TAM_STRING 5
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa
int comprobarArgumentos(int argc, char *argv[], int *cont_jugadores);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Definimos las variables
    char jugador[MAX_JUGADORES][TAM_STRING] = {0};
    int cont_jugadores           = 0,
        num_letras_por_argumento = 0,
        error                    = 0;

    error = comprobarArgumentos(argc, argv, &cont_jugadores);
    if(error)
        return error;

    

    // Comprobamos que ningun jugador supera el maximo de caracteres permitidos
    // for(int i = 0; i < MAX_JUGADORES; i++)
    // {
    //     for(int j = 0; j < TAM_STRING + 1; j++)
    //     {
    //         if(argv[i][j] != '\n')
    //         {

    //         }
    //     }
    // }

    // Asignamos el nombre de cada jugador a las cadenas de nuestro array
    // for(int i = 0; i < cont_jugadores; i++)
    // {
    //     for(int j = 0; j < TAM_STRING; j++)
    //     {
    //         jugador[i][j] = argv[i][j];

    //     }
    // }

    // Comprobar nombres jugadores
    // Comprobamos que el formato de los jugadores es correcto
    // todo el nombre de los jugadores no puede empezar por numero
    // todo el nombre de los jugadores no puede ser compuesto

    // Asignamos un ganador
    // todo si hay 3 ganadores, mostramos 3 ganadores



    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Encontramos el numero de jugadores
 * 
 */
int comprobarArgumentos(int argc, char *argv[], int *cont_jugadores)
{
    // Si el usuario solo introduce ./main
    if(argc == 1)
    {
        printf(RED_BOLD"ERROR: Tienes que introducir minimo 2 jugadores\n");
        printf("\n_________________________________________FAIL\n\n"RESET);
        return 1;
    }
    // Si el 2 argumento es un numero
    else if(argv[1][0] >= '0' && argv[1][0] <= '9' && argv[1][1] == '\0')
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 4 || argc < MAX_JUGADORES + 2)
        {
            printf(RED_BOLD"ERROR: Tienes que introducir minimo 2 jugadores y maximo 10\n");
            printf("\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
        *cont_jugadores = argc - 2;
    }
    // Si el 2 argumento no es un numero
    else
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 3 || argc > MAX_JUGADORES + 1)
        {
            printf(RED_BOLD"ERROR: Tienes que introducir minimo 2 jugadores y maximo 10\n");
            printf("\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
        *cont_jugadores = argc - 1;
    }
    return 0;
}


// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}