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
		Calcular el factorial de un numero 
		▪ Pide al usuario que introduzca numero entero positivo por teclado.
		▪ Utiliza un bucle de tipo do-while para asegurar que el numero no es negativo
		▪ Calcula el factorial del numero introducido e imprimelo por pantalla.	
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
		// Pedimos el numero
		printf("Introduce un numero positivo: ");
		scanf("%i", &numero);
	} while (numero < 0);

	for(int i = 1; i <= numero; i++){
		resultado = resultado*i;
	}

	printf("El factorial de %i es: %llu\n", numero, resultado);

}