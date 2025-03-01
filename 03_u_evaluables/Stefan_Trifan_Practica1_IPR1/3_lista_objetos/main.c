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
#include <stdlib.h> // Para strtol() y strtof()

#define TAM_ARR 10
#define TAM_TEMP 10
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

typedef struct objeto_t
{
    int id;
    float peso;
    char categ;
}
objeto_t;

// Funciones del programa
int procesarArgumentos(int argc);
int comprobarObjetos(int argc, char *argv[]);
void guardarObjetos(objeto_t *objeto, int argc, char *argv[]);
void imprimirObjetos(char letra, objeto_t *objeto, int argc);
void verUso();
// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    objeto_t objeto[TAM_ARR] = {0};
    int err         = 0; 

    // Comprobamos que el usuario respeta el limite de objetos
    if(argc < 2 || argc > 11)
    {
        printf(RED"ERROR: Tienes que introducir entre 1 y %d objetos.\n"RESET, TAM_ARR);
        verUso();
        return 1; // error
    }

    // Devuelve un error si el ID, peso o categoria no son correctos
    err = comprobarObjetos(argc, argv);
    if(err) return 1;

    // Guardamos los objetos en nuestro array de estructuras
    guardarObjetos(objeto, argc, argv);

    // Imprimimos los objetos en orden
    imprimirObjetos('A', objeto, argc);
    imprimirObjetos('B', objeto, argc);
    imprimirObjetos('C', objeto, argc);

    printf("_________________________________________END\n\n");
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
        // Comprobamos la categoria es 'A', 'B' o 'C'
        if(
            argv[i][j]     != 'A' && argv[i][j] != 'B' && argv[i][j] != 'C' &&
            argv[i][j]     != 'a' && argv[i][j] != 'b' && argv[i][j] != 'c' ||
            argv[i][j + 1] != '\0'
        )
        {
            printf(RED "ERROR: La CATEG debe ser 'A', 'B' o 'C'\n"RESET);
            verUso();
            return 1; // Error
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
 * Guardamos los objetos en nuestro array de estructuras
 * @param[out] objeto Array de estructuras que contiene los objetos
 */
void guardarObjetos(objeto_t *objeto, int argc, char *argv[])
{
    for(int i_str = 1; i_str < argc; i_str++)
    {
        char temp[TAM_TEMP] = {0}; // Array temporal
        int i_char = 0;
        int i_temp = 0;

        // 1º MIEMBRO
        // Guardamos dentro de temp el ID
        while(argv[i_str][i_char] != ':')
        {
            temp[i_temp] = argv[i_str][i_char];
            i_char++;
            i_temp++;
        }
        // Convertimos temp a INT y lo guardamos en nuestra estructura
        (objeto + (i_str - 1))->id = strtol(temp, NULL, 10);

        // 2º MIEMBRO
        if(argv[i_str][i_char] == ':')
        {
            i_char++;
            // Resteamos temp
            i_temp = 0;
            for(int i = 0; i < TAM_TEMP; i++) temp[i] = '\0';
        }

        // Guardamos dentro de temp el PESO
        while(argv[i_str][i_char] != ':')
        {
            temp[i_temp] = argv[i_str][i_char];
            i_char++;
            i_temp++;
        }
        // Convertimos temp a FLOAT y lo guardamos en nuestra estructura
        (objeto + (i_str - 1))->peso = strtof(temp, NULL);

        // 3º MIEMBRO
        if(argv[i_str][i_char] == ':') i_char++;

        // Guardamos en nuestra estructura la categoria
        (objeto + (i_str - 1))->categ = argv[i_str][i_char];
    }
}

/**
 * @param[in] letra : Recibe la categoria que va a imprimir la funcion 
 * 
 */
void imprimirObjetos(char letra, objeto_t *objeto, int argc)
{
    int primera_coincidencia = 0;
    for(int i = 0; i < argc - 1; i++)
    {
        if(!primera_coincidencia && objeto[i].categ == letra)
        {
            printf("CATEGORIA %c\n\n", letra);
            primera_coincidencia++;
        }
        if(objeto[i].categ == letra)
        {
            printf(GREEN
                "ID    : %d\n"
                "Peso  : %.2f\n"
                "Categ : %c\n"
                "\n"RESET, 
                objeto[i].id, objeto[i].peso, objeto[i].categ);
        }
    }
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

/* 
    DEBUG LOG 
    printf("DEBUG num_objetos: %d\n\n\n", argc - 1);

    printf("DEBUG id 0   : %d\n", objeto[0].id);
    printf("DEBUG id 1   : %d\n", objeto[1].id);
    printf("DEBUG id 2   : %d\n", objeto[2].id);
    printf("DEBUG id 3   : %d\n", objeto[3].id);
    printf("DEBUG id 4   : %d\n", objeto[4].id);
    printf("DEBUG id 5   : %d\n", objeto[5].id);
    printf("DEBUG id 6   : %d\n", objeto[6].id);
    printf("\n\n");
    printf("DEBUG peso 0 : %.2f\n", objeto[0].peso);
    printf("DEBUG peso 1 : %.2f\n", objeto[1].peso);
    printf("DEBUG peso 2 : %.2f\n", objeto[2].peso);
    printf("DEBUG peso 3 : %.2f\n", objeto[3].peso);
    printf("DEBUG peso 4 : %.2f\n", objeto[4].peso);
    printf("DEBUG peso 5 : %.2f\n", objeto[5].peso);
    printf("DEBUG peso 6 : %.2f\n", objeto[6].peso);
    printf("\n\n");
    printf("DEBUG categ 0: %c\n", objeto[0].categ);
    printf("DEBUG categ 1: %c\n", objeto[1].categ);
    printf("DEBUG categ 2: %c\n", objeto[2].categ);
    printf("DEBUG categ 3: %c\n", objeto[3].categ);
    printf("DEBUG categ 4: %c\n", objeto[4].categ);
    printf("DEBUG categ 5: %c\n", objeto[5].categ);
    printf("DEBUG categ 6: %c\n", objeto[6].categ);
*/