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
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
float pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    float notas[8] = {0}, notasTotal = 0, promedio = 0;

	printf("Introduce tus ocho notas\n");
	for(int i = 0; i < 8; i++)
	{
		printf("Nota %d: ", i + 1);
		notas[i] = pedirEntero();
		notasTotal += notas[i];
	}

	promedio = notasTotal / 8;

	printf("El promedio es: %.2f\n", promedio);

    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float pedirEntero()
{
	float num = 0, esValido = 1;
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}