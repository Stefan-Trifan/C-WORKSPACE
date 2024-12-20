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

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
    int num1 = 0;
	int *pNum1 = NULL;

	num1 = 0;
	pNum1 = &num1;
    
	printf("El numero guardado es:                            %d\n", num1);
	printf("La direccion de memoria de var1 es:               %X\n", &num1);
	printf("La direccion de memoria a la que apunta pNum1 es: %X\n", pNum1);
	printf("La direccion de memoria de pNum1 es:              %X\n", &pNum1);
	printf("El contenido de pNum1 es:                         %d\n", *pNum1);

	// INCREMENTAMOS EL CONTENIDO DE PNUM!
	*pNum1 += 1;

	printf("\n\nDespues de incrementar, el numero guardado es:      %d\n", num1);
	printf("La direccion de memoria de var1 es:                     %X\n", &num1);
	printf("La direccion de memoria a la que apunta pNum1 es:       %X\n", pNum1);
	printf("La direccion de memoria de pNum1 es:                    %X\n", &pNum1);
	printf("El contenido de pNum1 es:                               %d\n", *pNum1);



	printf("");

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}