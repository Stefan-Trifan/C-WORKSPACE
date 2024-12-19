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

	* 	Enunciado 21
		Vamos a realizar un programa que compare 2 cadebas,
		una ya definida en el codigo con lo que vosotros queráis (no mas de 10 carácteres),
		luego vamos a pedirle otra cadena al usuario (leerla como vosotros queráis) luego comparar las 2 cadenas y decir si son iguales
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
int cadenas_iguales(char cadena1[], char cadena2[]);
void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    

	// 1. Definir una cadena fija en el código
    char cadena_fija[11] = "HolaMundo"; // Máximo 10 caracteres + '\0'
    
    // 2. Crear una variable para la entrada del usuario
    char cadena_usuario[11];
    
    // 3. Pedir al usuario que introduzca una cadena
    printf("Introduce una cadena de máximo 10 caracteres: ");
    scanf("%10s", cadena_usuario); // Lee como máximo 10 caracteres

    // 4. Comparar las dos cadenas usando nuestra función
    if (cadenas_iguales(cadena_fija, cadena_usuario)) {
        // Si la función devuelve 1, las cadenas son iguales
        printf("Las cadenas son iguales.\n");
    } else {
        // Si devuelve 0, las cadenas son diferentes
        printf("Las cadenas son diferentes.\n");
    }

    return 0;

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Función para comparar dos cadenas
int cadenas_iguales(char cadena1[], char cadena2[]) {
    int i = 0;

    // Comparamos carácter por carácter
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return 0; // Si algún carácter es diferente, las cadenas son distintas
        }
        i++;
    }

    // Si llegamos al final de ambas cadenas al mismo tiempo, son iguales
    return cadena1[i] == '\0' && cadena2[i] == '\0';
}

void limpiarBuffer(){
	while (getchar() != '\n');
}