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

int pedirEnteroPos();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	int num = 0;

    printf("Introduce un numero entero \n-> ");

	num = pedirEnteroPos();

    printf("Numero es: %d", num);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int pedirEnteroPos()
{
	int num = 0, esValido = 0;
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0 || num < 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
				"-> \033[0m"
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