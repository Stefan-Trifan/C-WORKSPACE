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
void pedirCadena(char *text, int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char text[TAM];
    
    printf("Introduce un texo (max %d caracteres)\n-> ", TAM - 1);
	pedirCadena(text, TAM);
	printf("Tu text es: %s", text);
    
	printf("\n_________________________________________EXIT\n\n");
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

void pedirCadena(char *text, int tam)
{
    int i = 0, esValido = 0;
    char c;
    do
    {
        i = 0;
        while (i < tam - 1)
        {
            c = getchar();

            // printf("DEBUG: i = %d, c = %c (%d)\n", i, c, c);
            if(c == '\n')
				break;
                
            text[i] = c;
            i++; 
        }
        text[i] = '\0'; 

        if(i == tam - 1)
        {
            c = getchar();
        }
        // printf("DEBUG SALIDA WHILE: i = %d, c = %c (%d)\n", i, c, c);
        
        if(i == tam - 1 && c != '\n')
        {
            printf(
                "\033[1;33mHas introducido demasiados caracteres\n"
                "Intentalo de nuevo\n"
                "-> \033[0m");
            clearBuffer();
            esValido = 0;
        }
        else
		{
			esValido = 1;
		}
    } 
    while (esValido != 1);
}

void clearBuffer()
{
	while (getchar() != '\n');
}