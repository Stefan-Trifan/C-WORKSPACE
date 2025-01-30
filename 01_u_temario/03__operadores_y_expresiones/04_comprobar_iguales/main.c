/*	{
 *		"Autor": "Stefan Trifan", 
 *		"Compilar": {
 *			"mac": "gcc main.c -o main;",
 *			"windows": "gcc main.c -o main.exe;"
 *		},
 *		"Introducir despues de scanf": "limpiar()",
 *		"Enunciado": "Generar un programa que pida dos numeros enteros por pantalla, y que compruebe si son iguales. Almacenara el resultado en una variable entera y lo mostrara por pantalla. No se usaran operadores "if/then", solo se almacena el resultado de la comprobacion."
 *	}
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	
	// Declaramos las variuables
	int num1 = 0;
	int num2 = 0;
	int resultado = '0';

	// Pedimos los numeros
	printf("Introduce el primer numero\n");
	scanf("%d", &num1);

	printf("Introduce el segundo numero\n");
	scanf("%d", &num2);

	resultado = num1 == num2;
	printf("%d", resultado);
}