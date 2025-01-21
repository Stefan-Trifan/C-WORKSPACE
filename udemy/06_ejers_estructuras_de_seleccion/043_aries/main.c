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
#include <string.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");

	char nombre[20] = "";
	char signo[20] = "";
    
    printf("Introduce tu nombre: ");
	fgets(nombre, 20, stdin);
	strtok(nombre, "\n");
	printf("Tu nombre es: %s\n", nombre);

	printf("Introduce tu signo: ");
	fgets(signo, 20, stdin);
	strtok(signo, "\n");
	printf("Tu signo es: %s\n", signo);

	if(strcmp("Aries", signo) == 0 || strcmp("aries", signo) == 0 || strcmp("ARIES", signo) == 0){
		printf("\nTu signo es Aries");
	} else {
		printf("\nTu signo no es Aries");
	};
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}