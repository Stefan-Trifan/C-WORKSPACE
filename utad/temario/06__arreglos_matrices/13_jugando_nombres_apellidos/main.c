/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: doing

	* 	Enunciado X
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	char first_name[25];
	char newChar;
	char cadena[25];
	int pos = 0;
    
	// Pedimos el nombre
	printf("Introduce tu nombre: ");
	while((newChar = getchar()) != '\n'){
		cadena[pos] = newChar;
		pos++;
	}
	cadena[pos] = '\0';

	// Pedimos el apellido
	char last_name[25];
	printf("Introduce tu apellido: ");
	while((newChar = getchar()) != '\n'){
		cadena[pos] = newChar;
		pos++;
	}
	cadena[pos] = '\0';

	// Hacemos la concatenacion
	char full_name[50];
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}