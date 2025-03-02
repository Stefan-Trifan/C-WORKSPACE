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
void eliminarIngrediente();
// Funciones auxiliares
int pedirEnteroPos();
int pedirCadena(char *text);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n___________________________________________START\n\n");

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
            // "+-----------------------------------------+\n" 
            // "|           LISTA DE LA COMPRA            |\n" 
            // "|-----------------------------------------|\n"
            // "|         Selecciona una opcion:          |\n"
            // "|                                         |\n"
            "| [1] Listar                              |\n"
            "| [2] Introducir                          |\n"
            "| [3] Eliminar                            |\n"
            "| [4] Salir                               |\n"  
            // "+-----------------------------------------+\n"
            "-> ");

        do{ 
            opcion = pedirEnteroPos();
            if(opcion < 1 || opcion > 4) printf(RED"-> "RESET);
        }
        while (opcion < 1 || opcion > 4);

        switch (opcion)
        {
            case 1: 
                printf("\n\n");
                verLista(ingrediente, cont_ingredientes); 
                printf("\n\n\n\n");
                break; 
            case 2: 
                printf("\n\n");
                verLista(ingrediente, cont_ingredientes); // Todo eliminar verLista
                introducirIngrediente(ingrediente, &cont_ingredientes); 
                // verLista(ingrediente, cont_ingredientes); // Todo eliminar verLista
                printf("\n\n\n\n");
                break;
            case 3: 
                printf("\n\n");
                eliminarIngrediente(); 
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
        printf(
            "Hay %d elementos en la lista\n"
            "+-----------------------------------------+\n", cont_ingredientes);
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

// typedef struct ingrediente_t
// {
//     char nombre[TAM_STR];
//     int cant;
//     int tipo; // Crear enumeracion
// }
// ingrediente_t;

/**
 * @brief Introduce un ingrediente de la lista
 */
void introducirIngrediente(ingrediente_t *ingrediente, int *cont_ingredientes)
{
    /// @brief array temporal donde guardamos el nombre del ingrediente 
    // que introduce el usuario mientras comprobamos si ya existe o no
    char temp[TAM_STR]      = {0};
    int  existe_ingrediente = 0,
         num_letras_user    = 0,
         i                  = 0;

    // Pedimos el nombre del ingrediente
    printf(
        "Introduce el nombre del ingrediente que deseas aniadir\n"
        "(Max. %d caracteres)-> ", TAM_STR - 1);
    num_letras_user = pedirCadena(temp);

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
    printf("DEBUG i = %d\n", i);

    // Si el ingrediente ya existe actualizamos la nueva cantidad
    if(existe_ingrediente)
    {
        printf("El elemento existe en la lista\n");
    }
    // Si el ingrediente no existe lo crea
    else
    {
        printf("El elemento NO existe en la lista\n");
    }
}

/**
 * @brief Elimina un ingrediente de la lista
 */
void eliminarIngrediente()
{
    // Comprobamos si el ingredeinte existe en la lista
    // Si existe lo eliminamos
    // Si no exite mostramos un error
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
    int esValido = 1, i = 0;
    char c;
    do
    {
        i = 0;
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
                    "Has introducido demasiados caracteres\n"
                    "Intentelo de nuevo\n"
                    "-> "RESET);
                clearBuffer();
                esValido = 0;
            }
            else
            {
                esValido = 1;
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