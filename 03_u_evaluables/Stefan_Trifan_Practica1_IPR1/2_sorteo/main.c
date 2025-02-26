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
int procesarArgumentos(int *cont_jugadores, int *hay_num_ganadores, int argc, char *argv[]);
int procesarJugadores(int i, int cont_jugadores, char *argv[]);
// void guardarJugadores();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Definimos las variables
    char jugador[MAX_JUGADORES][TAM_STRING] = {0};
    int cont_jugadores    = 0,
        hay_num_ganadores = 0, // Especifica el usuario ha declarado un numero de jugadores
        error             = 0; // Guarda distintos codigos de errores

    // La funcion devuelve un codigo de error si se supera el limite de jugadores
    error = procesarArgumentos(&cont_jugadores, &hay_num_ganadores, argc, argv);
    if(error != 0)
        return 1;

    printf("DEBUG           argc: %d\n", argc);

    // La funcion devuelve un error si los nombres de los jugadores no son correctos
    if(hay_num_ganadores)
    {
        error = procesarJugadores(2, cont_jugadores, argv); 
    }
    else
    {
        error = procesarJugadores(1, cont_jugadores, argv);
    }
    if(error != 0)
    {
        return 1;
    }
        
    // Asignamos el nombre de cada jugador a las cadenas de nuestro array
    // Comprobar nombres jugadores
    // Asignamos un ganador
    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Comprueba si el usuario ha declarado un numero de ganadores 
 * y cuenta los jugadores que participan para cada caso
 * 
 * 
 * @param[out] cont_jugadores : guarda el numero de ganadores que participan en el sorteo
 * @param[out] hay_num_ganadores : 1 si hay numero de ganadores o 0 si hay solo 1 ganador
 * @return Si hay un error, devuelve el codigo del error
 */
int procesarArgumentos(int *cont_jugadores, int *hay_num_ganadores, int argc, char *argv[])
{
    // Si el usuario ejecuta el programa sin argumentos devuelve error
    if(argc == 1)
    {
        printf(RED_BOLD
            "ERROR: Tienes que introducir minimo 2 jugadores\n"
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
                "ERROR: Tienes que introducir minimo 2 jugadores y maximo 10\n"
                "\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
        *cont_jugadores = argc - 2;
        *hay_num_ganadores = 1;
    }
    // Si el 2 argumento no es un numero
    else
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 3 || argc > MAX_JUGADORES + 1)
        {
            printf(RED_BOLD
                "ERROR: Tienes que introducir minimo 2 jugadores y maximo 10\n"
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
 *      Especifica el indice dese el cual la funcion comprueba si los nombres 
 *      son correctos dependiendo si hay numero de ganadores o no
 * @param[in] cont_jugadores
 * @return devuelve un codigo error si:
 *      Los nombres de los jugadores contienen numero o son compuestos
 *      El numero de caracteres de un jugador supera el tamaño soportado por el string
 */
int procesarJugadores(int i, int cont_jugadores, char *argv[])
{
    int num_letras_argumento = 0; // Cuenta el numero de caracteres por string

    printf("DEBUG cont_jugadores: %d\n", cont_jugadores);

    for(; i < cont_jugadores + 2; i++)
    {
        int j = 0;
        num_letras_argumento = 0;
        while(argv[i][j] != '\0')
        {
            num_letras_argumento++;
            // Jugadores llevan numeros o tienen nombres compuestos
            if((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-' )
            {
                printf(RED_BOLD
                    "ERROR: Los nombres de los jugadores no pueden \n"
                    "empezar por numero o tener nombres compuestos\n"
                    "\n_________________________________________FAIL\n\n"RESET);
                return 1; // error
            }
            // Nombre jugador supera el tamaño que puede tener un string
            if(num_letras_argumento > TAM_STRING - 1)
            {
                printf(RED_BOLD
                    "ERROR: El numero maximo de caracteres por jugador es %d\n"
                    "\n_________________________________________FAIL\n\n"RESET, TAM_STRING - 1);
                return 1; // error
            }
            j++;
        }
    }
    return 0;
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}