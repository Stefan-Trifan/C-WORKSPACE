/*	{
 *		"Autor": "Stefan Trifan", 
 *		"Compilar": {
 *			"mac": "gcc main.c -o main;",
 *			"windows": "gcc main.c -o main.exe;"
 *		},
 *		"Introducir después de scanf": "limpiar()",
 *		"Enunciado": "Calcular el área de un triágulo" // (Base*altura)/2
 *	}
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){
	// Declaramos las variables
	float base;
	float altura;
	float area;

	// Pedimos laa base y la altura
	printf("Intruduce la base del triangulo\n");
	scanf("%f", &base);
	limpiar();

	printf("Intruduce la altura del triangulo\n");
	scanf("%f", &altura);
	limpiar();

	// Caluclamos y mostramos ela rea x pantalla
	area = (base*altura)/2;
	printf("El área del triangulo es %f", area);
}