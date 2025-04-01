/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    FILE *fd;
    fd = fopen("descubrimiento_ameirica.txt", "w+");

    char s1[10], s2[10], s3[10], s4[10];
    int anio_descubrimiento = 0;

    // Comprobamos si tiene extio
	if(fd == NULL)
	{
		printf("Error al abrir el archivo\n");
		return EXIT_FAILURE;
	}

    // Escribimos en el fichero
    fprintf(fd,"%s %s %s %s %d", "America", "se", "descubrio", "en", 1492);

    rewind(fd);

    fscanf(fd,"%s %s %s %s %d", s1, s2, s3, s4, &anio_descubrimiento);

    fclose(fd);

    // Calculamos hace cuantos anios se descubrio America
    printf("America se descubrio hace %d anos", 2025 - anio_descubrimiento);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}