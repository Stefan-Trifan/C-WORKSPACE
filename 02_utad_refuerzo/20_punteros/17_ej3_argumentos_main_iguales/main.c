/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Escribe un programa en lenguaje C al que se le pase por argumentos del main 
        dos cadenas (tamaño maximo 20 caracteres) y que compruebe que son iguales.
        El programa mostrara imprimira por pantalla si son iguales o no despues de comprobarlo
*/

/* _________________________________________
   Inicio cabecera */
#include <stdio.h>
#define RED "\033[1;31m"
#define RESET "\033[0m"
#define TAM 21
// Funciones del programa
int cadenasIguales(char* cadena1, char* cadena2);
int tamCadena(char* cadena);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]) 
{
    printf("\n_________________________________________START\n\n");

    int son_iguales = 1, i = 0, j = 0;
    char cadena1[TAM] = {0}, cadena2[TAM] = {0};

    if(argc != 3)
    {
        printf(RED"Tienes que introducir 2 argumentos\n"RESET);
        printf("\n_________________________________________EXIT_FAILURE\n\n");
        return 0;
    }

    while(i < TAM - 1 && argv[1][i] != '\0')
    {
        cadena1[i] =  argv[1][i];
        i++;
    }
    cadena1[i] = '\0';


    while(j < TAM - 1 && argv[2][j] != '\0')
    {
        cadena2[j] =  argv[2][j];
        j++;
    }
    cadena2[j] = '\0';

    printf("Cadena1: %s\n", cadena1);
    printf("Cadena2: %s\n", cadena2);
    printf("i: %d\n", i);
    printf("j: %d\n", j);

    if(i == j)
    {
        for(int k = 0; k < i; k++)
        {
            if(cadena1[k] != cadena2[k])
            {
                son_iguales = 0;
                break;
            }
        }
    }
    else
    {
        son_iguales = 0;
    }

    if(son_iguales)
    {
        printf("Las cadenas son iguales");
    }
    else
    {
        printf("Las cadenas no son iguales");
    }

    printf("\n_________________________________________EXIT\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Funcion que se le pasa como parametros dos cadenas y 
 * devuelve verdadero si son iguales y falso si no lo son
 */
int cadenasIguales(char* cadena1, char* cadena2)
{
    return 0;
}

/**
 * Funcion que se le pasa como parametro una cadena y 
 * devuelve el numero de caracteres que tiene
 */
int tamCadena(char* cadena)
{
    return 0;
}

// Funciones auxiliares
void clearBuffer() {
    while (getchar() != '\n');
}
