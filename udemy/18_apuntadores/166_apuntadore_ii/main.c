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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int numero = 40;
	
	int *p_numero = &numero;
	printf("Valor de la variable\n");
	printf("Dato: %d  \n",  numero);   // 50
	printf("Dato: %d\n\n", *p_numero); // 50

	printf("Posicion de la memoria: \n");
	printf("Posicion: %p\n", &numero);   // 0x16dd0b338
	printf("Posicion: %p\n",  p_numero); // 0x16dd0b338
	printf("Posicion: %p\n", &p_numero); // 0x16dd0b330 (Diferente)
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}