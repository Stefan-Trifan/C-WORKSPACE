/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definiciones */
typedef enum
{
    GUARDADO,
    SIN_GUARDAR
} 
estado_t;

typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
    estado_t estado;
} 
alumno_t;

/* Funciones del programa */
alumno_t *cargarAlumnos(FILE *fd, int *num_alumnos);
void listarAlumnos(alumno_t *lista, int num_alumnos);
void aniadirAlumno(alumno_t **lista, int *num_alumnos);
void guardarAlumnos(FILE *fd, alumno_t *lista, int num_alumnos);
void buscarAlumno(alumno_t *lista, int num_alumnos);

// Funciones auxiliares
char *pedirCadenaDinamica();
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    FILE *fd;
    alumno_t *alumnos;
    int num_alumnos = 0;
    int opcion = 0;

    // abrir el fichero
    fd = fopen("alumnos.txt", "a+");

    // Cargo los alumnos que ya estaban
    rewind(fd);
    alumnos = cargarAlumnos(fd, &num_alumnos);

    // Menú principal
    do
    {
        printf("1. Listar alumnos\n");
        printf("2. Añadir alumno\n");
        printf("3. Guardar alumnos\n");
        printf("4. Buscar alumno\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        opcion = pedirEnteroPos();

        switch (opcion)
        {
        case 1:
            listarAlumnos(alumnos, num_alumnos);
            break;
        case 2:
            aniadirAlumno(&alumnos, &num_alumnos);
            break;
        case 3:
            guardarAlumnos(fd, alumnos, num_alumnos);
            break;
        case 4:
            buscarAlumno(alumnos, num_alumnos);
            break;
        default:
            break;
        }
    } while (opcion != 5);

    // Libero memoria
    for (int i = 0; i < num_alumnos; i++)
    {
        free(alumnos[i].nombre);
        free(alumnos[i].apellido);
    }
    free(alumnos);

    fclose(fd);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// cargar alumnos del fichero
alumno_t *cargarAlumnos(FILE *fd, int *num_alumnos)
{
    alumno_t *lista = NULL;
    char nombre[100], apellido[100];
    int edad;

    lista = malloc(sizeof(alumno_t));

    while (fscanf(fd, "Nombre: %[^,],Apellido: %[^,],Edad: %d\n", nombre, apellido, &edad) == 3)
    {
        lista = realloc(lista, (*num_alumnos + 1) * sizeof(alumno_t));

        lista[*num_alumnos].nombre = malloc(strlen(nombre) + 1);
        lista[*num_alumnos].apellido = malloc(strlen(apellido) + 1);

        strcpy(lista[*num_alumnos].nombre, nombre);
        strcpy(lista[*num_alumnos].apellido, apellido);

        lista[*num_alumnos].edad = edad;
        lista[*num_alumnos].estado = GUARDADO;

        (*num_alumnos)++;
    }

    return lista;
}

// lista todos los alumnos cargados
void listarAlumnos(alumno_t *lista, int num_alumnos)
{
    printf("\nListado de alumnos:\n");

    for (int i = 0; i < num_alumnos; i++)
    {
        printf("Nombre: %s, Apellido: %s, Edad: %d, Estado: %s\n", lista[i].nombre, lista[i].apellido, lista[i].edad, (lista[i].estado == GUARDADO) ? "Guardado" : "Sin guardar");
    }
}

// pide los datos de un nuevo alumno
void aniadirAlumno(alumno_t **lista, int *num_alumnos)
{
    *lista = realloc(*lista, (*num_alumnos + 1) * sizeof(alumno_t));

    printf("Introduce el nombre: ");
    (*lista)[*num_alumnos].nombre = pedirCadenaDinamica();

    printf("Introduce el apellido: ");
    (*lista)[*num_alumnos].apellido = pedirCadenaDinamica();

    printf("Introduce la edad: ");
    (*lista)[*num_alumnos].edad = pedirEnteroPos();

    (*lista)[*num_alumnos].estado = SIN_GUARDAR;

    (*num_alumnos)++;
}

// guarda en fichero los alumnos no guardados
void guardarAlumnos(FILE *fd, alumno_t *lista, int num_alumnos)
{
    for (int i = 0; i < num_alumnos; i++)
    {
        if (lista[i].estado == SIN_GUARDAR)
        {
            fprintf(fd, "Nombre: %s,Apellido: %s,Edad: %d\n", lista[i].nombre, lista[i].apellido, lista[i].edad);
            lista[i].estado = GUARDADO;
        }
    }

    fflush(fd);
    printf("Datos guardados correctamente.\n");
}

// busca un alumno por nombre o apellido
void buscarAlumno(alumno_t *lista, int num_alumnos)
{
    char *busqueda;
    int encontrado = 0;

    printf("Introduce el nombre o apellido a buscar: ");
    busqueda = pedirCadenaDinamica();

    for (int i = 0; i < num_alumnos; i++)
    {
        if (strstr(lista[i].nombre, busqueda) != NULL || strstr(lista[i].apellido, busqueda) != NULL)
        {
            printf("Nombre: %s, Apellido: %s, Edad: %d\n", lista[i].nombre, lista[i].apellido, lista[i].edad);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron alumnos que coincidan.\n");
    }

    free(busqueda);
}

// para leer una cadena dinamica
char *pedirCadenaDinamica()
{
    int tam = 10, i = 0;
    char *cadena;
    char c;

    cadena = malloc(tam * sizeof(char));

    while ((c = getchar()) != '\n')
    {
        cadena[i++] = c;
        if (i == tam)
        {
            tam += 10;
            cadena = realloc(cadena, tam * sizeof(char));
        }
    }

    cadena[i] = '\0';
    return cadena;
}

// pedir un entero positivo
int pedirEnteroPos()
{
    int num;
    scanf("%d", &num);
    clearBuffer();
    return num;
}

// limpia el buffer de entrada
void clearBuffer()
{
    while (getchar() != '\n');
}
