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
#define YELLOW_BOLD "\033[1;33m"
#define RESET "\033[0m"
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
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */
// tam     :      5
// Entrada : rojo\n
// char c  : rojo\n  
// text[i] : rojo\0
// i       : 4

// Funciones del programa
void pedirCadena(char *text, int tam)
{
	int esValido = 0, i = 0;
	char c;
	do
	{
		i = 0;
		while(i < tam - 1)
		{
			c = getchar();
			// printf("DEBUG: i = %d, c = %c (%d)\n", i, c, c);
			if(c == '\n')
			{
				break;
			}
			text[i] = c;
			i++;
		}
		text[i] = '\0';
		
		c = getchar();
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

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}