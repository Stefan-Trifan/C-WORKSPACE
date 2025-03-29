/*
        *	Autor
                Stefan Trifan

        * 	Compilar
                mac     : comp (compilar)
                                  run  (ejecutar)
                                  brun (compilar y ejecutar)
                windows : gcc main.c -o main.exe
                                : ./main.exe

        *   Estado:

        * 	Enunciado
                LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
void clearBuffer();

float strtof(const char *str, char **endptr);
/* _________________________________________
       Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n___________________________START\n\n");

    float num1 = 0, num2 = 0, num3 = 0, numMin = 0, numMax = 0, sumaTotal = 0;
    char *endptr;

    if (argc != 4)
    {
        printf("Uso %s num1 num2 num3\n", argv[0]);
        return 1;
    }

    num1 = strtof(argv[1], &endptr);
    num2 = strtof(argv[2], &endptr);
    num3 = strtof(argv[3], &endptr);

    if (num1 >= num2 && num1 >= num3)
    {
        numMax = num1;
        if (num2 >= num3)
        {
            numMin = num3;
        }
        if (num3 >= num2)
        {
            numMin = num2;
        }
    }
    if (num2 >= num1 && num2 >= num3)
    {
        numMax = num2;
        if (num1 >= num3)
        {
            numMin = num3;
        }
        if (num3 >= num1)
        {
            numMin = num1;
        }
    }
    if (num3 >= num1 && num3 >= num2)
    {
        numMax = num3;
        if (num2 >= num1)
        {
            numMin = num1;
        }
        if (num1 >= num2)
        {
            numMin = num2;
        }
    }

    sumaTotal = num1 + num2 + num3;

    printf("La media de los 3 num es: %f\n", sumaTotal / 3);
    printf("El numero minimo es:      %f\n", numMin);
    printf("El numero maximo es:      %f\n", numMax);

    printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
    return 0;
}

/* _________________________________________
       Inicio definicion de funciones */

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}