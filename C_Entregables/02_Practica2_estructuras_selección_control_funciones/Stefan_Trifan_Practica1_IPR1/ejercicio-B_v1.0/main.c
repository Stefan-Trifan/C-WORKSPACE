/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir después de scanf
		limpiar()

	* 	Enunciado - Incrementa hasta 100
		
		Se pretende realizar un juego en el que el usuario, empezando desde el 1, debe llegar
		exactamente al número 100 siguiendo ciertas normas. Para ello el programa debe guiar al
		usuario y mostrar el progreso en cada paso.

		Normas:
			• En cada turno el usuario puede incrementar su número en 5 ó 3 unidades o puede multiplicarlo por 2.
			• Existe un límite de 8 operaciones para alcanzar el número 100.

		Condiciones de finalización del juego:
			• Si el usuario alcanza exactamente el 100 
			el programa debe mostrar un mensaje de éxito y acabar.
			• Si el usuario supera el 100 o utiliza más de las operaciones permitidas 
			el programa debe mostrar un mensaje de derrota y terminar.
			• Debe mostrarse al usuario una sugerencia cuando su número sea superior a 50 
			para que use la opción sumar y evitar superar el 100.

		void mostrarInstruccionesIniciales(){
			Debe mostrar las instrucciones del juego al principio de la partida
		}
		
		void mostrarMenu(int numero, int operaciones){
			Debe mostrar el menú de elección de operación	
		}

		int realizarOperacion(int numero, int opcion){
			Debe realizar la operación elegida y devolver su resultado)
		}
 */
/* 
	# Ejemplo de ejecución
		Debes alcanzar exactamente el valor 100 desde el valor inicial de 1.
		Puedes sumar 5, sumar 3 o multiplicar por 2 en cada movimiento.
		Tienes un maximo de 20 movimientos. Buena suerte!
		
		Numero actual: 1
		Operacion 1:
		1. Sumar 5
		2. Sumar 3
		3. Multiplicar por 2
		Elige tu movimiento (1, 2, o 3): 1
		
		Numero actual: 6
		Operacion 2:
		1. Sumar 5
		2. Sumar 3
		3. Multiplicar por 2
		Elige tu movimiento (1, 2, o 3): 1
		
		Numero actual: 11
		Operacion 7:
		1. Sumar 5
		2. Sumar 3
		3. Multiplicar por 2
		Elige tu movimiento (1, 2, 3): 1
		Sugerencia: Estas cerca de 100, intenta usar sumas en lugar de multiplicar.
		
		Numero actual: 99
		Operacion 8:
		1. Sumar 5
		2. Sumar 3
		3. Multiplicar por 2
		Elige tu movimiento (1, 2, o 3): 2
		Te has pasado de 100. Has perdido el juego.
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

int main(){
	printf("\n________________________________________________\n\n");

	printf("\n________________________________________________\n\n");
	return 0;
}