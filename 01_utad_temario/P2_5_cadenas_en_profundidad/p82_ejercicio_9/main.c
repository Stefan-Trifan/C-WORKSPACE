/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa

// Funciones auxiliares
char *mi_strcpy_dinamico(const char *origen);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // todo descomentar bloque
    // Comprobamos que el numero de parametros es correcto
    // if(argc != 2)
    // {
    //     printf("\033[31mERROR: Uso: ./main addrress.json\n\033[0m");
    //     printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
    //     return EXIT_FAILURE;
    // }
    // char *nombre_fichero = NULL; // todo descomentar y mover
    // nombre_fichero = mi_strcpy_dinamico(argv[1]); // todo descomentar y mover
      
    // Declaracion de variables
    char nombre_fichero[] = "addrress.json.txt"; // todo reemplazar 
    FILE *fd;

    // Se pide crear un programa que reciba por argc/argv el nombre de un fichero "json"
    fd = fopen(nombre_fichero, "a+");
    if(fd == NULL)
    {
        printf("\033[31mERROR: No ha sido posible abrir el archivo \n\033[0m");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }

    // Se debe leer el fichero, almacenarlo en memoria y mostrar su contenido formateado 

    // Se debe crear un menú que almacene nuevos datos como los mostrados. 
    // El usuario que introduce elementos hasta que pida parar 

    // Se debe escribir los nuevos datos al fichero json antes de cerrar el programa

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
char *mi_strcpy_dinamico(const char *origen)
{
    char *destino = NULL;
    int len;

    len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if(destino)
    {
        strcpy(destino, origen);
    }
    
    return destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}