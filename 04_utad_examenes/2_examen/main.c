#include <stdio.h>
#include <stdlib.h>

#define TAM_BLOQUE 10
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

typedef enum
{
    INTRODUCIR = 1, IMPRIMIR, FILTRAR, SALIR
}
opcion_t;

typedef struct
{
    char *marca_modelo;
    int kilometros;
    int anio_matriculacion;
    float precio;
}
coche_t;

// Funciones del programa
void introducircoche(coche_t* concesionario, int num_coche);
void imprimeCoche(coche_t *coche, int i);
void filtrarCoches(int total_coches, coche_t* concesionario);

// Funciones auxiliares
char* leeLineaDinamica();
int pedirEntero();
float pedirFloat();
void clearBuffer();

// Main

int main()
{
    printf("\n________________________________START\n\n");

    // Declaracion de variables    
    coche_t *coche = (coche_t *)malloc(sizeof(coche_t));
    int num_coche    = 0,
        total_coches = 0;
    opcion_t opcion;

    // Menu de opciones
    do
    {
        printf(
            "----- MENÚ -----\n"
            "1. Introducir coche\n"
            "2. Imprimir coches del concesionario\n"
            "3. Filtrar por kilómetros y año de matriculacion\n"
            "4. Salir\n");

        opcion = pedirEntero();

        switch (opcion)
        {
            case INTRODUCIR: 
                total_coches++;
                coche = (coche_t *)realloc(coche, total_coches * sizeof(coche_t));
                introducircoche(coche, num_coche);
                num_coche++;
                break;
            case IMPRIMIR: 
                for(int i = 0; i < total_coches; i++)
                {
                    imprimeCoche(coche, i);
                }
                printf("\n\n");
                break;
            case FILTRAR: 
                filtrarCoches(total_coches, coche);
                break;
            case SALIR: 
                printf("Saliendo...\n");
                break;
            default: 
                break;
        }
    } 
    while (opcion != 4);

    // Liberamos la memoria reservada
    for(int i = 0; i < total_coches; i++)
    {
        free(coche[i].marca_modelo);
    }
    free(coche);
    
    printf("\n\n________________________________END\n\n");
    return 0;
}

// Funciones del programa
/**
 * Función que se le pasa como parámetros la dirección de memoria donde comienza el
 * concesionario y el índice que ocupa el coche dentro del concesionario e incluye en el    
 * concesionario el nuevo coche con sus valores
 */
void introducircoche(coche_t* concesionario, int num_coche)
{
    printf("Introduce la marca y el modelo\n-> ");
    (concesionario + num_coche)->marca_modelo = leeLineaDinamica();
    
    printf("Introduce los kilometros\n");
    (concesionario + num_coche)->kilometros = pedirEntero();

    printf("Introduce el anio de matriculacion\n");
    (concesionario + num_coche)->anio_matriculacion = pedirEntero();

    printf("Introduce el precio\n");
    (concesionario + num_coche)->precio = pedirEntero();

    printf(GREEN"Coche aniadido con exito\n\n"RESET);
}

/**
 * Función que reciba una copia de un coche y lo imprima por pantalla
 */
void imprimeCoche(coche_t *coche, int i)
{
    printf("\nCOCHE %d\n", i);
    printf("Marca y modelo  = %s\n", (coche + i)->marca_modelo);
    printf("Kilometros      = %d\n", (coche + i)->kilometros);
    printf("Matriculacion   = %d\n", (coche + i)->anio_matriculacion);
    printf("Precio          = %f\n", (coche + i)->precio);
}

/**
 * Función en la que se realiza el filtrado de los coches solicitando los valores de kilómetros y año
 * y muestra los coches que cumplen con el filtro
 */
void filtrarCoches(int total_coches, coche_t* concesionario)
{
    int min_anio_fabricacion = 0, max_kilometros = 0;

    printf("Ingrese el anio minimo de fabricacion\n");
    min_anio_fabricacion = pedirEntero();

    printf("Ingrese los kilometros maximos\n");
    max_kilometros = pedirEntero();

    printf("Coches que cumplen los filtros: \n");

    // Filtramos los coches por anio de fabricacion
    for(int i = 0; i < total_coches; i++)
    {
        if(
            ((concesionario + i)->kilometros <= max_kilometros) &&
            ((concesionario + i)->anio_matriculacion >= min_anio_fabricacion)
        )
        {
            printf("\nCOCHE %d\n", i);
            printf("marca_modelo  = %s\n"  , (concesionario + i)->marca_modelo);
            printf("kilometros    = %d\n"  , (concesionario + i)->kilometros);
            printf("matriculacion = %d\n"  , (concesionario + i)->anio_matriculacion);
            printf("precio        = %f\n\n", (concesionario + i)->precio);
        }
    }
}

// Funciones auxiliares
/**
 * Función que devuelve una cadena de caracteres leída del buffer I/O y que realiza la reserva de
 * memoria dinámica por bloques para la cadena 
 */
char* leeLineaDinamica()
{
    char *texto_destino = (char *)malloc(sizeof(char));
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while((c = getchar()) != '\n')
    {
        if(i == memoria_actual)
        {
            memoria_actual += TAM_BLOQUE;
            texto_destino = (char *)realloc(texto_destino, memoria_actual * sizeof(char));
        }
        texto_destino[i] = c;
        i++;
    }
    texto_destino[i] = '\0';

    return texto_destino;
}

/**
 * Pide un entero con manejo de errores
 */
int pedirEntero()
{
    int num = 0, esValido = 0;
    
    do
    {
        printf("-> ");
        esValido = scanf("%d", &num);
        clearBuffer();
        if(esValido != 1)
        {
            printf("Intentelo de nuevo\n");
        }
    } 
    while (esValido != 1);

    return num;
}

/**
 * Pide un float con manejo de errores
 */
float pedirFloat()
{
    float num = 0;
    int esValido = 0;
    
    do
    {
        printf("-> ");
        esValido = scanf("%f", &num);
        clearBuffer();
        if(esValido != 1)
        {
            printf("Intentelo de nuevo\n");
        }
    } 
    while (esValido != 1);

    return num;
}

void clearBuffer()
{
    while(getchar() != '\n');
}

// DEBUG
// printf("marca_modelo  = %s\n", (coche + 0)->marca_modelo);
// printf("kilometros    = %d\n", (coche + 0)->kilometros);
// printf("matriculacion = %d\n", (coche + 0)->anio_matriculacion);
// printf("precio        = %f\n", (coche + 0)->precio);

// printf("marca_modelo  = %s\n", (coche + 1)->marca_modelo);
// printf("kilometros    = %d\n", (coche + 1)->kilometros);
// printf("matriculacion = %d\n", (coche + 1)->anio_matriculacion);
// printf("precio        = %f\n", (coche + 1)->precio);