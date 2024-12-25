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

	* 	Enunciado X
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	int horas = 0, minutos = 0, segundos = 0, segundos_totales = 0;
    
    printf("Intrudce horas, minutos y segundos en formato: HH:MM:SS: ");
	scanf("%i:%i:%i", &horas, &minutos, &segundos);

	segundos_totales = horas*3600 + minutos*60 + segundos;

	printf("Los segundos totales son: %i", segundos_totales);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer(){
	while (getchar() != '\n');
}