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
		Calcular el factorial de un número 
		▪ Pide al usuario que introduzca número entero positivo por teclado.
		▪ Utiliza un bucle de tipo do-while para asegurar que el número no es negativo
		▪ Calcula el factorial del número introducido e imprímelo por pantalla.	
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	int numero = 0;
	unsigned long long int resultado = 1;
	
	do {
		// Pedimos el número
		printf("Introduce un número positivo: ");
		scanf("%i", &numero);
	} while (numero < 0);

	for(int i = 1; i <= numero; i++){
		resultado = resultado*i;
	}

	printf("El factorial de %i es: %llu\n", numero, resultado);

}