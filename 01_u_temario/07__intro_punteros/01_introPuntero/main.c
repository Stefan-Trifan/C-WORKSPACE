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
    
    int num1 = 0;
	int *pNum1 = &num1;
    
	printf("El numero guardado es:                            %d\n", num1);
	printf("La direccion de memoria de num1 es:               %p\n", &num1);
	printf("La direccion de memoria a la que apunta pNum1 es: %p\n", pNum1);
	printf("La direccion de memoria de pNum1 es:              %p\n", &pNum1);
	printf("El contenido de pNum1 es:                         %d\n", *pNum1);

	// INCREMENTAMOS EL CONTENIDO DE PNUM!
	*pNum1 += 1;
	printf("\n\n");

	printf("Despues de incrementar, num1 es              :          %d\n", num1);
	printf("La direccion de memoria de num1 es:                     %p\n", &num1);
	printf("La direccion de memoria a la que apunta pNum1 es:       %p\n", pNum1);
	printf("La direccion de memoria de pNum1 es:                    %p\n", &pNum1);
	printf("El contenido de pNum1 es:                               %d\n", *pNum1);


	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}