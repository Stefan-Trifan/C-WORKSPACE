/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIRECCION "usuarios.txt"
#define TAM_BLOQUE 10

typedef struct usuario_t
{
    char *nombre;
    char *ape1;
    char *ape2;
} 
usuario_t;

// Funciones del programa {
void pedirDatosUsuario();
void copiarDatosEstructura();
void imprimirEstructuraCopia();
void crearNombreCompleto();
void guardarDatosEnArchivo();
void cerrarPrograma();
// } Funciones del programa 

// Funciones auxiliares 
char *pedirCadenaDinamica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd = fopen("w", DIRECCION);
    usuario_t usuario_original;

    // todo pedimos los datos con memoria dinamica
    pedirDatosUsuario();
    
    // todo copiamos el usuario en otra estructura
    copiarDatosEstructura();
    
    // todo imprimimos por pantalla los datos de la copia
    imprimirEstructuraCopia();
    
    // todo creamos una cadena con el nombre completo

    crearNombreCompleto();
    
    // todo guardamos los datos en el archivo usuarios.txt

    guardarDatosEnArchivo();
    
    // todo cerramos el archivo y eliberamos memoria
    cerrarPrograma();

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa 
// pedimos los datos con memoria dinamica
void pedirDatosUsuario()
{

}

// copiamos el usuario en otra estructura
void copiarDatosEstructura()
{

}

// imprimimos por pantalla los datos de la copia
void imprimirEstructuraCopia()
{

}

// creamos una cadena con el nombre completo
void crearNombreCompleto()
{

}

// guardamos los datos en el archivo usuarios.txt
void guardarDatosEnArchivo()
{

}

// cerramos el archivo y eliberamos memoria
void cerrarPrograma()
{

}

// Funciones auxiliares 
char *pedirCadenaDinamica()
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
    {
        if (i == memoria_actual - 1)
        {
            memoria_actual += TAM_BLOQUE;
            p_texto_destino = realloc(p_texto_destino, memoria_actual * sizeof(char));
        }
        p_texto_destino[i] = c;
        i++;
    }
    p_texto_destino[i] = '\0';

    return p_texto_destino;
}

void clearBuffer()
{
    while (getchar() != '\n');
}