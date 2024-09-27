/*	{
 *		"Autor": "Stefan Trifan", 
 *		"Compilar": {
 *			"mac": "gcc main.c -o main;",
 *			"windows": "gcc main.c -o main.exe;"
 *		},
 *		"Ejecutar en windows": "./main.exe",
 *		"Introducir después de scanf": "limpiar()",
 *		"Enunciado": "Numero par o impar"
 *	}

	
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	
	// Declaramos la variable del numero
	int num1 = 0;

	// Pedimos el num por pantalla
	printf("Introduce el número\n");
	scanf("%i", &num1);

	// Comprobamos si es par o impar
	if ( num1 % 2 == 0){
		printf("El número %i es par", num1);
	} else {
		printf("El numero %i es impar", num1);
	}
}