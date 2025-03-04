/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 4 
        Lista de la compra
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM_ARR 10
#define TAM_STR 16
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

typedef enum tipo_t 
{
    GRAMOS,
    UNIDADES
}tipo_t; 

typedef struct ingrediente_t
{
    char nombre[TAM_STR];
    int cant;
    tipo_t tipo;
}
ingrediente_t;

// Funciones del programa
void verLista(ingrediente_t *lista_ingredientes, int cont_ingredientes);
void introducirIngrediente(ingrediente_t *lista_ingredientes,int *cont_ingredientes);
void eliminarIngrediente(ingrediente_t *lista_ingredientes, int *cont_ingredientes);
// Funciones auxiliares
int pedirEnteroPos();
int pedirCadena(char *text);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n___________________________________________START\n\n");

    /// Probar el programa desde 0
        ingrediente_t lista_ingredientes[TAM_ARR] = {0};
        int cont_ingredientes = 0;

    /// testing: Probar el programa con ingredientes en la lista
        // ingrediente_t lista_ingredientes[TAM_ARR] = 
        // {
        //     {"uvas", 500, GRAMOS},
        //     {"patatas", 10, UNIDADES},
        //     {"tomates", 1500, GRAMOS},
        //     {"huevos", 12, UNIDADES}
        // };
        // int cont_ingredientes = 4; 
    
    int opcion = 0;

    // Menu
    do
    {
        printf(
            "+------------------------------------------+\n" 
            "|                MENU LISTA                |\n" 
            "|------------------------------------------|\n"
            "|          Selecciona una opcion:          |\n"
            "|                                          |\n"
            "| [1] Listar                               |\n"
            "| [2] Introducir                           |\n"
            "| [3] Eliminar                             |\n"
            "| [4] Salir                                |\n"  
            "+------------------------------------------+\n"
            "-> ");

        do{ 
            opcion = pedirEnteroPos();
            if(opcion < 1 || opcion > 4) printf(RED"-> "RESET);
        }
        while (opcion < 1 || opcion > 4);

        switch (opcion)
        {
            case 1: 
                printf("\n\n\n");
                if(cont_ingredientes)
                    printf("Hay %d elementos en la lista\n", cont_ingredientes);
                verLista(lista_ingredientes, cont_ingredientes); 
                printf("\n\n\n");
                break; 
            case 2: 
                printf("\n\n\n");
                if(cont_ingredientes < TAM_ARR)
                {
                    verLista(lista_ingredientes, cont_ingredientes); 
                    introducirIngrediente(lista_ingredientes, &cont_ingredientes); 
                    verLista(lista_ingredientes, cont_ingredientes); 
                }
                else
                {
                    printf("Has superado el limite de %d ingredientes en la lista", TAM_ARR);
                }
                printf("\n\n\n");
                break;
            case 3: 
                printf("\n\n\n");
                verLista(lista_ingredientes, cont_ingredientes);
                eliminarIngrediente(lista_ingredientes, &cont_ingredientes); 
                printf("\n\n\n");
                break;
        }
        
    } 
    while (opcion != 4);

    printf(
        "\n\n"
        "Muchas gracias por su visita!\n"
        "Saliendo del programa...\n\n");

    printf("\n___________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * @brief Imprime la lista de la compra en formato tabla
 *        Si no hay ingredientes en la lista imprime un mensaje
 * 
 * @param[out] lista_ingredientes Array de estructuras con cada uno de los ingredientes
 * @param[in] cont_ingredientes Contador de ingredientes
 */
void verLista(ingrediente_t *lista_ingredientes, int cont_ingredientes)
{

    if(cont_ingredientes)
    {
        printf(
                    "+------------------------------------------+\n"
                    "|                 Mi lista                 |\n"
                    "+-----+-----------------+------------------+\n");
        for(int i = 0; i < cont_ingredientes; i++)
        {
            if(lista_ingredientes[i].tipo == GRAMOS)
                printf(
                    "| %2dº | %15s | %7dg         |\n", 
                    i + 1, lista_ingredientes[i].nombre, lista_ingredientes[i].cant);
            else if (lista_ingredientes[i].tipo == UNIDADES)
                printf(
                    "| %2dº | %15s | %7d unidades |\n", 
                    i + 1, lista_ingredientes[i].nombre, lista_ingredientes[i].cant);
            printf( "+-----+-----------------+------------------+\n");
        }
    }
    else
        printf("No hay ingredientes en la lista\n");
}

/**
 * @brief Actualiza la lista de ingredientes
 *      1. Pide el nombre del ingrediente
 *      2. Comprueba si el ingrediente existe
 *          a. Si existe actualizamos la cantidad
 *          b. Si no existe lo añade
 */
void introducirIngrediente(ingrediente_t *lista_ingredientes, int *cont_ingredientes)
{
    // Array temporal donde guardamos el nombre del ingrediente 
    // que introduce el usuario mientras comprobamos si ya existe o no
    char arr_temporal[TAM_STR] = {0};
    int  existe_ingrediente    = 0,
         num_letras_user       = 0,
         i                     = 0,
         opcion                = 0;

    // Pedimos el nombre del ingrediente
    printf(
        "\nIntroduce el nombre del ingrediente que deseas aniadir\n"
        "(Max. %d caracteres)-> ", TAM_STR - 1);
    num_letras_user = pedirCadena(arr_temporal);

    // TODO: crear funcion comprobarSiExiste() con este codigo
    // Comprobamos si el elemento ya existe en la lista
    for(i = 0; i < *cont_ingredientes; i++)
    {
        int num_letras_coinciden = 0, j = 0;

        while(lista_ingredientes[i].nombre[j] != '\0')
        {
            if(arr_temporal[j] == lista_ingredientes[i].nombre[j])
            {
                num_letras_coinciden++;
            };
            j++;
        }
        if(num_letras_user == num_letras_coinciden && num_letras_coinciden == j)
        {
            existe_ingrediente = 1;
            break;
        }
    }

    // Si el ingrediente ya existe actualizamos la nueva cantidad
    if(existe_ingrediente)
    {
        if(lista_ingredientes[i].tipo == GRAMOS)
        {
            printf(
                "\nActualmente hay %dg\n"
                "Que cantidad desea aniadir?\n"
                "-> ", lista_ingredientes[i].cant);
        }
        else
        {
            printf(
                "\nActualmente hay %d unidades\n"
                "Que cantidad desea aniadir?\n"
                "-> ", lista_ingredientes[i].cant);
        }
        (lista_ingredientes + i)->cant += pedirEnteroPos();
    }
    // Si el ingrediente no existe lo crea
    else
    {
        printf("El elemento NO existe en la lista\n");

        // Copiamos el nombre del array temporal nuestra la lista
        int j = 0;
        while(arr_temporal[j] != '\0')
        {
            (lista_ingredientes + i)->nombre[j] = arr_temporal[j];
            j++;
        }
        (lista_ingredientes + i)->nombre[j] = '\0';

        // Pedimos la cantidad
        printf("¿Que cantidad desea introducir?\n-> ");
        (lista_ingredientes + i)->cant = pedirEnteroPos();

        // Pedimos el tipo de medida
        do
        {
            printf(
                "Introduzca\n"
                "[0] Gramos\n"
                "[1] Unidades\n"
                "-> ");
            opcion = pedirEnteroPos();
            if(opcion == 1)
            {
                (lista_ingredientes + i)->tipo = UNIDADES;
            }
            else
            {
                (lista_ingredientes + i)->tipo = GRAMOS;
            }
        } 
        while (opcion != 1 && opcion != 0);

        // Actualizamos la cantidad de ingredientes
        (*cont_ingredientes)++;
    }
    printf(GREEN"La lista ha sido actualizada con exito\n"RESET);
}

/**
 * @brief Elimina un ingrediente de la lista
 *      - Si el ingrediente no existe en la lista avisamos al usuario
 */
void eliminarIngrediente(ingrediente_t *lista_ingredientes, int *cont_ingredientes)
{
    /// Array temporal donde guardamos el nombre del ingrediente 
    // que introduce el usuario mientras comprobamos si ya existe o no
    char arr_temporal[TAM_STR] = {0};
    int  existe_ingrediente    = 0,
         num_letras_user       = 0,
         i                     = 0,
         opcion                = 0;

    // Pedimos el nombre del ingrediente
    printf(
        "\nIntroduce el nombre del ingrediente que deseas eliminar\n"
        "(Max. %d caracteres)-> ", TAM_STR - 1);
    num_letras_user = pedirCadena(arr_temporal);

    // TODO: crear funcion comprobarSiExiste() con este codigo
    // Comprobamos si el elemento ya existe en la lista
    for(i = 0; i < *cont_ingredientes; i++)
    {
        int num_letras_coinciden = 0, j = 0;

        while(lista_ingredientes[i].nombre[j] != '\0')
        {
            if(arr_temporal[j] == lista_ingredientes[i].nombre[j])
            {
                num_letras_coinciden++;
            };
            j++;
        }
        if(num_letras_user == num_letras_coinciden && num_letras_coinciden == j)
        {
            existe_ingrediente = 1;
            break;
        }
    }
    
    if(existe_ingrediente)
    {
        // Si el ingrediente existe en la lista lo eliminamos
        for (int j = 0; j < TAM_STR; j++) 
        {
            (lista_ingredientes + i)->nombre[j] = '\0';
        }
        (lista_ingredientes + i)->cant = 0;
        (lista_ingredientes + i)->tipo = GRAMOS;
        
        // Actualizamos el contador de ingredientes
        (*cont_ingredientes)--;
        
        // Movemos todos los elementos superiores en la lista una posicion mas abajo
        // printf(
        //     "DEBUG i = %d\n"
        //     "DEBUG cont_elementos = %d\n", i, *cont_ingredientes);
        for(; i < *cont_ingredientes; i++)
        {
            int j = 0;
            while((lista_ingredientes + i + 1)->nombre[j] != '\0')
            {
                (lista_ingredientes + i)->nombre[j] = (lista_ingredientes + i + 1)->nombre[j];
                j++;
            }
            (lista_ingredientes + i)->nombre[j] = '\0';
            (lista_ingredientes + i)->cant = (lista_ingredientes + i + 1)->cant;
            (lista_ingredientes + i)->tipo = (lista_ingredientes + i + 1)->tipo;
        }

        printf(GREEN"La lista ha sido actualizada con exito\n"RESET);
        verLista(lista_ingredientes, *cont_ingredientes); 
    }
    // Si el ingrediente no existe en la lista mostramos un error
    else
    {
        printf(RED
            "El elemento no se ha podido eliminar\n"
            "Por que no existe en la lista\n"RESET);
    }
}

// Funciones auxiliares
/**
 * @brief Solicita al usuario un entero positivo hasta que introduzca un valor valido
 * @return entero positivo
 */
int pedirEnteroPos()
{
    int num = 0, esValido = 0;
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if(esValido != 1 || num < 0)
        {
            printf(RED"ERROR: El numero debe ser positivo\n-> "RESET);
            esValido = 0;
        }
        if(esValido == 1 && num > 9999999)
        {
            printf(RED"ERROR: El numero debe tener 7 digitos o menos\n-> "RESET);
            esValido = 0;
        }
    } 
    while (esValido != 1);
    return num;
}

/**
 * @brief Solicita al usuario una cadena de caracteres
 *      - Si el usuario introduce mas caracteres de los permitidos, 
 *        se muestra un error y se le pide que vuelva a intentarlo.
 * @param[out] text Puntero a un arreglo donde se almacena el ingrediente
 */
int pedirCadena(char *text)
{
    int i = 0, esValido;
    char c;
    do
    {
        i = 0;
        esValido = 1;
        while (i < TAM_STR - 1)
        {
            c = getchar();

            // printf("DEBUG: i = %d, c = %c (%d)\n", i, c, c);
            if(c == '\n') break;
                
            text[i] = c;
            i++; 
        }
        text[i] = '\0'; 

        // printf("DEBUG SALIDA WHILE: i = %d, c = %c (%d)\n", i, c, c);
        
        if(i == TAM_STR - 1)
        {
            c = getchar();
            if(c != '\n')
            {
                printf(
                    "\033[1;33mHas introducido demasiados caracteres\n"
                    "Intentalo de nuevo\n"
                    "-> \033[0m");
                clearBuffer();
                esValido = 0;
            }
        }
    } 
    while (esValido != 1);
    return i;
}

void clearBuffer()
{
    while (getchar() != '\n');
}