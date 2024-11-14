/*	{
 *		"Autor": "Stefan Trifan", 
 *		"Compilar": {
 *			"mac": "gcc main.c -o main;",
 *			"windows": "gcc main.c -o main.exe;"
 *		},
 *		"Introducir después de scanf": "limpiar()",
 *		"Enunciado": "Generar un programa que pida dos números enteros por pantalla, y que compruebe si son iguales. Almacenará el resultado en una variable entera y lo mostrará por pantalla. No se usarán operadores "if/then", sólo se almacena el resultado de la comprobación."
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
	printf("Introduce el primer número\n");
	scanf("%i", &num1);

	printf("Introduce el segundo número\n");
	scanf("%i", &num2);

	resultado = num1 == num2;
	printf("%i", resultado);
}