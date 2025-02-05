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

	* 	Enunciado X
		LoremIpsum
*/

// strrchr(Cadena, Caracter)
// Regresa el restante de la cadena a partir de la primera aparición del carácter indicado.

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	char abecedario[] = "abcdefghijklmnopqrstuvwxyz";
	char letraCorte   = ' ';

	printf("Introduce la letra en la que quieres que se corte el abecedario: ");
	scanf("%c", &letraCorte);
	clearBuffer();
    
	printf("%s", strrchr(abecedario, letraCorte));
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}