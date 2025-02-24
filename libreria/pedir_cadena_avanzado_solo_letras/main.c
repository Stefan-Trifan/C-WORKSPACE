/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM 5

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char *text, int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char text[TAM];
    
    printf("Introduce un texto (max %d caracteres)\n-> ", TAM - 1);
	pedirCadena(text, TAM);
	printf("Tu text es: %s", text);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares

//      tam : 5
//  tam - 1 : 4

//  Entrada : rojo\n
//        c : cojo\0
//  text[i] : cojo\0
//        i : 4

void pedirCadena(char *text, int tam) {
    int i, esValido;
    char c;

    do {
        i = 0;
        esValido = 1;  // Suponemos que la entrada es válida
        
        while (i < tam - 1) {
            c = getchar();

            if (c == '\n')   // Si presiona ENTER antes de llenar el buffer, salir
                break;

            if (c < '0' || c > '9') {  // Si se ingresa un número, reiniciar entrada
                printf("\033[1;33mSolo puedes introducir numeros\n"
                       "Inténtalo de nuevo\n"
                       "-> \033[0m");
                clearBuffer();  // ✅ Llamamos `clearBuffer()` aquí
                esValido = 0;  // Marcar entrada como inválida
                break;  // Salir del while y repetir la entrada
            }

            text[i] = c;  // Guardar el carácter válido en la cadena
            i++; 
        }

        text[i] = '\0';  // Terminar la cadena correctamente

        // Verificar si se ingresaron demasiados caracteres
        if (i == tam - 1) {
            c = getchar();
            if (c != '\n') {
                printf("\033[1;33mHas introducido demasiados caracteres\n"
                       "Inténtalo de nuevo\n"
                       "-> \033[0m");
                clearBuffer();  // ✅ Llamamos `clearBuffer()` aquí también
                esValido = 0;  // Marcar como inválido
            }
        }

    } while (!esValido);
}

void clearBuffer()
{
	while (getchar() != '\n');
}