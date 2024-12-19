/*	{
 *		"Autor": "Stefan Trifan", 
 *		"Compilar": {
 *			"mac": "gcc main.c -o main;",
 *			"windows": "gcc main.c -o main.exe;"
 *		},
 *		"Introducir despues de scanf": "limpiar()",
 *		"Enunciado": "Realizad un programa que calcule el incremento de un salario de un empleado por un porcentaje especificado. Tanto salario como porcentaje se piden al usuario."
 *	}
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	
	// Declaramos las variables
	float salario       = 0;
	float incremento    = 0;
	float salario_nuevo = 0;

	// Pedimos por pantalla el salario
	printf("Introduce tu salario\n");
	scanf("%f", &salario);

	// Pedimos el porcentaje del incremento
	printf("Introduce el incremento (Solo numero del 0 al 100) \n");
	scanf("%f", &incremento);

	// Calculamos el icnremento
	salario_nuevo = salario + (salario * (incremento/100));
	printf("El salario nuevo que recibirias es %f\n", salario_nuevo);

}