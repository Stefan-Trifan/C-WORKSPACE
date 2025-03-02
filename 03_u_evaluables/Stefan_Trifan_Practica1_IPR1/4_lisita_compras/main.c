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
#define TAM_STR 5
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

typedef struct ingrediente_t
{
    char nombre[TAM_STR];
    int cant;
    int tipo; // Crear enumeracion
}
ingrediente_t;

// Funciones del programa
void verLista();
void introducirIngrediente(ingrediente_t *ingrediente,int cont_ingredientes);
void eliminarIngrediente();
// Funciones auxiliares
int pedirEnteroPos();
void pedirCadena(char *text);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n_________________________________________START\n\n");

    ingrediente_t ingrediente[TAM_ARR];
    int opcion            = 0,
        cont_ingredientes = 0;

    do
    {
        printf(
            // "+--------------------------------+\n"
            // "|       LISTA DE LA COMPRA       |\n" // todo descomentar
            // "|--------------------------------|\n"
            // "|     Selecciona una opcion:     |\n"
            // "|                                |\n"
            "| [1] Listar                     |\n"
            "| [2] Introducir                 |\n"
            "| [3] Eliminar                   |\n"
            "| [4] Salir                      |\n"  
            // "+--------------------------------+\n"
            "-> ");

        do{ 
            opcion = pedirEnteroPos();
            if(opcion < 1 || opcion > 4) printf(RED"-> "RESET);
        }
        while (opcion < 1 || opcion > 4);

        // todo Poner en la misma linea
        switch (opcion)
        {
            case 1: 
                verLista(); 
                break;
            case 2: 
                introducirIngrediente(ingrediente, cont_ingredientes); 
                break;
            case 3: eliminarIngrediente(); 
                break;
        }
        
    } 
    while (opcion != 4);

    printf(
        "\n\n"
        "Muchas gracias por su visita!\n"
        "Saliendo del programa...\n");

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// typedef struct ingrediente_t
// {
//     char nombre[TAM_STR];
//     int cant;
//     int tipo; // Crear enumeracion
// }
// ingrediente_t;

// Funciones del programa
/**
 * @brief
 */
void verLista()
{
    printf("\n\n");
}

/**
 * @brief Introduce un ingrediente de la lista
 */
void introducirIngrediente(ingrediente_t *ingrediente, int cont_ingredientes)
{
    char temp[TAM_STR];

    // Pedimos el nombre del ingrediente
    printf(
        "Introduce el nombre del ingrediente que deseas aniadir\n"
        "(Max. %d caracteres)-> ", TAM_STR - 1);
    pedirCadena(temp);
    printf("DEBUG temp : %s\n", temp);

    // Si el ingrediente no existe lo crea

    // Si el ingrediente ya existe actualizamos la nueva cantidad
    printf("\n\n");
}

/**
 * @brief Elimina un ingrediente de la lista
 */
void eliminarIngrediente()
{
    // Comprobamos si el ingredeinte existe en la lista
    // Si existe lo eliminamos
    // Si no exite mostramos un error
    printf("\n\n");
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
void pedirCadena(char *text)
{
    int esValido = 0;
    char c;
    do
    {
        int i = 0;
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
                printf(
                    "\033[1;33mHas introducido demasiados caracteres\n"
                    "Intentalo de nuevo\n"
                    "-> \033[0m");
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
}

void clearBuffer()
{
    while (getchar() != '\n');
}