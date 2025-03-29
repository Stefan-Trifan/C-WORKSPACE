/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: todo

	* 	Enunciado
		Crear funcion que lea 
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int leerCadena(char cadena[], int maxTam);
// int leerCadena(char *cadena, int maxTam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    char cadena[20];
	int tam = 0;
	printf("Introduce una cadena: ");
	tam = leerCadena(cadena, 20);
	

	printf("");
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int leerCadena(char cadena[], int maxTam){

}

void clearBuffer()
{
	while (getchar() != '\n');
}