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

int esPar(int num);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    int num = 0, resultado = 0;

	printf("Introduce un nr: ");
	scanf("%d", &num);

	if(esPar(num))
	{
		printf("Es par");
	}
	else
	{
		printf("No es par");
	}
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int esPar(int num)
{
	if(num % 2 == 0)
		return 1;
	else
		return 0;
}

void clearBuffer()
{
	while (getchar() != '\n');
}