/*
*	Autor
		Stefan Trifan

*	Compilar
		mac    : gcc main.c -o main
		windows: gcc main.c -o main.exe
			   : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado
		* Generar un programa que pida un caracter por pantalla, y que compruebe si es una letra tanto mayuscula como minuscula. 
		* Almacenara el resultado en una variable entera y lo mostrara por pantalla. 
		* No se usaran operadores "if/then", solo se almacena el resultado de la comprobacion.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(int argc, char *argv[]){

	char letra       = ' ';
	int  esMinuscula = 0;
	int  esMayuscula = 0;

	// Pedimos la letra
	printf("Por favor introduce una letra (a-z, A-Z)\n");
	scanf("%c", &letra);

	// Comprobamos si es letra mayuscula o minuscula
	esMinuscula = (letra >= 'a') && (letra <= 'z');
	esMayuscula = (letra >= 'A') && (letra <= 'Z');
	
	// Devolvemos el resultado
	printf(
	"\tLa letra es minuscula: %d\n"
	"\tLa letra es mayuscula: %d\n", esMinuscula, esMayuscula);
}