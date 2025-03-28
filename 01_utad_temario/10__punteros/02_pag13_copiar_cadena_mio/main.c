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
#define TAM 15

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]){
    printf("\n_________________________________________START\n\n");

    char nombre_origen[15]  = {0};
    char nombre_destino[15] = {0};
    int esValido;

    printf("Introduce -> ");
    do
    {
        int i = 0;
        esValido = 1;
        char c;
        while(i < TAM - 1)
        {
            c = getchar();

            if(c == '\n') break;

            nombre_origen[i] = c;
            i++;
        }
        nombre_origen[i] = '\0';

        if(i == TAM - 1)
        {
            c = getchar();
            if(c != '\n')
            {
                printf("ERROR -> ");
                clearBuffer();
                esValido = 0;
            }
        }
    } while(esValido != 1);
        

    char *p_origen = nombre_origen;
    char *p_destino = nombre_destino;

    {
        int i = 0;
        while (*(p_origen + i) != '\0')
        {
            *(p_destino + i) = *(p_origen + i);
            i++;
        }
    }

    printf("nombre_origen:  %s\n", nombre_origen);
    printf("nombre_destino: %s\n", nombre_destino);

    printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
    while (getchar() != '\n');
}