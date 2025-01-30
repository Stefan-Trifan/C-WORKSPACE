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

int main(){

	// Declaramos las variables
	int horas    = 0;
	int minutos  = 0;
	int segundos = 0;

	// Pedimos por pantalla
	printf("Introduce las horas: ");
	scanf("%d:%d:%d", &horas, &minutos, &segundos);

	printf("%d:%d:%d", horas, minutos, segundos);

	return 0;
}