/*	{
 *		"Autor": "Stefan Trifan", 
 *		"Compilar": {
 *			"mac": "gcc main.c -o main;",
 *			"windows": "gcc main.c -o main.exe;"
 *		},
 *		"Introducir después de scanf": "limpiar()",
 *		"Enunciado": "Generar un programa que pida 4 números en coma flotante, y almacenarlos en 4 variables distintas. Mostrar el 		*		resultado de calcular las siguientes condiciones:
 *			▪ Si el primero es mayor que el segundo "y" el primero es mayor que el tercero
 *			▪ Si el cuadrado del tercero es menor que el segundo por el cuarto "o" el tercero por 2
 *				menor que el segundo
 *			▪ Si el resto de la división entre el primero y el cuarto es mayor que el tercero "y" el
 *				primero es mayor que el cuarto
 *			▪ Si la división entre el segundo y el cuarto "no es" distinta al primero"
 *	}
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos los float
	float num1 = 0, num2 = 0, num3 = 0, num4 = 0;

	int resultado1 = 0, resultado2 = 0, resultado3 = 0, resultado4 = 0;


	// Pedimos los números de coma flotante
	printf("Introduce el primer número\n");
	scanf("%f", &num1);

	printf("Introduce el segundo número\n");
	scanf("%f", &num2);

	printf("Introduce el tercer número\n");
	scanf("%f", &num3);

	printf("Introduce el cuarto número\n");
	scanf("%f", &num4);

	// Si el primero es mayor que el segundo "y" el primero es mayor que el tercero
	// num1 > num2  &&  num1 > 3
	resultado1 = num1 > num2  &&  num1 > 3;

	// Si el cuadrado del tercero es menor que el segundo por el cuarto "o" el tercero por 2 menor que el segundo
	// num3^2 < num2*num4  ||  num3*2 < num2
	resultado2 = num3^2 < num2*num4 || num3*2 < num2;

	// Si el resto de la división entre el primero y el cuarto es mayor que el tercero "y" el primero es mayor que el cuarto
	// num1%num4 > num3 && num1 > num4
	resultado3 = num1%num4 > num3 && num1 > num4;

	// Si la división entre el segundo y el cuarto "no es" distinta al primero
	// num2/4 != num1
	resultado4 = num2/4 != num1;

}