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
		El objetivo de este programa es operar con variables de manera indirecta
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
    
    int w = 10, x = 20, y = 30, z = 40, r1,r2,r3;
	int *p1, *p2, p3, *p4;

	p1  = &w;
	*p2 = &x;
	*p3 = y;
	p4  = *p1;
	r1  = p1 + *p2;
	r2  = p3 * p4;
	*r3 = *p2 + *p3;
	printf("Los Resultados son: %d, %d y %d\n", r1, r2, r3);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}






