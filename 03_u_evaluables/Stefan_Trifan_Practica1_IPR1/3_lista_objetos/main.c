/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 3 
        Lista de objetos

    *   Testing
        ./main 101:2.5:A 102:3.1:B 103:1.8:C 104:4.0:A 105:2.2:B 106:3.9:C
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM_ARR 10
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

typedef struct objeto_t
{
    int id;
    float peso;
    char categoria;
}
objeto_t;

// Funciones del programa
int procesarArgumentos(int argc);
int comprobarObjetos(int argc, char *argv[]);
int guardarObjetos();
void imprimirObjetos(char letra);
void verUso();
// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    objeto_t objeto[TAM_ARR] = {0};
    int err            = 0,
        num_objetos      = 0;

    // Comprobamos que el usuario respeta el limite de objetos
    if(argc < 2 || argc > 11)
    {
        printf(RED"ERROR: Tienes que introducir entre 1 y 10 objetos.\n"RESET);
        verUso();
        return 1; // error
    }
    num_objetos = argc - 1;

    // Devuelve un error si el ID, peso o categoria no son correctos
    err = comprobarObjetos(argc, argv);
    if(err) return 1;

    // Si son correctos los guardamos en nuestro array de estructuras
    // Utilizamos un arreglo de string intermedio
    err = guardarObjetos();
    if(err) return 1;

     // Imprimimos los objetos en orden

    /* DEBUG LOG */
    printf("DEBUG num_objetos: %d\n", num_objetos);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Comprobamos que el formato de los objetos es correcto 
 * 
 * @return 1 (error) si:
 *      - El ID contiene contiene caracteres no numericos
 *      - El PESO contiene caracteres no numericos que no sean '.'
 *      - El punto decimal del PESO está mal colocado
 *      - Hay mas de un punto decimal en PESO
 *      - La CATEG es distinta de 'A', 'B' o 'C'
 *      - La CATEG tiene mas de un solo caracter
 */
int comprobarObjetos(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        int j                = 0,
            cont_separadores = 0,
            cont_punto_float = 0;
        
        // ID (INT)
        while(argv[i][j] != ':')
        {
            // Comprobamos si el ID  son solo numeros
            if(!(argv[i][j] >= '0' && argv[i][j] <= '9'))
            {
                printf(RED"ERROR: El ID solo puede contener numeros\n"RESET);
                verUso();
                return 1; // Error
            } 
            j++;
        }
        if(argv[i][j] == ':')
        {
            cont_separadores++;
            j++;
        }
        // PESO (FLOAT)
        if(argv[i][j] == '.')
        {
            printf(RED"ERROR: El punto del float esta mal colocado. Falta parte entera\n"RESET);
            verUso();
            return 1; // Error
        }
        while(argv[i][j] != ':')
        {
            // Comprobamos el float es compuesto solo por digitos o punto
            if(!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '.'))
            {
                printf(RED"ERROR: El PESO solo puede contener numeros o punto\n"RESET);
                verUso();
                return 1; // Error
            } 
            if(argv[i][j] == '.')
            {
                cont_punto_float++;
            }
            if(argv[i][j] == '.' && argv[i][j + 1] == ':')
            {
                printf(RED"ERROR: El punto del float esta mal colocado. Falta parte decimal\n"RESET);
                verUso();
                return 1; // Error
            }
            j++;
        }
        if(cont_punto_float > 1)
        {
            printf(RED"ERROR: El float puede contener un unico punto\n"RESET);
            verUso();
            return 1; // Error
        }
        if(argv[i][j] == ':')
        {
            cont_separadores++;
            j++;
        }
        // CATEGORIA (CHAR)
        while(argv[i][j] != '\0')
        {
            // Comprobamos la categoria es A, B o C
            if(
                argv[i][j] != 'A' && argv[i][j] != 'B' && argv[i][j] != 'C' &&
                argv[i][j] != 'a' && argv[i][j] != 'b' && argv[i][j] != 'c'
            )
            {
                printf(RED "ERROR 3: La CATEG debe ser 'A', 'B' o 'C'\n"RESET);
                verUso();
                return 1; // Error
            } 
            j++;
        }
        if(cont_separadores != 2)
        {
            printf("Formato incorrecto");
            return 1; // Error
        }
    }
    return 0;
}

/**
 * 
 * 
 */
int guardarObjetos()
{
    return 0;
}

/**
 * 
 * 
 */
void imprimirObjetos(char letra)
{

}

void verUso()
{
    printf(YELLOW
        "Uso  : ./main [ID]:[PESO]:[CATEG]...[ID]:[PESO]:[CATEG]\n"
        "Ej.  : ./main 101:2.5:A 102:3:B 103:1:C\n"RED
        "\n_________________________________________FAIL\n\n"RESET);
}


// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}