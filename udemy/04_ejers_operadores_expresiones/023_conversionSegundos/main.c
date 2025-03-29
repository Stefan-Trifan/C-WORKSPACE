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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	int horas = 0, minutos = 0, segundos = 0, segundos_totales = 0;
    
    printf("Intrudce horas, minutos y segundos en formato: HH:MM:SS: ");
	scanf("%d:%d:%d", &horas, &minutos, &segundos);

	segundos_totales = horas*3600 + minutos*60 + segundos;

	printf("Los segundos totales son: %d", segundos_totales);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}