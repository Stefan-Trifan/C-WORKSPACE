/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir despues de scanf
		limpiar()

	* 	Enunciado X
		
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	int opcion = 0;

	// Comprobamos si el usuario ha introducido una opcion valida
	// Seguimos ejecutando hasta que el usuario introduzca una opcion valida
	do{

		printf("Introduce una opcion: \n"
		"1. Verificar si un numero es par o impar\n"
		"2. Calcular la suma de los numeros desde 0 hasta un valor dado.\n"
		"3. Realizar una cuenta regresiva.\n"
		"4. Salir\n");

		printf("Opcion: ");
		scanf("%i", &opcion);

		if(opcion >= 1 && opcion <= 4){
			printf("Has introducido una opcion valida\n");
		}

	}while(opcion < 1 && opcion > 4);

	return 0;

}