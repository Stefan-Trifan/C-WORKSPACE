// Pablo Martin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaramos las funciones
char *leeLineaDinamicaFichero(FILE *fd);
float ObtenerPrecipitacion(char *cadena);

int main()
{
    // Variables para controlar el fichero
    char *nombreFd = "precipitacionesMadrid2024.txt";
    FILE *fd = fopen(nombreFd, "r");

    // Comprobamos que existe el fichero
    if (fd == NULL)
    {
        printf("[-] Errro al abrir el archivo %s", nombreFd);
        return 1;
    }

    // Variables para el control de las cadenas
    float *lista = (float *)malloc(sizeof(float));
    int tamLista = 0;
    int numRepeticiones = 0;

    // Array que guarda los meses
    char *listaMeses[] = {"Enero","Febrero", "Marzo", "Abril", "Mayo","Junio", "Julio", "Agosto","Septiembre", "Octubre", "Noviembre", "Diciembre"};

    // Guardamos los datos
    while (!feof(fd))
    {
        char *cadena = leeLineaDinamicaFichero(fd); // Guardamos la cadena del fichero

        if (!feof(fd) && numRepeticiones != 0)
        {                                                   // No se mete en la primera linea
            lista[tamLista] = ObtenerPrecipitacion(cadena); // Parseamos la linea para quedarnos con la preciptación

            // Redimensionamos la lista
            tamLista++;
            lista = (float *)realloc(lista, (tamLista + 1) * sizeof(float));
        }
        numRepeticiones++;
    }
    fclose(fd);

    // Variables para guardar las posiciones de las precipitacionesMadrid2024
    float maximo = lista[0];
    int posMax = 0; // Ayuda a saber el mes que pertenece
    float minimo = lista[0];
    int posMin = 0; // Ayuda a saber el mes que pertenece
    float media = 0;

    for (int pos = 0; pos < tamLista; pos++)
    {
        // Minimo
        if (lista[pos] < minimo)
        {
            minimo = lista[pos];
            posMin = pos;
        }

        // Maximo
        if (lista[pos] > maximo)
        {
            maximo = lista[pos];
            posMax = pos;
        }

        // Media
        media += lista[pos];
    }
    media = media / 12; // Dividimos el total entre 12 meses

    // Imprimimos los valores por pantalla
    printf("\n[+] Mes de minimo precipitación: %s (%.2f l/m²)", listaMeses[posMin], minimo);
    printf("\n[+] Mes de maxima precipitación: %s (%.2f l/m²)", listaMeses[posMax], maximo);
    printf("\n[+] Media anual de precipitaciones: %.2f l/m²", media);

    // Guardamos los valores en el fichero al final
    fd = fopen(nombreFd, "a");

    fputs("Mes de máxima precipitación: ", fd);
    fputs(listaMeses[posMax], fd);
    fputs("( ", fd);
    fprintf(fd, "%.2f", maximo);
    fputs(" l/m²)", fd);
    fputc('\n', fd);

    fputs("Mes de mínimo precipitación: ", fd);
    fputs(listaMeses[posMin], fd);
    fputs("( ", fd);
    fprintf(fd, "%.2f", minimo);
    fputs(" l/m²)", fd);
    fputc('\n', fd);

    fputs("Media anual de precipitaciones: ", fd);
    fprintf(fd, "%.2f", maximo);
    fputs(" l/m²", fd);
    fputc('\n', fd);

    fclose(fd);  // Cerramos el fichero
    free(lista); // Liberamos la memoria de la lista de precipitacioens

    return 0;
}

char *leeLineaDinamicaFichero(FILE *fd)
{
    char *cadena = (char *)malloc(sizeof(char));
    char letra;
    int tam = 0;

    while ((letra = fgetc(fd)) != '\n' && letra != EOF)
    {
        cadena[tam] = letra;
        tam++;
        cadena = (char *)realloc(cadena, (tam + 1) * sizeof(char));
    }
    cadena[tam] = '\0';

    return cadena;
}

float ObtenerPrecipitacion(char *cadena)
{
    strtok(cadena, ";");
    char *precipitacionChar = strtok(NULL, ";"); // Guardamos la cadena con la precipitación
    return strtof(precipitacionChar, NULL);      // Pasamos la precipitación de char a float
}