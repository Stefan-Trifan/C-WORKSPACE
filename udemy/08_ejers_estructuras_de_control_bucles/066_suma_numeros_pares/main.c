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
		0 + 2 + 4 + 6 + 8 + 10 ...
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

	int numMax = 0, resultado = 0, multiplicador = 0;
    
    printf("Cuantos num quieres sumar: ");
	scanf("%d", &numMax);

	for(int i = 1; i <= numMax; i++)
	{
		resultado += multiplicador;
		printf("Calculando:      +%d\n", multiplicador);
		multiplicador += 2;
	}

	printf("Resultado es:     %d", resultado);
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}