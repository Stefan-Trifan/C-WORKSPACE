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

	// Solicitar al usuario que seleccione un dia de la semana
	int dia;

	printf("Selecciona el dia de la semana como numero (del 1 al 7): ");
	scanf("%d", &dia);

	switch (dia){
	case 1: 
		printf("Seleccionaste el Lunes");
		break;
	case 2: 
		printf("Seleccionaste el Martes");
		break;
	case 3: 
		printf("Seleccionaste el Miercoles");
		break;
	case 4: 
		printf("Seleccionaste el Jueves");
		break;
	case 5: 
		printf("Seleccionaste el Viernes");
		break;
	case 6: 
		printf("Seleccionaste el Sabado");
		break;
	case 7: 
		printf("Seleccionaste el Domingo");
		break;
	default: 
		printf("Esta opcion no es valida");
		break;
	}

	switch (dia){
	case 1:
		/* code */
		break;
	
	default:
		break;
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