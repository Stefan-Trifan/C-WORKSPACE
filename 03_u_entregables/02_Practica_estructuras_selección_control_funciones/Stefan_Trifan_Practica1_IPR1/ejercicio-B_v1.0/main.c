/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado - Incrementa hasta 100
		Se pretende realizar un juego en el que el usuario, empezando desde el 1, debe llegar exactamente al numero 100 siguiendo normas. 
		Para ello el programa debe guiar al usuario y mostrar el progreso en cada paso.

		Normas:
			• En cada turno el usuario puede incrementar su numero en 5 o 3 unidades o puede multiplicarlo por 2.
			• Existe un limite de 8 operaciones para alcanzar el numero 100.

		Condiciones de finalizacion del juego:
			• Si el usuario alcanza exactamente el 100 el programa debe mostrar un mensaje de exito y acabar.
			• Si el usuario supera el 100 o utiliza mas de las operaciones permitidas  el programa debe mostrar un mensaje de derrota y terminar.
			• Debe mostrarse al usuario una sugerencia cuando su numero sea superior a 50 para que use la opcion sumar y evitar superar el 100.

		Se tienen que implementar las siguientes funciones:
			void mostrarInstruccionesIniciales(){
				Debe mostrar las instrucciones del juego al principio de la partida
			}
			void mostrarMenu(int numero, int operaciones){
				Debe mostrar el menu de eleccion de operacion	
			}
			int realizarOperacion(int numero, int opcion){
				Debe realizar la operacion elegida y devolver su resultado)
			}

	*   Ejemplo de ejecucion
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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void mostrarInstruccionesIniciales();
void mostrarMenu(int numero, int operaciones);
int  realizarOperacion(int numero, int opcion);
void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	// Declaramos las variables
	int operaciones = 1;
	int numero = 1;
	int opcion = 0;
	
    
	mostrarInstruccionesIniciales();

	// Repetimos 8 veces
	for(; operaciones <= 8; operaciones++){

		mostrarMenu(numero, operaciones);

		do{
			printf("Elige tu movimiento (1, 2 o 3): ");
			scanf("%i", &opcion);
		} while(opcion < 1 || opcion > 3);

		numero = realizarOperacion( numero, opcion);

		if(numero > 100){
			printf("Tu numero es: %i\n", numero);
			printf("Te has pasado de 100. Has perdido el juego\n");
			break;
		} else if (numero == 100){
			printf("Tu numero es: %i\n", numero);
			printf("Felicidades! Has ganado el juego\n");
			break;
		}
	}

	if(numero < 100){
		printf("Tu numero es: %i\n", numero);
		printf("No has llegado a 100. Has perdido el juego\n");
	}
    
	printf("\n_________________________________________END  \n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Muestra las instrucciones del juego al principio de la partida
void mostrarInstruccionesIniciales(){

	printf("Debes alcanzar exactamente el valor 100 desde el valor inicial de 1.\n"
	"Puedes sumar 5, sumar 3 o multiplicar por 2 en cada movimiento.\n"
	"Tienes un maximo de 20 movimientos. Buena suerte!\n\n");

}

// Muestra el menu de eleccion de operacion	
void mostrarMenu(int numero, int operaciones){

	printf(
	"Numero actual: %i\n"
	"Operacion %i:\n"
	"1. Sumar 5\n"
	"2. Sumar 3\n"
	"3. Multiplicar por 2\n", numero, operaciones);

}

// Realiza la operacion elegida y devuelve su resultado
int realizarOperacion(int numero, int opcion){
	
	switch (opcion) {
		case 1:
			numero += 5;
			break;
		case 2:
			numero += 3;
			break;
		case 3:
			numero *= 2;
			break;
	}

	return numero;
}

void limpiarBuffer(){
	while (getchar() != '\n');
}