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
    
    float nota_parcial_1 = 0, nota_parcial_2 = 0, nota_parcial_3 = 0, nota_examen_final = 0, nota_trabajo_final = 0, nota_final = 0;

	printf("Introduce primer parcial:  ");
	scanf("%f", &nota_parcial_1);
	printf("Introduce segundo parcial: ");
	scanf("%f", &nota_parcial_2);
	printf("Introduce tercer parcial:  ");
	scanf("%f", &nota_parcial_3);
	printf("Introduce examen final:    ");
	scanf("%f", &nota_examen_final);
	printf("Introduce trabajo final:   ");
	scanf("%f", &nota_trabajo_final);

	nota_final = nota_parcial_1*0.18333333 + nota_parcial_2*0.18333333 + nota_parcial_3*0.18333333 + nota_examen_final*0.30 + nota_trabajo_final*0.15;
	printf("Tu nota final es: %.2f", nota_final);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}