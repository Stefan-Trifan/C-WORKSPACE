/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 2 
        Sorteo

    *   Testing
        Bien: 
            ./main 1 Jose Steve 
            ./main 6 Megan Pepe Steve Ana Val Carlos Marcos Guada Gyan Mate

        Mal: 
            ./main 1 Jose
            ./main 1 MaximilianoAlejandroFernandezRodriguezGonzalez Steve 
            ./main 1 Jose-Vicente 3- Steve       
            ./main = Steve Jose
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h> // Para strtol(), srand() y rand()
#include <time.h>   // Para time()

#define TAM_ARR 10
#define TAM_STR 41
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa
int procesarArgumentos
(
    int *cont_jugadores, 
    int *num_ganadores, 
    int argc, 
    char *argv[]
);
int comprobarNombres
(
    int i, 
    int argc, 
    char *argv[]
);
void guardarNombres
(
    int i, 
    char jugadores[TAM_ARR][TAM_STR], 
    int argc,
    char *argv[]
);
void seleccionarGanador
(
    int num_ganadores, 
    int cont_jugadores, 
    char jugadores[TAM_ARR][TAM_STR]
);
void verUso();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Definimos las variables
    char jugadores[TAM_ARR][TAM_STR] = {0};
    int cont_jugadores = 0,
        num_ganadores  = 0,   // Especifica si el usuario ha declarado un numero de jugadores
        err            = 0;
    
    // La funcion devuelve un codigo de error si se supera el limite de jugadores
    err = procesarArgumentos(&cont_jugadores, &num_ganadores, argc, argv);
    if(err) return 1;

    // La funcion devuelve un error si los nombres de los jugadores no son correctos
    if(num_ganadores)
        err = comprobarNombres(2, argc, argv); // Comenzamos en argv[2]
    else
        err = comprobarNombres(1, argc, argv); // Comenzamos en argv[1]
    if(err) return 1;
        
    // Guardamos en el arreglo jugadores los jugadores
    if(num_ganadores)
        guardarNombres(2, jugadores, argc , argv); // Comenzamos en argv[2]
    else
        guardarNombres(1, jugadores, argc , argv); // Comenzamos en argv[1]

    // Seleccionamos los ganadores del sorteo de manera aleatoria
    seleccionarGanador(num_ganadores, cont_jugadores, jugadores);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * @brief Comprueba si el usuario:
 *     1: Ha introducido el numero correcto de argumentos
 *     2: Ha declarado un numero de ganadores y cuenta 
 *        los jugadores que participan para cada caso
 * 
 * @param[out] cont_jugadores : guarda el numero de ganadores que participan en el sorteo
 * @param[out] num_ganadores : guarda el numero de ganadores
 * @return Si hay un error, devuelve 1
 */
int procesarArgumentos(int *cont_jugadores, int *num_ganadores, int argc, char *argv[])
{
    char *endptr;
    // Si el usuario ejecuta el programa sin argumentos devuelve error
    if(argc == 1)
    {
        printf(RED"ERROR: Tienes que introducir minimo 2 jugadores.\n"RESET);
        verUso();
        return 1; // error
    }
    // Si el segundo argumento es el numero de ganadores
    else if(argv[1][0] >= '0' && argv[1][0] <= '9' && argv[1][1] == '\0')
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 4 || argc > TAM_ARR + 2)
        {
            printf(RED"ERROR: Tienes que introducir entre 2 y %d jugadores.\n"RESET, TAM_ARR);
            verUso();
            return 1; // error
        }
        *cont_jugadores = argc - 2;
        *num_ganadores = strtol(argv[1], &endptr, 10);
        // Comprobamos que no hay mas ganadores que jugadores
        if(*num_ganadores >= *cont_jugadores) 
        {
            printf(RED"ERROR: El numero de ganadores debe ser inferior al numero de participantes\n"RESET);
            verUso();
            return 1; // error
        }
    }
    // Si el 2 argumento no es un numero
    else
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 3 || argc > TAM_ARR + 1)
        {
            printf(RED"ERROR: Tienes que introducir entre 2 y %d jugadores.\n"RESET, TAM_ARR);
            verUso();
            return 1; // error
        }
        *cont_jugadores = argc - 1;
    }
    return 0;
}

/**
 * @brief 
 *      Comprueba que ningun jugador supere el limite de caracteres que pueda almacenar un string
 *      Comprobamos que los nombres de los jugadores no tengan numeros o nombres compuestos
 *      Le pasamos como argumento el indice desde el cual tiene que comprobar los nombres
 * 
 * @param[in] i
 *      Especifica el indice de argv dese el cual la funcion comprueba si 
 *      los nombres son correctos dependiendo si hay numero de ganadores o no
 * @return error si:
 *      Los nombres de los jugadores contienen numero o son compuestos
 *      El numero de caracteres de un jugador supera el tamaño soportado por el string
 */
