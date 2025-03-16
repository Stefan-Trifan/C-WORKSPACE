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

// strlen(Cadena)
// Devuelve un entero que representa la longitud de una cadena de texto (incluyendo espacios en blanco, 
// pero excluyendo el caracter nulo). 

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
    
    char array[200];
	int longitudCadena = 0;

	printf("Escribe cualquier cosa: ");
	scanf("%s", array);

	longitudCadena = strlen(array);
	printf("La longitud de tu cadena es de %d\n", longitudCadena);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}
