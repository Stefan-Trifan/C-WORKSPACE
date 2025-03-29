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

	* 	Enunciado Funcion de lectura de cadena y cuenta de letras abecedario
		Funcion que reciba una cadena de caracteres y devuelva el numero total de caracteres de dicha cadena
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

int contarCaracteres(const char *cadena);

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    char cadena[] = {"Texto de ejemplo"};
	int totalCaracteres = contarCaracteres(cadena);
	printf("El numero total de caracteres es: %d", totalCaracteres);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int contarCaracteres(const char *cadena){

	int contador = 0;
	while(cadena[contador] != '\0'){
		contador++;
	}
	return contador;
	
}

void clearBuffer()
{
	while (getchar() != '\n');
}