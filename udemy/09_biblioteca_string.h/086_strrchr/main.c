/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado
		LoremIpsum
*/

// strrchr(Cadena, Caracter)
// Regresa el restante de la cadena a partir de la primera aparicion del caracter indicado.

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	char abecedario[] = "abcdefghijklmnopqrstuvwxyz";
	char letraCorte   = ' ';

	printf("Introduce la letra en la que quieres que se corte el abecedario: ");
	scanf("%c", &letraCorte);
	clearBuffer();
    
	printf("%s", strrchr(abecedario, letraCorte));
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}