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

// Invertir una cadena con la funcion strrev().

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char cadena[] = "Steve";
	
	strrev(cadena); //Invertimos la cadena con la funcion strrev
	
	printf("Cadena Invertida: %s",cadena); 
	//mostramos la cadena invertida
    
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}