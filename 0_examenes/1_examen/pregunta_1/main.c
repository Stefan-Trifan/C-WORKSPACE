/*
    * Nombre
        Stefan Trifan

    * Enunciado
            Problema: 
                Desplazamiento de Bits a la Izquierda

            Descripción:
                Escribe un programa en C que solicite al usuario un número entero y un número de posiciones para desplazar los bits de ese número a la izquierda. 
                El programa debe usar la función printBinary proporcionada para imprimir el valor inicial y el resultado en binario.

            Requisitos:
                Solicitar al usuario que ingrese un número entero.
                Solicitar al usuario que ingrese el número de posiciones para desplazar los bits a la izquierda.
                Usar la función printBinary para imprimir el valor inicial y el resultado en binario.

            Función Proporcionada:
            void printBinary(int number) {
                /// Assuming a 32-bit integer
                unsigned int mask = 1 << (32-1); // Start with the leftmost bit
                int i = 0;
                while(i < 32){
                    /// Print '1' or '0' based on the current bit
                    if (number & mask) {
                        printf("1");
                    } else {
                        printf("0");
                    }
                    /// Shift the mask to the right by one bit
                    mask >>= 1;
                    i++;
                }
                printf("\n");
            }

            Ejemplo de Ejecución:
                Ingrese un número: 5
                Ingrese el número de posiciones para desplazar: 3
                Valor inicial en binario: 00000000000000000000000000000101
                Resultado en binario: 00000000000000000000000000101000
*/

#include <stdio.h>

void printBinary(int number) {
    /// Assuming a 32-bit integer
    unsigned int mask = 1 << (32 - 1); // Start with the leftmost bit
    int i = 0;
    while(i < 32){
        /// Print '1' or '0' based on the current bit
        if (number & mask) {
            printf("1");
        } else {
            printf("0");
        }
        /// Shift the mask to the right by one bit
        mask >>= 1;
        i++;
    }
    printf("\n");
}

int main() {

    // Declaramos las variables
    unsigned int miEntero = 0, posicionesDesplazadas = 0, resultado = 0;

    // Pedimos los datos por pantalla
    printf("Ingrese un número: ");
    scanf("%u", &miEntero); 

    // Guardamos dentro de posicionesDesplazadas el número de posiciones que desplazamos los bits a la izquierda
    printf("Ingrese el número de posiciones para desplazar: ");
    scanf("%u", &posicionesDesplazadas);

    // Imprimimos el valor inicial en binario 
    printf("Valor inicial en binario: "); 
    printBinary(miEntero);

    // Desplazamos los bits a la izquierda el número de veces que nos indique el usuario
    resultado = miEntero << posicionesDesplazadas;

    // Imprimomos el número en binario
    printf("Resultado en binario:     "); 
    printBinary(resultado);

}

