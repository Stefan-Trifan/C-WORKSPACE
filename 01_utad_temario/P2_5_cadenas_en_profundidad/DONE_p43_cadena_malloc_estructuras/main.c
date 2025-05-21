/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIRECCION "users.txt"
#define TAM_BLOQUE 10

typedef struct usuario_t
{
    char *nombre;
    char *ape1;
    char *ape2;
} 
usuario_t;

// Funciones del programa 
void  pedirDatosUsuario(usuario_t *u);
void  copiarDatosEstructura(usuario_t *u_origen, usuario_t *u_destino);
void  imprimirEstructura(usuario_t u);
char* crearNombreCompleto(usuario_t u);
void  guardarDatosEnArchivo(FILE *fd, char *nombre_completo);
void  cerrarPrograma(FILE *fd, usuario_t u1, usuario_t u2, char *nombre_completo);

// Funciones auxiliares 
char *mi_strcpy_dinamico(const char *origen);
void mi_strcat_dinamico(char **destino, const char *origen);
char *pedirCadenaDinamica();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    FILE *fd = fopen(DIRECCION, "w");
    usuario_t usuario_origen;
    usuario_t usuario_destino;
    char *nombre_completo = NULL;

    // Comprobamos que el archivo ha abierto bien
    if(fd == NULL)
    {
        printf("\033[1;31mERROR: No se ha podido abrir el archivo\n \033[0m");
        printf("\033[31m\n_________________________________________FAIL\n\n\033[0m");
        return EXIT_FAILURE;;
    }

    // pedimos los datos con memoria dinamica
    pedirDatosUsuario(&usuario_origen);
    
    // copiamos el usuario en otra estructura
    copiarDatosEstructura(&usuario_origen, &usuario_destino);
    
    // imprimimos por pantalla los datos de la copiar
    imprimirEstructura(usuario_destino);
    
    // creamos una cadena con el nombre completo
    nombre_completo = crearNombreCompleto(usuario_origen);
    
    // guardamos los datos en el archivo users.txt
    guardarDatosEnArchivo(fd, nombre_completo);
    
    // cerramos el archivo y eliberamos memoria
    cerrarPrograma(fd, usuario_origen, usuario_destino, nombre_completo);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa 
// pedimos los datos con memoria dinamica
void pedirDatosUsuario(usuario_t *usuario)
{
    printf("Introduce tu nombre\n-> ");
    usuario->nombre = pedirCadenaDinamica();

    printf("Introduce tu ape1\n-> ");
    usuario->ape1   = pedirCadenaDinamica();

    printf("Introduce tu ape2\n-> ");   
    usuario->ape2   = pedirCadenaDinamica();
}

// copiamos el usuario en otra estructura
void copiarDatosEstructura(usuario_t *u_origen, usuario_t *u_destino)
{
    u_destino->nombre = mi_strcpy_dinamico(u_origen->nombre);
    u_destino->ape1   = mi_strcpy_dinamico(u_origen->ape1);
    u_destino->ape2   = mi_strcpy_dinamico(u_origen->ape2);
}

// imprimimos por pantalla los datos de la copia
void imprimirEstructura(usuario_t u)
{
    printf("\nu.nombre = %s \n", u.nombre);
    printf(  "u.ape1   = %s \n", u.ape1);
    printf(  "u.ape2   = %s \n", u.ape2);  
}

// creamos una cadena con el nombre completo
char *crearNombreCompleto(usuario_t u)
{
    char *cadena_destino = NULL;

    cadena_destino = mi_strcpy_dinamico(u.nombre);
    mi_strcat_dinamico(&cadena_destino, " ");
    mi_strcat_dinamico(&cadena_destino, u.ape1);
    mi_strcat_dinamico(&cadena_destino, " ");
    mi_strcat_dinamico(&cadena_destino, u.ape2);

    return cadena_destino;
}

// guardamos los datos en el archivo users.txt
void guardarDatosEnArchivo(FILE *fd, char *nombre_completo)
{
    fprintf(fd, "%s", nombre_completo);
}

// cerramos el archivo y eliberamos memoria
void cerrarPrograma(FILE *fd, usuario_t u1, usuario_t u2, char *nombre_completo)
{
    fclose(fd);
    free(nombre_completo);
    free(u1.nombre);
    free(u1.ape1);
    free(u1.ape2);
    free(u2.nombre);
    free(u2.ape1);
    free(u2.ape2);
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

char *mi_strcpy_dinamico(const char *origen)
{
    char *destino = NULL;
    int len;

    len = strlen(origen) + 1;
    destino = (char *)malloc(len * sizeof(char));
    if(destino)
    {
        strcpy(destino, origen);
    }
    
    return destino;
}

void mi_strcat_dinamico(char **destino, const char *origen)
{
    *destino = realloc(*destino, sizeof(char) * (strlen(*destino) + strlen(origen) + 1));

    if (*destino)
    {
        strcat(*destino, origen);
    }
}


void clearBuffer()
{
    while (getchar() != '\n');
}

/* DEBUG LOG 

    printf("DEBUG nombre_completo = %s", nombre_completo);






DEBUG LOG */