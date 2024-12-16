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
		Hacer una funcion que reciba 2 cadenas y las compare
		Primero comparar si las 2 casenas son iguales
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int leerCadena(char cadena[], int maxTam);
// int leerCadena(char *cadena, int maxTam);

// Devolverá 0 si las cadenas no son iguales y 1 si las cadenas son iguales
int comparaCadena(char cadena1[], char *cadena2);

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
    
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */
int leerCadena(char cadena[], int maxTam){
	return 0;
}

int comparaCadena(char cadena1[], char *cadena2){

	return 0;
}
void limpiarBuffer(){
	while (getchar() != '\n');
}