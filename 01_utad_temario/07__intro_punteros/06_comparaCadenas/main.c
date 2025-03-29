/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: todo

	* 	Enunciado
		Hacer una funcion que reciba 2 cadenas y las compare
		Primero comparar si las 2 casenas son iguales
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int leerCadena(char cadena[], int maxTam);
// int leerCadena(char *cadena, int maxTam);

// Devolvera 0 si las cadenas no son iguales y 1 si las cadenas son iguales
int comparaCadena(char cadena1[], char *cadena2);

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    char cadena1[100];
	char cadena2[100];

	printf("Introduce la primera cadena: ");
	leerCadena(cadena1, 100);

	printf("Introduce la segunda cadena: ");
	leerCadena(cadena2, 100);

	if(comparaCadena(cadena1, cadena2)){
		printf("Las cadenas son iguales.\n");
	} else {
		printf("Las cadenas son diferentes.\n");
	}
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */
int leerCadena(char cadena[], int maxTam) {
    if (fgets(cadena, maxTam, stdin) != NULL) {
        int i = 0;
        while (cadena[i] != '\0') i++;
        if (i > 0 && cadena[i - 1] == '\n') {
            cadena[i - 1] = '\0'; // Eliminar el salto de linea
        }
        return 1; // exito
    }
    return 0; // Error
}


int comparaCadena(char cadena1[], char *cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return 0; // Diferentes
        }
        i++;
    }
    // Si ambas cadenas terminan al mismo tiempo, son iguales
    return cadena1[i] == '\0' && cadena2[i] == '\0';
}

void clearBuffer()
{
	while (getchar() != '\n');
}