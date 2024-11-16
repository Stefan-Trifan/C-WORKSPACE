/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir despues de scanf
		limpiar()

	* 	Enunciado X
		Este codigo pide al usuario un intervalo de numeros y un paso de incremento, 
		luego calcula y muestra la suma acumulativa de los numeros en ese intervalo, 
		actualizando el resultado con cada incremento.

*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables
	int numMin        = 0;
	int numMax        = 0;
	int numIntervalos = 0;
	int contador      = 0;
	int resultado     = 0;

	// Pedmos los numeros
	printf("Introduce el numero en el que comienza el intervalo:    ");
	scanf("%i", &numMin);

	printf("Introduce el ultimo numero donde finaliza el intervalo: ");
	scanf("%i", &numMax);

	printf("Introduce el numero de intervalos entre cada suma:      ");
	scanf("%i", &numIntervalos);

	// Declaramos las condiciones
	if (numMin > numMax){
		printf("El numero en el que comienza el intervalo tiene que ser menor que el numero donde finaliza el intervalo");
	}

	if (numIntervalos > (numMax - numMin)){
		printf("El el numero de intervalos entre cada suma no es posible\n");
	}

	// Hacemos la suma
	resultado = numMin;
	contador  = numMin;

	while (contador < numMax){

		printf("__________\n");
		
		printf("El contador es: %i\n", contador);
		contador = contador + numIntervalos;
		
		printf("El resultado es: %i\n", resultado);
		resultado = resultado + contador;
	}

	printf("__________\n");
	printf("El resultado FINAL es: %i\n", resultado);

	return 0;
}