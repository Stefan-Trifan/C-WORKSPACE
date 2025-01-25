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

float pedirFloat();
void  clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	float num = 0;

	printf("Introduce un numero: \n");
	num = pedirFloat();

	printf("Numero es: %f", num);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float pedirFloat()
{
	float num = 0;
	int esValido = 1;
	printf("-> ");
	do
	{	
		esValido = scanf("%f", &num);
		clearBuffer();
		if(esValido == 0) // Aqui se pueden añadir mas condiciones
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. Por favor, inténtelo de nuevo. \n\033[0m"
				"\033[1;31m-> \033[0m"
			);
			esValido == 0; // Util cuando hay mas de una condicion
		}
	} 
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}