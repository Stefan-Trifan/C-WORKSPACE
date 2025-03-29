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
float pedirFloat();
void  clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	float num = 0;

	printf("Introduce un numero: \n-> ");

	do
	{
		num = pedirFloat();
		if(num < 0)
		{
			printf(
				"\033[1;31mERROR: El numero tiene que ser mayor o igual a 0. \n"
				"Por favor, intentelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
		}
	} 
	while (num < 0); // Aqui se pueden añadir otras validaciones adicionales
	

	printf("Numero es: %2f", num);
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

float pedirFloat()
{
	float num = 0;
	int esValido = 0;
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. \n"
				"Por favor, intentelo de nuevo. \n\033[0m" 
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
