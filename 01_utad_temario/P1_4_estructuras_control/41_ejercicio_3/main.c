/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado
		Escribir un programa que calcule y visualice el mas grande, el mas pequeño y la media de n numeros (n >0). 
		El valor de n se solicitara al principio del programa y los numeros seran introducidos por el usuario.
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(int argc, char *argv[]){

	// Declaramos las variables
	int n = 0;

	int numero = 0;

	int num_grande = 0;
	int num_chiqui;
	int suma       = 0;
	int media      = 0;

	// Pedimos por pantalla el numero de numeros
	printf("Dime cuantos numeros vas a introducir: ");
	scanf("%d", &n);

	if (n > 0){
		for(int i = 1; i <= n; i++){

			// Pedimos numero por cada iteracion
			printf("Introduce numero: ");
			scanf("%d", &numero);
			printf("Numero es %d\n", numero);

			// Buscamos el mas pequeño
			if(num_chiqui < numero){
				num_chiqui = numero;
			}

			// Buscamos el numero mas pequeño
			if(i == 1 || num_chiqui > numero){
				num_chiqui = numero;
			}

			// Aumentamos la suma por cada iteracion
			suma = suma + numero;

			// Buscamos el numero mas grande
			if (numero > num_grande){
				num_grande = numero;
			}

		}

	} else {
		printf("El numero de numeros debe ser mayor a 0");
	}

	// 	Calculamos la media
	media = suma / n;

	printf("La media es:                     %d\n", media);
	printf("El numero mas pequeño es:        %d\n", num_chiqui);
	printf("El numero mas grande es:         %d\n", num_grande);
	printf("La suma de todos los numeros es: %d\n", suma);

}