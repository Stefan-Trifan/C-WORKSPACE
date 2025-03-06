/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado
		Comprobad que los valores de hroasm minutos y segundos de un reloj que marca 
		el tiempo en formato HH:MM:SS son correctos siguiendo el siguiente criterio:
		- HH señala las horas desde 0 hasta 24
		- MM los minutos desde 0 hasta 60
		- SS los segundos desde 0 hasta 60
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(int argc, char *argv[]){

	// Declaramos las variables
	char horas       = '0';
	char dosPuntos1  = '0';
	char minutos     = '0';
	char dosPuntos2  = '0';
	char segundos    = '0';

	// Pedimos por pantalla
	printf("Introduce las hora en formato HH:MM:SS -> ");
	horas      = getchar();
	dosPuntos1 = getchar();
	minutos    = getchar();
	dosPuntos2 = getchar();
	segundos   = getchar();

	printf("%c %c %c %c %c\n", horas, dosPuntos1, minutos, dosPuntos2, segundos);

	return 0;
}