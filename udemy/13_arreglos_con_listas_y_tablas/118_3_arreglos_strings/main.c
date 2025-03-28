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

/* 
	Array Unidimensional
	Es una secuencia de datos 

	Array o Arreglos Unidimensionales

	Arrays Enteros
	Arrays Flotantes
	Arrays de Caracter
	Arrays de String (Conjunto de Caracteres)

	Empiezan en el cero NUNCA EN UNO  
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define MAX_TAM 4


int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char a[20] = "Jorge Profe";
	printf("%s\n", a);

	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}