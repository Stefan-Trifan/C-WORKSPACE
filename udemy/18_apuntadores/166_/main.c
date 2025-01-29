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
	int *p_numero; 

	p_numero = &numero;
	printf("Calor de la variable\n");
	printf("Dato: %i\n",  numero);   // 50
	printf("Dato: %i\n", *p_numero); // 50

	printf("\nPosicion de la memoria: \n");
	printf("Posicion: %p\n", &numero);   // 00xskjfkjhs
	printf("Posicion: %p\n",  p_numero); // 00xskjfkjhs
	printf("Posicion: %p\n", &p_numero); // 0xzciubvfwe
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}