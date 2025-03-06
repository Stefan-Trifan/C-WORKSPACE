/* 
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Testing
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TAM_STR 5
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char *text);
void clearBuffer();

/*  ________________________________________
    Inicio Main */

int main(int argc, char *argv[])
{
    printf("________________________________________START\n\n");

    int min = 0;
    int max = 3;

    srand(time(NULL));
    int num = min + rand() % (max + 1);
    printf("num %d\n",num);

    

    printf("________________________________________END\n\n");
    return 0;
}

/*  ________________________________________
    Inicio Definicion de Funciones */

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char *text)
{
    int i, esValido;
    char c;
    do
    {
        esValido = 1, i = 0;
        while(i < TAM_STR - 1)
        {
            c = getchar();

            if(c == '\n') break;

            text[i] = c;
            i++;
        }
        text[i] = '\0';

        if(i == TAM_STR - 1)
        {
            c = getchar();

            if(c != '\n')
            {
                printf(YELLOW
                    "ALERTA. Has superado el limite de %d caracteres\n"
                    "Por favor, intentelo de nuevo\n"
                    "-> "RESET, 
                    TAM_STR);
                clearBuffer();
                esValido = 0;
            }
        }
    } 
    while (esValido != 1);
}

void clearBuffer()
{
    while(getchar() != '\n');
}