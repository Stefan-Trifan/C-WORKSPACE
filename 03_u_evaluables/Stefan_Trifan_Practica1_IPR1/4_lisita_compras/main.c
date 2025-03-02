/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 4 
        Lista de la compra

    *   Testing
        
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
void verLista(ingrediente_t *ingrediente, int cont_ingredientes);
void introducirIngrediente(ingrediente_t *ingrediente,int *cont_ingredientes);
void eliminarIngrediente(ingrediente_t *ingrediente, int *cont_ingredientes);
// Funciones auxiliares
int pedirEnteroPos();
int pedirCadena(char *text);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n___________________________________________START\n\n");

    // todo comentar bien el codigo

    // todo restablecer a 0
    ingrediente_t ingrediente[TAM_ARR] = 
    {
        {"uvas", 500, GRAMOS},
        {"tomates", 3, UNIDADES},
        {"patatas", 10, UNIDADES}
    };
    int opcion            = 0,
        cont_ingredientes = 3;

    do
    {
        // todo descomentar
        printf(
            "+-----------------------------------------+\n" 
            "|           LISTA DE LA COMPRA            |\n" 
            "|-----------------------------------------|\n"
            "|         Selecciona una opcion:          |\n"
            "|                                         |\n"
            "| [1] Listar                              |\n"
            "| [2] Introducir                          |\n"
            "| [3] Eliminar                            |\n"
            "| [4] Salir                               |\n"  
            "+-----------------------------------------+\n"
            "-> ");

        do{ 
            opcion = pedirEnteroPos();
            if(opcion < 1 || opcion > 4) printf(RED"-> "RESET);
        }
        while (opcion < 1 || opcion > 4);

        switch (opcion)
        {
            case 1: 
                printf("\n\n\n\n");
                printf("Hay %d elementos en la lista\n", cont_ingredientes);
                verLista(ingrediente, cont_ingredientes); 
                printf("\n\n\n\n");
                break; 
            case 2: 
                printf("\n\n\n\n");
                introducirIngrediente(ingrediente, &cont_ingredientes); 
                verLista(ingrediente, cont_ingredientes); // Todo eliminar verLista
                printf("\n\n\n\n");
                break;
            case 3: 
                printf("\n\n\n\n");
                verLista(ingrediente, cont_ingredientes);
                eliminarIngrediente(ingrediente, &cont_ingredientes); 
                verLista(ingrediente, cont_ingredientes);
                printf("\n\n\n\n");
                break;
        }
        
    } 
    while (opcion != 4);

    printf(
        "\n\n"
        "Muchas gracias por su visita!\n"
        "Saliendo del programa...\n");

    printf("\n___________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * @brief 
 */
void verLista(ingrediente_t *ingrediente, int cont_ingredientes)
{

    if(cont_ingredientes)
    {
        printf("+-----------------------------------------+\n");
        for(int i = 0; i < cont_ingredientes; i++)
        {
            if(ingrediente[i].tipo == GRAMOS)
            {
                printf(
                    "| %2dº | %15s | %6dg         |\n", 
                    i + 1, ingrediente[i].nombre, ingrediente[i].cant);
            }
            else if (ingrediente[i].tipo == UNIDADES)
            {
                printf(
                    "| %2dº | %15s | %6d unidades |\n", 
                    i + 1, ingrediente[i].nombre, ingrediente[i].cant);
            }
            if(i < cont_ingredientes - 1)
            {
                printf("|-----------------------------------------|\n");
            }
        }
        printf("+-----------------------------------------+\n");
    }
    else
    {
        printf("No hay ingredientes en la lista\n");
    }
    
}

/**
 * @brief Introduce un ingrediente de la lista
 */
void introducirIngrediente(ingrediente_t *ingrediente, int *cont_ingredientes)
{
    /// @brief array temporal donde guardamos el nombre del ingrediente 
    // que introduce el usuario mientras comprobamos si ya existe o no
    char temp[TAM_STR]      = {0};
    int existe_ingrediente = 0,
        num_letras_user    = 0,
        i                  = 0,
        opcion             = 0;

    // Pedimos el nombre del ingrediente
    printf(
        "\nIntroduce el nombre del ingrediente que deseas aniadir\n"
        "(Max. %d caracteres)-> ", TAM_STR - 1);
    num_letras_user = pedirCadena(temp);

    // todo crear funcion codigo repetido
    // Comprobamos si el elemento ya existe en la lista
    for(i = 0; i < *cont_ingredientes; i++)
    {
        int num_letras_coinciden = 0, j = 0;

        while(ingrediente[i].nombre[j] != '\0')
        {
            if(temp[j] == ingrediente[i].nombre[j])
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
        if(ingrediente[i].tipo == GRAMOS)
        {
            printf(
                "\nActualmente hay %dg\n"
                "Que cantidad desea aniadir?\n"
                "-> ", ingrediente[i].cant);
        }
        else
        {
            printf(
                "\nActualmente hay %d unidades\n"
                "Que cantidad desea aniadir?\n"
                "-> ", ingrediente[i].cant);
        }
        (ingrediente + i)->cant += pedirEnteroPos();
    }
    // Si el ingrediente no existe lo crea
    else
    {
        printf("El elemento NO existe en la lista\n");

        // Guardamos el nombre
        int j = 0;
        while(temp[j] != '\0')
        {
            (ingrediente + i)->nombre[j] = temp[j];
            j++;
        }
        (ingrediente + i)->nombre[j] = '\0';

        // Pedimos la cantidad
        printf("¿Que cantidad desea introducir?\n-> ");
        (ingrediente + i)->cant = pedirEnteroPos();

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
                (ingrediente + i)->tipo = UNIDADES;
            }
            else
            {
                (ingrediente + i)->tipo = GRAMOS;
            }
        } 
        while (opcion != 1 && opcion != 0);

        (*cont_ingredientes)++;
    }
    printf(GREEN"La lista ha sido actualizada con exito\n"RESET);
}

