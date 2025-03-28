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
	printf("\n_________________________________________START\n\n");
    
    int numMax = 0, base = 0;

	printf("De que numero quieres sacar multiplos (base): ");
	scanf("%d", &base);

	printf("Hasta que numero quieres sacar multiplos: ");
	scanf("%d", &numMax);

	for(int i = 0; i <= numMax; i++)
	{
		if(i % base == 0)
		{
			printf("%d\n", i);
		}
	}
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}