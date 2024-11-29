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

	* 	Enunciado 49
		Introducir una única línea que contenga entre 2 y 10 palabras separadas por coma (,), sin espacios, y presentarlas en orden inverso. Las palabras tendrán un máximo de 10 letras. El número de palabras es desconocido, sólo sabemos que serán como mínimo 2 y como máximo 10, el programa debe adaptarse a lo que introduzca el usuario.

		Condiciones
		▪ En caso de introducir palabras de más de 10 letras, el programa mostrará un error y volverá a pedir una línea que contenga las palabras correctas.
		▪ En caso de introducir más de 10 palabras, o menos de 2, el programa mostrará un error y volverá a pedir la línea.
		▪ Repetir hasta que se tengan todas las palabras introducidas correctamente.
		▪ Mostrar las palabras en orden inverso de introducción, separadas por comas.

		Ejemplo:
		▪ Usuario introduce la línea : perro,gato,oso
		▪ El programa muestra la línea: oso,gato,perro
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
    char cadenaUser[50];
	char matrizCadena[5][11];
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}