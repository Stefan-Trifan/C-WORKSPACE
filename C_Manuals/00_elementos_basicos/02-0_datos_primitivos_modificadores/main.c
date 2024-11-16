/*
*	Autor
	Stefan Trifan

*	Compilar
	mac     : gcc main.c -o main
	windows : gcc main.c -o main.exe
			: ./main.exe

*	Introducir des:pues de scanf
	limpiar()

*	Enunciado X
	LoremIpsumDummyText
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

int main(){
	printf("\n________________________________________________\n\n");

	char a = 'A';	   // 1 byte   | Rango desde 0 -> 255 (si es unsigned char)
	short c = 21000;   // 2 bytes  | Rango desde -32768 -> 32767 (cuando es signed short)
	int b = 3200000;   // 4 bytes  | Rango desde -2 147 483 648 a 2 147 483 647
	float d = 3.14159; // 4 bytes  | Precision aproximada de 6-7 digitos

	long e = 980000000;			  // 4 bytes  | Rango desde -2 147 483 648 -> 2 147 483 647
	double f = 2.718281828459045; // 8 bytes  | Precision de 15-16 digitos

	unsigned int g = 123;			   // 4 bytes  | Rango desde 0 -> 4 294 967 295
	long double h = 12.33333232323232; // 16 bytes | Precision de 15-16 digitos

	printf("El valor del char es:   %c        \n", a);
	printf("El valor del int es:    %d        \n", b);
	printf("El valor del short es:  %d        \n", c);
	printf("El valor del float es:  %f        \n\n", d);

	printf("El valor del long es:   %li       \n", e);
	printf("El valor del double es: %lf       \n\n", f);

	printf("El valor del unsigned int es: %u  \n", g);
	printf("El valor del long double es:  %Lf \n", h);

	printf("\n________________________________________________\n\n");
	return 0;
}