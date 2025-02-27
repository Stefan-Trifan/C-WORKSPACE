/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 2 
        Sorteo

    *   Testing
        Bien: ./main 1 Jose Steve 
        Bien: ./main Megan Pepe Steve Ana Val Carlos Jack Guada Gyan Mate

        Mal: ./main 1 Jose
        Mal: ./main 1 uvuvuevuevueenyetuenwuevueugwemubwemossas Steve 
        Mal: ./main 1 Jose-Vicente 3- Steve       
        Mal: ./main = Steve Jose
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h> // Para llamar a strtol()

#define MAX_JUGADORES 10
#define TAM_STRING 41
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa
int procesarArgumentos(int *cont_jugadores, int *num_ganadores, int argc, char *argv[]);
int comprobarNombresJugadores(int i, int argc, char *argv[]);
void guardarJugadoresEnArray(int i, char jugador[MAX_JUGADORES][TAM_STRING], int argc ,char *argv[]);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Definimos las variables
    char jugador[MAX_JUGADORES][TAM_STRING] = {0};
    int cont_jugadores = 0,
        num_ganadores  = 0, // Especifica si el usuario ha declarado un numero de jugadores
        error          = 0; 

    // La funcion devuelve un codigo de error si se supera el limite de jugadores
    error = procesarArgumentos(&cont_jugadores, &num_ganadores, argc, argv);
    if(error != 0)
        return 1;

    // La funcion devuelve un error si los nombres de los jugadores no son correctos
    if(num_ganadores)
        error = comprobarNombresJugadores(2, argc, argv); // Comenzamos en argv[2]
    else
        error = comprobarNombresJugadores(1, argc, argv); // Comenzamos en argv[1]
    if(error != 0)
        return 1;
        
    // Guardamos en jugador[][] los jugadores
    if(num_ganadores)
        guardarJugadoresEnArray(2, jugador, argc , argv); // Comenzamos en argv[2]
    else
        guardarJugadoresEnArray(1, jugador, argc , argv); // Comenzamos en argv[1]

    // seleccionarGanador
    if(num_ganadores == 0)
        num_ganadores = 1;
            

    printf("Num Ganadores    : %d\n", num_ganadores);
    printf("DEBUG Jugador 1  : %s\n", jugador[0]);
    printf("DEBUG Jugador 1  : %s\n", jugador[1]);
    printf("DEBUG Jugador 2  : %s\n", jugador[2]);
    printf("DEBUG Jugador 3  : %s\n", jugador[3]);
    printf("DEBUG Jugador 4  : %s\n", jugador[4]);
    printf("DEBUG Jugador 5  : %s\n", jugador[5]);
    printf("DEBUG Jugador 6  : %s\n", jugador[6]);
    printf("DEBUG Jugador 7  : %s\n", jugador[7]);
    printf("DEBUG Jugador 8  : %s\n", jugador[8]);
    printf("DEBUG Jugador 9  : %s\n", jugador[9]);

    // Asignamos un ganador
    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Comprueba si el usuario:
 *     1: Ha introducido el numero correcto de argumentos
 *     2: Ha declarado un numero de ganadores y cuenta los 
 *     jugadores que participan para cada caso
 * 
 * @param[out] cont_jugadores : guarda el numero de ganadores que participan en el sorteo
 * @param[out] num_ganadores : guarda 1 si hay numero de ganadores o 0 si hay solo 1 ganador
 * @return Si hay un error, devuelve 1
 */
int procesarArgumentos(int *cont_jugadores, int *num_ganadores, int argc, char *argv[])
{
    char *endptr;
    // Si el usuario ejecuta el programa sin argumentos devuelve error
    if(argc == 1)
    {
        printf(RED_BOLD
            "ERROR: Tienes que introducir minimo 2 jugadores\n"YELLOW_BOLD
            "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
            "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED_BOLD
            "\n_________________________________________FAIL\n\n"RESET);
        return 1; // error
    }
    // Si el segundo argumento es el numero de ganadores
    else if(argv[1][0] >= '0' && argv[1][0] <= '9' && argv[1][1] == '\0')
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 4 || argc > MAX_JUGADORES + 2)
        {
            printf(RED_BOLD
                "ERROR: Tienes que introducir minimo 2 jugadores y maximo 10\n"YELLOW_BOLD
                "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED_BOLD
                "\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
        *cont_jugadores = argc - 2;
        *num_ganadores = strtol(argv[1], &endptr, 10);
    }
    // Si el 2 argumento no es un numero
    else
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 3 || argc > MAX_JUGADORES + 1)
        {
            printf(RED_BOLD
                "ERROR: Tienes que introducir minimo 2 jugadores y maximo 10\n"YELLOW_BOLD
                "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED_BOLD
                "\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
        *cont_jugadores = argc - 1;
    }
    return 0;
}

/**
 * Comprueba que ningun jugador supere el maximo de caracteres que pueda almacenar un string
 * Comprobamos que los nombres de los jugadores no tengan numeros o nombres compuestos
 * Le pasamos como argumento el indice desde el cual tiene que comprobar los nombres
 * 
 * @param[in] i : 
 *      Especifica el indice de argv dese el cual la funcion comprueba si los nombres 
 *      son correctos dependiendo si hay numero de ganadores o no
 * @return devuelve un codigo error si:
 *      Los nombres de los jugadores contienen numero o son compuestos
 *      El numero de caracteres de un jugador supera el tamaño soportado por el string
 */
int comprobarNombresJugadores(int i, int argc, char *argv[])
{
    int num_letras_argumento = 0; // Cuenta el numero de caracteres por string

    for(; i < argc; i++)
    {
        int j = 0;
        num_letras_argumento = 0;
        while(argv[i][j] != '\0')
        {
            num_letras_argumento++;
            // Jugadores llevan algun caracter que no sea letra
            if(!(
                    (argv[i][j] >= 'a' && argv[i][j] <= 'z') || 
                    (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                ))
            {
                printf(RED_BOLD
                    "ERROR: Los nombres de los jugadores no pueden \n"
                    "empezar por numero o tener nombres compuestos\n"YELLOW_BOLD
                    "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                    "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED_BOLD
                    "\n_________________________________________FAIL\n\n"RESET);
                return 1; // error
            }
            // Nombre jugador supera el tamaño que puede tener un string
            if(num_letras_argumento > TAM_STRING - 1)
            {
                printf(RED_BOLD
                    "ERROR: El numero maximo de caracteres por jugador es %d\n"YELLOW_BOLD
                    "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                    "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED_BOLD
                    "\n_________________________________________FAIL\n\n"RESET, TAM_STRING - 1);
                return 1; // error
            }
            j++;
        }
    }
    return 0;
}

/**
 * Asignamos el nombre de cada jugador a las cadenas de nuestro array por referencia
 * 
 * @param[in] i :
 *      Especifica el indice de argv dese el cual la funcion guarda nombres en el array
 * @param[out] jugador : 
 *      Guarda en las posiciones de jugador[][] los nombres de los jugadores
 */
void guardarJugadoresEnArray(int i, char jugador[MAX_JUGADORES][TAM_STRING], int argc ,char *argv[])
{
    int i_inicio = i;
    for(; i < argc; i++)
        {
            int j = 0;
            while(argv[i][j] != '\0')
            {
                jugador[i - i_inicio][j] = argv[i][j];
                j++;
            }
            if(argv[i][j] == '\0')
            {
                jugador[i - i_inicio][j] = '\0';
            }
        }
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}