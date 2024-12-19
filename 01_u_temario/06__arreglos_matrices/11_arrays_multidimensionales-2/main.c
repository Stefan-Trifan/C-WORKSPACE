/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: done

	* 	Enunciado 49
		Introducir una única línea que contenga entre 2 y 10 palabras separadas por coma (,), sin espacios, y presentarlas en orden inverso. Las palabras tendrán un máximo de 10 letras. El número de palabras es desconocido, sólo sabemos que serán como mínimo 2 y como máximo 10, el programa debe adaptarse a lo que introduzca el usuario.

		Condiciones
		▪ En caso de introducir palabras de más de 10 letras, el programa mostrará un error y volverá a pedir una línea que contenga las palabras correctas.
		▪ En caso de introducir más de 10 palabras, o menos de 2, el programa mostrará un error y volverá a pedir la línea.
		▪ Repetir hasta que se tengan todas las palabras introducidas correctamente.
		▪ Mostrar las palabras en orden inverso de introducción, separadas por comas.

		Ejemplo
		▪ Usuario introduce la línea : perro,gato,oso
		▪ El programa muestra la línea: oso,gato,perro
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PALABRAS 10
#define MAX_LONGITUD 10

bool validar_palabras(char palabras[][MAX_LONGITUD + 1], int cantidad) {
    // Verificar que cada palabra tiene un máximo de 10 letras
    for (int i = 0; i < cantidad; i++) {
        if (strlen(palabras[i]) > MAX_LONGITUD) {
            return false;
        }
    }
    return true;
}

int main() {
    char linea[256];
    char palabras[MAX_PALABRAS][MAX_LONGITUD + 1];
    int cantidad_palabras = 0;

    while (1) {
        // Pedir al usuario una línea
        printf("Introduce una línea con entre 2 y 10 palabras separadas por comas (sin espacios): ");
        fgets(linea, sizeof(linea), stdin);

        // Eliminar el salto de línea si está presente
        linea[strcspn(linea, "\n")] = 0;

        // Dividir la línea en palabras usando strtok
        char *token = strtok(linea, ",");
        cantidad_palabras = 0;

        while (token != NULL) {
            if (cantidad_palabras >= MAX_PALABRAS) {
                cantidad_palabras++; // Para manejar el error de más de 10 palabras
                break;
            }
            strncpy(palabras[cantidad_palabras], token, MAX_LONGITUD);
            palabras[cantidad_palabras][MAX_LONGITUD] = '\0'; // Asegurar el fin de cadena
            cantidad_palabras++;
            token = strtok(NULL, ",");
        }

        // Validar cantidad de palabras
        if (cantidad_palabras < 2 || cantidad_palabras > MAX_PALABRAS) {
            printf("Error: Debes introducir entre 2 y 10 palabras.\n");
            continue;
        }

        // Validar longitud de palabras
        if (!validar_palabras(palabras, cantidad_palabras)) {
            printf("Error: Todas las palabras deben tener un máximo de 10 letras.\n");
            continue;
        }

        // Si todo está bien, salir del bucle
        break;
    }

    // Mostrar las palabras en orden inverso
    printf("Las palabras en orden inverso son:\n");
    for (int i = cantidad_palabras - 1; i >= 0; i--) {
        printf("%s", palabras[i]);
        if (i > 0) printf(","); // Separar con comas excepto la última palabra
    }
    printf("\n");

    return 0;
}
