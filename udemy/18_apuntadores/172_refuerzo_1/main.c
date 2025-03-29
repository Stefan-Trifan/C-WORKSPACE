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
	printf("\n___________________________START\n\n");
    
	int w = 10,
	    x = 20,
	    y = 30,
	    z = 40,
		r1,r2,r3;

	int *p1, *p2, *p3, *p4;

	p1 = &w; // Puntero1 es igual a la direccion de memoria de w
	p2 = &x;
	p3 = &y;
	p4 = p1; // Puntero 4 apunta a la misma direccion que Puntero1
	r1 = *p1 + *p2; // El valor de r1 es igual al valor de p1 + el valor de p2
	r2 = *p3 * *p4;
	r3 = *p2 + *p3;
	printf("Los Resultados son: \nr1 %d \nr2 %d \nr3 %d\n", r1, r2, r3);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}