/**
 * @brief Elimina un ingrediente de la lista
 */
void eliminarIngrediente(ingrediente_t *ingrediente, int *cont_ingredientes)
{
    
    /// @brief array temporal donde guardamos el nombre del ingrediente 
    // que introduce el usuario mientras comprobamos si ya existe o no
    char temp[TAM_STR]      = {0};
    int existe_ingrediente = 0,
        num_letras_user    = 0,
        i                  = 0,
        opcion             = 0;

    // Pedimos el nombre del ingrediente
    printf(
        "\nIntroduce el nombre del ingrediente que deseas eliminar\n"
        "(Max. %d caracteres)-> ", TAM_STR - 1);
    num_letras_user = pedirCadena(temp);

    // todo crear funcion codigo repetido
    // Comprobamos si el elemento ya existe en la lista
    for(i = 0; i < *cont_ingredientes; i++)
    {
        int num_letras_coinciden = 0, j = 0;

        while(ingrediente[i].nombre[j] != '\0')
        {
            if(temp[j] == ingrediente[i].nombre[j])
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
            (ingrediente + i)->nombre[j] = '\0';
        }
        (ingrediente + i)->cant = 0;
        (ingrediente + i)->tipo = GRAMOS;
        
        // Movemos todos los elementos superiores en la lista una posicion mas abajo
        printf(
            "DEBUG i = %d\n"
            "DEBUG cont_elementos = %d\n", i, *cont_ingredientes);

        // typedef struct ingrediente_t
        // {
        //     char nombre[TAM_STR];
        //     int cant;
        //     tipo_t tipo;
        // }
        // ingrediente_t;

        for(; i < *cont_ingredientes + 3; i++)
        {
            int j = 0;
            while((ingrediente + i + 1)->nombre[j] != '\0')
            {
                (ingrediente + i)->nombre[j] = (ingrediente + i + 1)->nombre[j];
                j++;
            }
            (ingrediente + i)->cant = (ingrediente + i + 1)->cant;
            (ingrediente + i)->tipo = (ingrediente + i + 1)->tipo;
        }

        (*cont_ingredientes)--;


        printf(GREEN"La lista ha sido actualizada con exito\n"RESET);
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
 * @brief solicita al usuario un entero positivo hasta que introduzca un valor valido
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
    } 
    while (esValido != 1);
    return num;
}

/**
 * @brief Solicita al usuario una cadena de caracteres
 *      - Si el usuario introduce más caracteres de los permitidos, 
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
            if(c == '\n')
				break;
                
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