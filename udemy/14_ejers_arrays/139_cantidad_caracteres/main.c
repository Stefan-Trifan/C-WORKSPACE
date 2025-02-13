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
#define TAM 30
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char arr_normal[TAM] = {0}, arr_reves[TAM] = {0};
	int numLetras = 0;

	printf("Introduce el array incial: ");
	for(int i = 0; i < TAM - 1; i++)
	{
		arr_normal[i] = getchar();
		numLetras++;
		if(arr_normal[i] == '\n' )
		{
			numLetras--;
			arr_normal[i] = '\0';
			break;
		}
	}

	for(int i = 0, j = numLetras - 1; i < numLetras; i++, j--)
	{
		arr_reves[i] = arr_normal[j];
	}

	printf("Introduce el array final es: ");
	printf("%s\n", arr_reves);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}