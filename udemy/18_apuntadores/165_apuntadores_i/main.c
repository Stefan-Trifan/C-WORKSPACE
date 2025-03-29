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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

float pedirFloat();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	int   cifra = 100;
	int *pcifra = &cifra;

	printf("%d\n",  cifra ); // 100
	printf("%d\n", *pcifra); // 100

	printf("%p\n", &cifra ); // 0x16f15b338 Direccion de memoria de cifra
	printf("%p\n",  pcifra); // 0x16f15b338 Direccion de memoria a la que apunta pcifra
	printf("%p\n", &pcifra); // 0x16f15b330 Direccion de memoria de pcifra

	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */



void clearBuffer()
{
	while (getchar() != '\n');
}