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

	* 	Enunciado 21
		Vamos a realizar un programa que compare 2 cadebas,
		una ya definida en el codigo con lo que vosotros querais (no mas de 10 caracteres),
		luego vamos a pedirle otra cadena al usuario (leerla como vosotros querais) luego comparar las 2 cadenas y decir si son iguales
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
int cadenas_iguales(char cadena1[], char cadena2[]);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    

	// 1. Definir una cadena fija en el codigo
    char cadena_fija[11] = "HolaMundo"; // Maximo 10 caracteres + '\0'
    
    // 2. Crear una variable para la entrada del usuario
    char cadena_usuario[11];
    
    // 3. Pedir al usuario que introduzca una cadena
    printf("Introduce una cadena de maximo 10 caracteres: ");
    scanf("%10s", cadena_usuario); // Lee como maximo 10 caracteres

    // 4. Comparar las dos cadenas usando nuestra funcion
    if (cadenas_iguales(cadena_fija, cadena_usuario)) {
        // Si la funcion devuelve 1, las cadenas son iguales
        printf("Las cadenas son iguales.\n");
    } else {
        // Si devuelve 0, las cadenas son diferentes
        printf("Las cadenas son diferentes.\n");
    }

    return 0;

	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funcion para comparar dos cadenas
int cadenas_iguales(char cadena1[], char cadena2[]) {
    int i = 0;

    // Comparamos caracter por caracter
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return 0; // Si algun caracter es diferente, las cadenas son distintas
        }
        i++;
    }

    // Si llegamos al final de ambas cadenas al mismo tiempo, son iguales
    return cadena1[i] == '\0' && cadena2[i] == '\0';
}

void clearBuffer()
{
	while (getchar() != '\n');
}