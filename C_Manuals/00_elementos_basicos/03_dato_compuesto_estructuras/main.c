/*
*	Autor
	Stefan Trifan

*	Compilar
	mac     : gcc main.c -o main
	windows : gcc main.c -o main.exe
			: ./main.exe

*	Introducir despues de scanf
	limpiar()

*	Enunciado X
	LoremIpsumDummyText
*/

#include <stdio.h>
#include <stdbool.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	/*  
		Los datos compuestos estructuras
		- Almacenan en una variable datos de diferentes tipos
		- Por ejemplo, para la vaiable persona podemos almacenar:
			int edad
			bool vivo
			string nombre 

		* Tamaño
			ver abajo
	*/

	// Declaramos una estructura
	struct persona       // 100 bytes + 4 bytes + 2 bytes = 106 bytes
	{
		char nombre[50]; // 50 char * 2 bytes = 100 bytes
		int  edad;       // 4 bytes
		bool vivo;       // 2 bytes 
	};
	

	return 0;
}