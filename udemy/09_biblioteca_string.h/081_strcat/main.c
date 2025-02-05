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

//* strcat(Destino, Fuente)
//* Concatena (agrega) la cadena fuente en el destino. Debes considerar que la cadena destino
//* debe tener un tamaño tal que pueda albergar la cadena resultante.

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <string.h> // Recuerda incluir la nueva biblioteca

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char cadena1[] = "Stefan",
	     cadena2[] = "Trifan";
	char final[50];

	
	// Concatenamos
    strcat(final,cadena1);
    strcat(final,"-");
    strcat(final,cadena2);
    printf("%s",final); // Imprime Stefan-Trifan

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}



