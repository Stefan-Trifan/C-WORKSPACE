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
#include <string.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	char marca[25] = " ";
    
    printf("Introduce la marca del coche: ");
	fgets(marca, 25, stdin);
	strtok(marca, "\n");
	printf("marca es: %s\n", marca); // debug

	if(strcmp(marca, "honda") == 0 || strcmp(marca, "Honda") == 0 || strcmp(marca, "HONDA") == 0){
		printf("Tu descuento es: 5%%");
	} 
	else if (strcmp(marca, "yamaha") == 0 || strcmp(marca, "Yamaha") == 0 || strcmp(marca, "YAMAHA") == 0){
		printf("Tu descuento es: 8%%");
	} 
	else if (strcmp(marca, "suzuki") == 0 || strcmp(marca, "Suzuki") == 0 || strcmp(marca, "SUZUKI") == 0){
		printf("Tu descuento es: 10%%");
	} 
	else{
		printf("Tu descuento es: 2%%");
	}

	
	
	
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}