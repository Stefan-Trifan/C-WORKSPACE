/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado
		Escribir un programa que calcule y visualice el más grande, el más pequeño y la media de n números (n >0). 
		El valor de n se solicitará al principio del programa y los números serán introducidos por el usuario.
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	int n = 0;

	int numero = 0;

	int num_grande = 0;
	int num_chiqui = 0;
	int suma       = 0;
	int media      = 0;

	// Pedimos por pantalla el número de numeros
	printf("Dime cuántos números vas a introducir: ");
	scanf("%i", &n);

	if (n > 0){
		for(int i = 1; i <= n; i++){

			// Pedimos número por cada iteracion
			printf("Introduce numero: ");
			scanf("%i", &numero);
			printf("Numero es %i\n", numero);

			// Aumentamos la suma por cada iteración
			suma = suma + numero;

			// Buscamos el número más grande
			if (numero > num_grande){
				num_grande = numero;
			}

			// Buscamos el más pequeño
			if(i == 1)

			// Buscamos el más pequeño
			// if (i == 1 || numero < num_chiqui){
			// 	num_chiqui = numero;
			// }

		}

	} else {
		printf("El número de números debe ser mayor a 0");
	}

	media = suma / n;

	printf("La media es:                     %i\n", media);
	printf("El número más pequeño es:        %i\n", num_chiqui);
	printf("El número más grande es:         %i\n", num_grande);
	printf("La suma de todos los números es: %i\n", suma);

}