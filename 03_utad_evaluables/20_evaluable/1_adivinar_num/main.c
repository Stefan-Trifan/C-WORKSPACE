/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 1 - Adivinar número entre 1 y 1000
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definimos el rango de los numeros aleatorios
#define min 0
#define max 1000

// Funciones del programa

// Funciones auxiliares
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    // Reservamos espacio para el primer num aleatorio
    int *nums         = (int *)malloc(sizeof(int));
    int num_aleatorio = 0,
        esAdivinado   = 0,
        num_actual    = 0,
        pos           = 0; // Contador de intentos del usuario

    // Generamos un número aleatorio
    srand(time(NULL));
    num_aleatorio = rand() % (max - min + 1) + min;
    printf("(TESTING: Num aleatorio es: %d)\n\n\n", num_aleatorio);

    // Pedimos numeros al usuario numeros 
    // hasta que averigue el numero aleatorio
    do
    {
        // Pedimos un numero
        printf("Introduce un numero\n-> ");
        *(nums + pos) = pedirEnteroPos();
        num_actual = *(nums + pos);

        if(num_actual == num_aleatorio) // El usuario adivina
        {
            esAdivinado = 1;
            break;
        }
        else // El usuario no adivina
        {
            // Le indicamos si es mayor o menor
            if(num_actual < num_aleatorio)
                printf("El número es mayor.\n");
            else
                printf("El número es menor.\n");

            // Reservamos otro espacio
            nums = (int*)realloc(nums,(pos + 2) * sizeof(int));
            esAdivinado = 0;
        }
        pos++;
    } 
    while (esAdivinado == 0);
    
    // Comunicamos al usuario si ha adivinado
    if(esAdivinado)
    {
        printf("¡Felicidades! Has adivinado el número %d\n", num_aleatorio);
        // Mostramos los numeros introducidos anteriormente por pantalla
        printf("Numeros introducidos: ");
        for(int i = 0; i <= pos; i++)
        {
            printf("%d ", *(nums + i));
        }
    }

    // Liberamos memoria
    free(nums);

    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
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