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
		Convertir grados Celsuiss a Farenhait 
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	float  grados         = 0;
	int tipoConversion   = 0;
	float  celsius        = 0;
	float  fahrenheit     = 0;

	// Pedimos los datos
	printf("Introduce los grados que quieres convertir\n");
	scanf("%f", &grados);
	limpiar();

	printf("Introduce el tipo conversion que deseas realizar:\n" 
	"Introdcue 1 si quieres convertir grados celsius a grados fahrenheit \n"
	"Introduce 2 si quieres convertir grados fahrenheit a grados celsius\n");
	scanf("%d", &tipoConversion);
	limpiar();

	if(tipoConversion == 1){

		celsius = grados;
		fahrenheit = celsius * (9.0 / 5.0) + 32;
		printf("%f grados celsius son %f grados fahrenheit", celsius, fahrenheit);

	} else if (tipoConversion == 2) {

		fahrenheit = grados;
		celsius = (fahrenheit - 32) * 5.0 / 9.0;
		printf("%f grados fahrenheit son %f grados celsius", fahrenheit, celsius);

	} else {

		printf("Dato no valido");

	}

	return 0;
}
