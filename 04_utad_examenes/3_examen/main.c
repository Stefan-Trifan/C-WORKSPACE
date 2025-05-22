#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

// Lee una lÃ­nea dinÃ¡mica usando fgetc
char *leeLineaDinamicaFichero(FILE *fd);

// FunciÃ³n para generar nombre de salida con extensiÃ³n .out
char *generaNombreSalida(char *nombreEntrada);

// Procesa lÃ­nea, muestra etiqueta y contenido, y escribe contenido al fichero
void procesarLinea(char *linea, FILE *f_out);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Uso: %s <nombre_fichero>\n", argv[0]);
        return 1;
    }

    FILE *fd_In = fopen(argv[1], "r");
    if (!fd_In)
    {
        perror("No se pudo abrir el fichero de entrada");
        return 1;
    }

    char *nombreSalida = generaNombreSalida(argv[1]);
    FILE *fd_Out = fopen(nombreSalida, "w");
    if (!fd_Out)
    {
        perror("No se pudo crear el fichero de salida");
        free(nombreSalida);
        fclose(fd_In);
        return 1;
    }

    char *linea;
    while ((linea = leeLineaDinamicaFichero(fd_In)) != NULL)
    {
        procesarLinea(linea, fd_Out);
        free(linea);
    }

    free(nombreSalida);
    fclose(fd_In);
    fclose(fd_Out);

    return 0;
}

char *leeLineaDinamicaFichero(FILE *fd)
{
    int tam = TAM_BLOQUE;
    char *LineaFich = (char *)malloc(sizeof(char) * tam);

    char newchar;
    int i = 0;
    while (((newchar = fgetc(fd)) != '\n') && (newchar != EOF))
    {
        LineaFich[i++] = newchar;
        if (i >= tam + 1)
        {
            tam += TAM_BLOQUE;
            LineaFich = (char *)realloc(LineaFich, sizeof(char) * tam);
        }
    }
    LineaFich[i] = '\0';

    if (i == 0 && newchar == EOF)
    {
        LineaFich = NULL;
    }

    return (LineaFich);
}

char *generaNombreSalida(char *nombreEntrada)
{
    // Busca la Ãºltima apariciÃ³n del punto (.) para detectar la extensiÃ³n.
    const char *extension = strrchr(nombreEntrada, '.');
    int len_base;

    // Comprueba si es .txt.
    if (extension && strcmp(extension, ".txt") == 0)
    {
        len_base = extension - nombreEntrada;
    }
    else
    {
        len_base = strlen(nombreEntrada);
    }

    char *nuevo_nombre = malloc(len_base + 5); // ".out" + '\0' = 5 caracteres
    if (!nuevo_nombre)
        return NULL;

    // Copia la parte del nombre sin la extensiÃ³n y le concatena .out
    strncpy(nuevo_nombre, nombreEntrada, len_base);
    nuevo_nombre[len_base] = '\0';
    strcat(nuevo_nombre, ".out");

    return nuevo_nombre;
}

// Procesa lÃ­nea, muestra etiqueta y contenido, y escribe contenido al fichero
void procesarLinea(char *linea, FILE *f_out)
{
    char *inicioEtiqueta = strchr(linea, '<'); // <b>Hola mundo </b>
    if (!inicioEtiqueta)
        return;

    char *finEtiqueta = strchr(inicioEtiqueta, '>'); //>Hola mundo </b>
    if (!finEtiqueta)
        return;

    int lenEtiqueta = finEtiqueta - inicioEtiqueta - 1; // 1
    char *etiqueta = malloc(lenEtiqueta + 1);
    strncpy(etiqueta, inicioEtiqueta + 1, lenEtiqueta); // b
    etiqueta[lenEtiqueta] = '\0';

    char *valor = finEtiqueta + 1;      // Hola mundo
    char *cierre = strstr(valor, "</"); //</b>
    if (!cierre)
    {
        free(etiqueta);
        return;
    }

    int lenValor = cierre - valor; // 10
    char *contenido = malloc(lenValor + 1);
    strncpy(contenido, valor, lenValor); // Hola mundo
    contenido[lenValor] = '\0';

    printf("Etiqueta: %s\n", etiqueta);
    printf("Contenido: %s\n\n", contenido);
    fprintf(f_out, "%s\n", contenido);

    free(etiqueta);
    free(contenido);
}

// Version 2 de la funcion generaNombreSalida
/*
char* generaNombreSalida( char *nombreEntrada){
        char* nombreSalida=(char*)malloc(sizeof(char)*(strlen(nombreEntrada)+5));//+1 por el '\0' y +4 por ".out"
        nombreSalida=strtok(nombreEntrada,".");//cojo el nombreEntrada hasta el . de la extension
        nombreSalida=strcat(nombreSalida,".out");//aÃ±ado .out al final
        return nombreSalida;
}
*/