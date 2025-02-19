/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado X
        Escribe un programa en lenguaje C al que se le pase por argumentos del main dos cadenas (tamaño máximo 20 caracteres) y que compruebe que son iguales.
        El programa mostrará imprimirá por pantalla si son iguales o no después de comprobarlo
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[]) {
    printf("\n_________________________________________START\n\n");



    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
int cadenasIguales(char* cadena1, char* cadena2)
{

}

int tamCadena(char* cadena)
{

}

// Funciones auxiliares
void clearBuffer() {
    while (getchar() != '\n');
}
