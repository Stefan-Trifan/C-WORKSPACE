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

	int nota = 0;
	int esEntero = 0;

	// Seguimos pidiendo la nota al user hasta que introduzca un numero valido
	do {	

		printf("Introduce tu nota: ");
		esEntero = scanf("%d", &nota);

		if(!esEntero) {
			printf("Entrada no valida. Por favor, introduce un numero.\n");
			clearBuffer();
		}


	} while (!esEntero || nota < 0 || nota > 10);
	
	// Imprimmos el mensaje segun su nota
	switch (nota) {
		
		case 1 : printf("Puedes mejorar"); break;
		case 2 : printf("Puedes mejorar"); break;
		case 3 : printf("Puedes mejorar"); break;
		case 4 : printf("Puedes mejorar"); break;
		case 5 : printf("Puedes mejorar"); break;
		case 6 : printf("Puedes mejorar"); break;
		case 7 : printf("Eres estudiante regular"); break;
		case 8 : printf("Muy bien, puedes mejorar"); break;
		case 9 : printf("Excelente sigue asi"); break;
		case 10: printf("Excelente sigue asi"); break;
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