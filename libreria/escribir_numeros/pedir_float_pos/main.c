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
float pedirFloatPos();
void  clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	float num = 0;

	printf("Introduce un numero: \n-> ");

	num = pedirFloatPos();
	
	printf("Numero es: %2f", num);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float pedirFloatPos()
{
	float num = 0;
	int esValido = 0;
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if (esValido == 0 || num < 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. \n"
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
