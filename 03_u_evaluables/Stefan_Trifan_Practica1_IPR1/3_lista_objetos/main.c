/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 3 
        Lista de objetos

    *   Testing
        
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

typedef struct objeto_t
{
    int id;
    float peso;
    char categoria;
}objeto_t;

// Funciones del programa
int procesarObjetos(int argc);
int guardarObjetos();
void imprimirObjetos(char letra);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    objeto_t objeto[10];
    int error = 0;

    // Comprobamos el formato de los argumentos
    procesarObjetos(argc);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Comprobamos
 * - El formato de los argumentos es correcto
 * - El usuario no supera el limite de objetos
 */
int procesarObjetos(int argc)
{
    if(argc < 2 || argc > 11)
    {
        
    }
    return 0;
}
/**
 * Guardamos los objetos en nuestro array de estructuras
 * 
 */
int guardarObjetos()
{
    return 0;
}

/**
 * Imprimimos los objetos en orden
 * 
 */
void imprimirObjetos(char letra)
{

}


// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}