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

	int num = 0, cont = 0;
    
    printf("Introduce un num para ver si es primo: ");
	scanf("%d", &num);

	for(int i = 1; i <= num; i++)
	{
		if(num % i == 0)
		{
			cont++;
		};
	};

	(cont == 2) ? printf("El numero es primo") : printf("El numero no es primo");
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}



