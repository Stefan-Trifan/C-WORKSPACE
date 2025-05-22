/**
 *  Nombre:
 *      Stefan Trifan
 * 
 * Hora Inicio:
 *      09: 30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_BLOQUE 10

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

char* grupoStr[]= { "MAMIFERO", "AVE", "REPTIL", "DESCONOCIDO"};

typedef enum
{
    MAMIFERO, AVE, REPTIL, DESCONOCIDO
}
grupo_e;

typedef struct
{
    char    *nombre_comun;
    grupo_e  grupo_taxonomico;
    int      cantidad_ejemplares;
}
contenedor_especie_t; // "contenedor_especie_t" === "especie_t"

// Funciones del programa
grupo_e stringAGrupo(char *grupo);
contenedor_especie_t pideEspecie();

// Funciones auxiliares
int pedirEntero();
char *leeLineaDinamica();
void clearBuffer();

/*  ____________________________________________
    Inicio main*/

int main(int argc, char *argv[])
{
    printf("________________________________________START\n\n");
   
    // El nombre del fichero con los datos de las especies censadas 
    // se le pasarán al programa por parámetros del main.
    if(argc != 2)
    {
        printf("\033[1;31mUSO: ./main <nombre_archivo.txt\033[0m");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }   
    
    // Declaracion de variables
    FILE *fd = fopen(argv[1], "w+");
    contenedor_especie_t *c_especies = (contenedor_especie_t *)malloc(sizeof(contenedor_especie_t));
    char *salir;
    int num_especies = 0;

    // Comprobamos que el archivo se ha creado con exito
    if(fd == NULL)
    {
        printf("\033[1;31mERROR: No ha sido posible crear el fichero\n\033[0m");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;
    }
    else
    {
        printf("\033[1;32mArchivo abieto correctamente\n\n\033[0m");
    }

    // Pedir datos
    do
    {
        // Llamada a la funcion pideEspecie()
        c_especies[num_especies] = pideEspecie();

        // El programa debe pedir datos de cada especie hasta que el usuario lo desee 
        // (preguntar si debe continuar después de haber leído una especie correctamente
        printf("Quieres seguir introduciendo especies?\n-> ");
        do
        {
            salir = leeLineaDinamica();
            if((strcmp(salir, "si") != 0) && (strcmp(salir, "no") != 0))
            {
                printf(YELLOW"Introduzca si/no\n"RESET);
            }
        } 
        while ((strcmp(salir, "si") != 0) && (strcmp(salir, "no") != 0) );
        
        // Si se quiere seguir ampliamos la memoria
        if((strcmp(salir, "si") == 0))
        {
            // Incrementamos el numero de animales
            num_especies++;
            c_especies = (contenedor_especie_t *)realloc(c_especies, sizeof(contenedor_especie_t) * (num_especies + 1));
        }
    } 
    while (strcmp(salir, "si") == 0);   

    // Se añadirán al fichero pasado por parámetros del main con el siguiente formato
    // <Nombre común>;<grupo taxonómico>;<cantidad de ejemplares>
    for(int i = 0; i <= num_especies; i++)
    {
        if(c_especies[i].grupo_taxonomico == 0)
            fprintf
            (
                fd, 
                "%s;MAMIFERO;%d\n", 
                c_especies[i].nombre_comun,
                c_especies[i].cantidad_ejemplares
            );
        else if (c_especies[i].grupo_taxonomico == 1)
            fprintf
            (
                fd, 
                "%s;AVE;%d\n", 
                c_especies[i].nombre_comun,
                c_especies[i].cantidad_ejemplares
            );
        else if (c_especies[i].grupo_taxonomico == 2)
            fprintf
            (
                fd, 
                "%s;REPTIL;%d\n", 
                c_especies[i].nombre_comun,
                c_especies[i].cantidad_ejemplares
            );   
    }

    // Una vez que el usuario hayamos determinado no seguir introduciendo datos 
    // el programa debe presentar por pantalla todas las especies introducidas 
    // en esa sesión en orden inverso.
    printf("\n\n");
    int contador_inverso = num_especies;
    for(int i = 0; i <= num_especies; i++)
    {
        printf("Nombre: %s\n", c_especies[contador_inverso].nombre_comun);

        if(c_especies[contador_inverso].grupo_taxonomico == 0)
        {
            printf("Grupo: MAMIFERO\n");
        }
        else if (c_especies[contador_inverso].grupo_taxonomico == 1)
        {
            printf("Grupo: AVE\n");
        }     
        else if (c_especies[contador_inverso].grupo_taxonomico == 2)
        {
            printf("Grupo: REPTIL\n");
        }
        
        printf("Numero: %d\n\n", c_especies[contador_inverso].cantidad_ejemplares);

        contador_inverso--;     
    }

    // Liberar memoria y cerrar fd para salvar su contenido:
    fclose(fd);
    for(int i = 0; i < num_especies + 1; i++)
    {
        free(c_especies[i].nombre_comun);
    }
    free(c_especies);
    
    printf("\n________________________________________END\n\n");
    return EXIT_SUCCESS;
}

