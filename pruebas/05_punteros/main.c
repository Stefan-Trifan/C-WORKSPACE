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
		LoremIpsum
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
    
	// Primer puntero
    int var1 = 3;
	int *pvar1 = &var1;
	printf("%d\n", var1);

	// Segundo puntero
	int casa = 0;
	int* direccion;
	direccion = &casa;

	int* direccion2;
	direccion2 = direccion;

	printf("Casa: %d direccion: %d direccion2: %d\n", casa, *direccion, *direccion2);
	casa = 1;
	printf("Casa: %d direccion: %d direccion2: %d\n", casa, *direccion, *direccion2);

	
	int var3, var4;
	int *p;
	
	var3 = 5;
	p = &var3;
	var4 = *p;
	*p =10;
	printf("%d", var3);
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}