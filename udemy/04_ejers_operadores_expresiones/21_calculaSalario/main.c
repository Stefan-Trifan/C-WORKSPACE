/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado X
		LoremIpsumDummyText
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
    int horas = 0, salario_hora = 0, salario_total = 0;

	printf("Introduce las horas:       ");
	scanf("%i", &horas);
	printf("Introduce tu salario hora: ");
	scanf("%i", &salario_hora);

	salario_total = horas * salario_hora;

	printf("Tu salario total es: %i", salario_total);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}