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
    
    // Declaramos un array de 5 indices
	int array[5] = {1,2,3,4,5};

	int *apuntadorArray = &array[0];

	// Con esto podemos desplazarnos por el array sin conocer su dimension

	while(*apuntadorArray != NULL)
	{
		printf("Posicion: %d\n", *apuntadorArray);
		apuntadorArray++; // Se va recorriendo el array por las posiciones
	}
    
	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}