/*
    *   Autor
        Stefan Trifan
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>
#define TAM 5
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char nombre[TAM] = {0};

	printf("Tu nombre (max %d caracteres): ", TAM - 1);
	fgets(nombre, sizeof(nombre), stdin);
	nombre[strcspn(nombre, "\n")] = '\0'; // Elimina el salto de linea por defecto

	printf("Tu nombre es: %s", nombre);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}