int comprobarNombres(int i, int argc, char *argv[])
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
            if(!( (argv[i][j] >= 'a' && argv[i][j] <= 'z') || 
                  (argv[i][j] >= 'A' && argv[i][j] <= 'Z') ))
            {
                printf(RED
                    "ERROR: Los nombres de los jugadores no pueden \n"
                    "empezar por numero o tener nombres compuestos\n"RESET);
                verUso();
                return 1; // error
            }
            // Nombre jugador supera el tamaño que puede tener un string
            if(num_letras_argumento > TAM_STR - 1)
            {
                printf(RED"ERROR: El nombre excede el limite de %d caracteres.\n"RESET, TAM_STR - 1);
                verUso();
                return 1; // error
            }
            j++;
        }
    }
    return 0;
}

/**
 * @brief Asignamos el nombre de cada jugador a las cadenas de nuestro array por referencia
 * 
 * @param[in] i:
 *      Especifica el indice de argv dese el cual la funcion guarda nombres en el array
 * @param[out] jugadores: 
 *      Arreglo de string que guarda los nombres de los jugadores
 */
void guardarNombres(int i, char jugadores[TAM_ARR][TAM_STR], int argc, char *argv[])
{
    int i_inicio = i;
    for(; i < argc; i++)
        {
            int j = 0;
            while(argv[i][j] != '\0')
            {
                jugadores[i - i_inicio][j] = argv[i][j];
                j++;
            }
            if(argv[i][j] == '\0')
                jugadores[i - i_inicio][j] = '\0';
        }
}

/**
 * @brief Funcion que selecciona los ganadores
 */
void seleccionarGanador(
    int num_ganadores, 
    int cont_jugadores, 
    char jugadores[TAM_ARR][TAM_STR])
{
    char ganadores[TAM_ARR - 1][TAM_STR] = {0}; // Arreglo que almacena los nombres de los ganadores. Maximo 9
    int numerosAleatorios[TAM_ARR - 1] = {0}, // Arreglo que almacena los indices de los ganadores
        repetido = 0;
    
    // Si el usuario no especifica que hay ganadores por defecto debe haber 1 ganador
    if(num_ganadores == 0)
        num_ganadores = 1;

    srand(time(NULL)); 
    // Generamos de manera aleatoria un indice para cada ganador
    // Los indices no se pueden repetir (un jugador no puede ganar 2 veces el mismo sorteo)
    for(int i = 0; i < num_ganadores; i++)
    {
        do
        {
            repetido = 0;
            numerosAleatorios[i] = rand() % cont_jugadores;
            // Comprobamos si el mismo indice ya ha salido
            for(int j = 0; j < i; j++)
            {
                if(numerosAleatorios[j] == numerosAleatorios[i])
                    repetido = 1;
            }
        } 
        while(repetido);
    }

    // Asignamos los los indices de los ganadores a nuestro array de ganadores
    if(num_ganadores == 1)
        printf(GREEN"GANADOR: \n\n"RESET);
    else
        printf(GREEN"GANADORES: \n\n"RESET);
    for(int i = 0; i < num_ganadores; i++)
    {
        for(int j = 0; j <= TAM_STR; j++)
        {
            ganadores[i][j] = jugadores[numerosAleatorios[i]][j];
        }
        printf(GREEN"%d: %s\n"RESET, i + 1, ganadores[i]); // Imprimimos los ganadores
    }
}

void verUso()
{
    printf(
        YELLOW
        "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
        "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"
        RED
        "\n_________________________________________FAIL\n\n"
        RESET);
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}

/*
    DEBUG LOG
    printf("\n_________________________________________DEBUG\n\n");
    printf("DEBUG random i = %d: %d\n", i, random);
    printf("\n\n");
    printf("DEBUG numerosAleatorios[0]: %d\n", numerosAleatorios[0]);
    printf("DEBUG numerosAleatorios[1]: %d\n", numerosAleatorios[1]);
    printf("DEBUG numerosAleatorios[2]: %d\n", numerosAleatorios[2]);
    printf("DEBUG numerosAleatorios[3]: %d\n", numerosAleatorios[3]);
    printf("DEBUG numerosAleatorios[4]: %d\n", numerosAleatorios[4]);
    printf("DEBUG numerosAleatorios[5]: %d\n", numerosAleatorios[5]);
    printf("\n\n")
    printf("DEBUG Argc          : %d\n", argc);
    printf("DEBUG Num Ganadores : %d\n", num_ganadores);
    printf("DEBUG Num Jugadores : %d\n", cont_jugadores);
    printf("DEBUG Jugador 0 : %s\n", jugadores[0]);
    printf("DEBUG Jugador 1 : %s\n", jugadores[1]);
    printf("DEBUG Jugador 2 : %s\n", jugadores[2]);
    printf("DEBUG Jugador 3 : %s\n", jugadores[3]);
    printf("DEBUG Jugador 4 : %s\n", jugadores[4]);
    printf("DEBUG Jugador 5 : %s\n", jugadores[5]);
    printf("DEBUG Jugador 6 : %s\n", jugadores[6]);
    printf("DEBUG Jugador 7 : %s\n", jugadores[7]);
    printf("DEBUG Jugador 8 : %s\n", jugadores[8]);
    printf("DEBUG Jugador 9 : %s\n", jugadores[9]);
    printf("\n_________________________________________DEBUG\n\n");
*/