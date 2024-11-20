/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: todo

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

	char nombre[40];
	int salario;
    
    printf("Introduce tu nombre: \n");
	gets(nombre);
	printf("Tu nombre es: %s", nombre);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}



/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}