/*  ____________________________________________
    Inicio declaracion de funciones */

// Funciones del programa
/**
 * Función que pide datos de una especie por terminal
 * Rellena un elemento de tipo "contenedor_especie_t" con 
 * datos leidos y lo devuelve por parámetros de return 
 */
contenedor_especie_t pideEspecie()
{
    // Declaracion de variables
    contenedor_especie_t nueva_especie;
    char *temp;

    // Rellenamos los miembros con los datos que menciona el usuario
    printf("Introduzca nombre de especie:\n-> ");
    nueva_especie.nombre_comun = leeLineaDinamica();

    // En grupo taxonomico el usuario debe introducir la palabra correspondiente
    // Comparamos la cadena con dowhile con la variable global
    // Llamamos a la funcion stringAGrupo(char *grupo)
    do
    {
        printf("Introduzca grupo grupo taxonomico:\n-> ");
        temp = leeLineaDinamica();
        nueva_especie.grupo_taxonomico = stringAGrupo(temp);
        if(nueva_especie.grupo_taxonomico == DESCONOCIDO)
        {
            printf(YELLOW"ALERTA! Grupo taxonomico no existe\n"RESET);
            printf(YELLOW"Escribe “MAMIFERO, AVE o REPTIL” con mayusculas\n"RESET);
        }
    } 
    while (nueva_especie.grupo_taxonomico == DESCONOCIDO);

    // Igualmente, cuando se pida la cantidad, el usuario debe introducir un valor numérico válido. 
    // En caso contrario, se debe volver a pedir hasta que introduzca un número válido.
    printf("Introduzca la cantidad:\n-> ");
    nueva_especie.cantidad_ejemplares = pedirEntero();

    return nueva_especie;
};

/**
 * Función que, dada una cadena, compara con todos
 * los grupos taxonómicos válidos, y devuelve el 
 * enumerado correspondiente.
 * Si no es un grupo válido, devuelve el valor 
 * enumerado "DESCONOCIDO”
 */
grupo_e stringAGrupo(char *grupo)
{
    // Declaracion de variables
    grupo_e nuevo_grupo;

    if(strcmp(grupo, grupoStr[0]) == 0)
        nuevo_grupo = MAMIFERO;
    else if(strcmp(grupo, grupoStr[1]) == 0)
        nuevo_grupo = AVE;
    else if(strcmp(grupo, grupoStr[2]) == 0)
        nuevo_grupo = REPTIL;
    else
        nuevo_grupo = DESCONOCIDO;

    return nuevo_grupo;
}

// Funciones auxiliares
/**
 * Funcion pedir entero con recubrimiento de errores
 * No admite letras ni valores negativos
 */
int pedirEntero()
{
    // Declaracion de variables
    int num = 0, esValido = 0;

    // Cuerpo funcion
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if(esValido != 1 || num < 0)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                "-> \033[0m"
            );
            esValido = 0;
        }
    } 
    while (!esValido);
    
    return num;
}

/**
 * Devuelve la cadena de caracteres que el usuario ha //escrito en el teclado por terminal 
 * reservando memoria de manera dinamica 
 */
char *leeLineaDinamica()
{
    // Declaracion de variables
    char *destino = (char *)malloc(sizeof(char) * TAM_BLOQUE);
    int memoria_actual = TAM_BLOQUE;
    int i = 0;
    char c;

    // Cuerpo funcion
    while(((c = getchar()) != '\n'))
    {
        if(i == memoria_actual - 1)
        {
            memoria_actual += TAM_BLOQUE;
            destino = (char *)realloc(destino, sizeof(char) * memoria_actual);
        }
        destino[i] = c;
        i++;
    }
    destino[i] = '\0';

    return destino;
}

void clearBuffer() 
{
    while(getchar() != '\n');
}