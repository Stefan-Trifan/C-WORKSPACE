/*
*	Autor
		Stefan Trifan

*	Compilar
		mac    : gcc main.c -o main
		windows: gcc main.c -o main.exe
			   : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado
		* Generar un programa que pida un carácter por pantalla, y que compruebe si es una letra tanto mayúscula como minúscula. 
		* Almacenará el resultado en una variable entera y lo mostrará por pantalla. 
		* No se usarán operadores "if/then", sólo se almacena el resultado de la comprobación.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

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
	"\tLa letra es minúscula: %i\n"
	"\tLa letra es mayúscula: %i\n", esMinuscula, esMayuscula);
}