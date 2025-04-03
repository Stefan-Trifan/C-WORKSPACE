/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: done

	* 	Enunciado 49
		Introducir una unica linea que contenga entre 2 y 10 palabras separadas por coma (,), sin espacios, y presentarlas en orden inverso. Las palabras tendran un maximo de 10 letras. El numero de palabras es desconocido, solo sabemos que seran como minimo 2 y como maximo 10, el programa debe adaptarse a lo que introduzca el usuario.

		Condiciones
		▪ En caso de introducir palabras de mas de 10 letras, el programa mostrara un error y volvera a pedir una linea que contenga las palabras correctas.
		▪ En caso de introducir mas de 10 palabras, o menos de 2, el programa mostrara un error y volvera a pedir la linea.
		▪ Repetir hasta que se tengan todas las palabras introducidas correctamente.
		▪ Mostrar las palabras en orden inverso de introduccion, separadas por comas.

		Ejemplo
		▪ Usuario introduce la linea : perro,gato,oso
		▪ El programa muestra la linea: oso,gato,perro
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PALABRAS 10
#define MAX_LONGITUD 10

bool validar_palabras(char palabras[][MAX_LONGITUD + 1], int cantidad) {
    // Verificar que cada palabra tiene un maximo de 10 letras
    for (int i = 0; i < cantidad; i++) {
        if (strlen(palabras[i]) > MAX_LONGITUD) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    char linea[256];
    char palabras[MAX_PALABRAS][MAX_LONGITUD + 1];
    int cantidad_palabras = 0;

    while (1) {
        // Pedir al usuario una linea
        printf("Introduce una linea con entre 2 y 10 palabras separadas por comas (sin espacios): ");
        fgets(linea, sizeof(linea), stdin);

        // Eliminar el salto de linea si esta presente
        linea[strcspn(linea, "\n")] = 0;

        // Dividir la linea en palabras usando strtok
        char *token = strtok(linea, ",");
        cantidad_palabras = 0;

        while (token != NULL) {
            if (cantidad_palabras >= MAX_PALABRAS) {
                cantidad_palabras++; // Para manejar el error de mas de 10 palabras
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
            printf("Error: Todas las palabras deben tener un maximo de 10 letras.\n");
            continue;
        }

        // Si todo esta bien, salir del bucle
        break;
    }

    // Mostrar las palabras en orden inverso
    printf("Las palabras en orden inverso son:\n");
    for (int i = cantidad_palabras - 1; i >= 0; i--) {
        printf("%s", palabras[i]);
        if (i > 0) printf(","); // Separar con comas excepto la ultima palabra
    }
    printf("\n");

    return 0;
}
