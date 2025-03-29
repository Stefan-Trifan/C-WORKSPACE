/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM 5

// Funciones del programa

// Funciones auxiliares
void escribeLineaTam(char *text, int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	char text[TAM];
    
    printf("Introduce un texo (max %d caracteres)\n-> ", TAM - 1);
	escribeLineaTam(text, TAM);
	printf("Tu text es: %s", text);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares

//      tam : 5
//  Entrada : rojo
//        c :
//  text[i] : 
//        i :
// printf("DEBUG: i = %d, c = %c (%d)\n", i, c, c);
// printf("DEBUG SALIDA WHILE: i = %d, c = %c (%d)\n", i, c, c);

void escribeLineaTam(char *text, int tam)
{
    int i, esValido;
    char c;
    do
    {
        i = 0;
        esValido = 1;
        while (i < tam - 1)
        {
            c = getchar();
            if(c == '\n') break;
            text[i] = c;
            i++; 
        }
        text[i] = '\0'; 
        
        if(i == tam - 1)
        {
            c = getchar();
            if(c != '\n')
            {
                printf(
                    "\033[1;33mHas introducido demasiados caracteres\n"
                    "Intentalo de nuevo\n"
                    "-> \033[0m");
                clearBuffer();
                esValido = 0;
            }
        }
    } 
    while (esValido != 1);
}

void clearBuffer()
{
	while (getchar() != '\n');
}