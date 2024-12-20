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

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
    float base_mayor, base_menor, altura, area;

	printf("Introduce la base mayor: ");
	scanf("%f", &base_mayor);
	printf("Introduce la base menor: ");
	scanf("%f", &base_menor);
	printf("Introduce la altura:     ");
	scanf("%f", &altura);

	area = ((base_mayor+base_menor)*altura)/2;
	printf("El area es:              %.2f", area);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}