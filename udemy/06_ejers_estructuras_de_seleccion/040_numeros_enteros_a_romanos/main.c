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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
	int numero     = 0;
	int miles      = 0;
	int centenas   = 0;
	int decenas    = 0;
	int unidades   = 0;
	int esNumValido = 0;

	
	do {
		printf("Digita un numero del 0 al 3999: ");
		esNumValido = scanf("%d", &numero); 
		clearBuffer();
	} while (!esNumValido || numero <= 0 || numero > 3999);

	miles  = numero / 1000;
	numero = numero % 1000;

	centenas = numero / 100;
	numero   = numero % 100;

	decenas = numero / 10;
	numero  = numero % 10;

	unidades = numero;

	printf("miles:    %d\n", miles);
	printf("centenas: %d\n", centenas);
	printf("decenas:  %d\n", decenas);
	printf("unidades: %d\n", unidades);

	printf("Numero romano: ");

	switch (miles) {
		case 1 : printf("M") ; break;
		case 2 : printf("MM") ; break;
		case 3 : printf("MMM") ; break;
	}

	switch (centenas) {
		case 1 : printf("C") ; break;
		case 2 : printf("CC") ; break;
		case 3 : printf("CCC") ; break;
		case 4 : printf("CD") ; break;
		case 5 : printf("D") ; break;
		case 6 : printf("DC") ; break;
		case 7 : printf("DCC") ; break;
		case 8 : printf("DCCC") ; break;
		case 9 : printf("CM") ; break;
		default: printf("") ; break;
	}

	switch (decenas) {
		case 1 : printf("X") ; break;
		case 2 : printf("XX") ; break;
		case 3 : printf("XXX") ; break;
		case 4 : printf("XL") ; break;
		case 5 : printf("L") ; break;
		case 6 : printf("LX") ; break;
		case 7 : printf("LXX") ; break;
		case 8 : printf("LXXX") ; break;
		case 9 : printf("XC") ; break;
		default: printf("") ; break;
	}

	switch (unidades) {
		case 1 : printf("I") ; break;
		case 2 : printf("II") ; break;
		case 3 : printf("III") ; break;
		case 4 : printf("IV") ; break;
		case 5 : printf("V") ; break;
		case 6 : printf("VI") ; break;
		case 7 : printf("VII") ; break;
		case 8 : printf("VIII") ; break;
		case 9 : printf("IX") ; break;
		default: printf("") ; break;
	}

	
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}