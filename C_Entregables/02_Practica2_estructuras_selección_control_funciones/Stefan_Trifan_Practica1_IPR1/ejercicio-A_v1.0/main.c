/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir después de scanf
		limpiar()

	* 	Enunciado - Práctica las tablas de multiplicar
		El siguiente ejercicio pretende crear un programa para practicar las tablas de multiplicar. 
		Las instrucciones del juego son las siguientes:
			• El programa solicita al usuario la tabla mayor incluida (mínimo 2)
			• Habrá 10 rondas de preguntas con operandos elegidos al azar entre el 2 y el máximo solicitado anteriormente.
			• El usuario tiene 3 vidas
			• Si no introduce el resultado correcto resta una vida
			• Si introduce el resultado correcto gana un punto
			• El juego termina cuando se acaban las 10 rondas o cuando pierde todas las vidas.
			• Al final de la partida deberá indicar cuantos puntos ha conseguido.

		# Se deberán implementar las siguientes funciones:

		int obtenerMaximo(){
			Pide el maximo numero a multiplicar al usuario,
			repite la operacion hasta que el usuario indique un
			numero valido. El numero debe ser mayor que 1.
		}
		
		void obtenNumeros(int maximo, int *ope1, int *ope2){
			obtiene dos numeros aleatorios entre 2 y el maximo incluido
			y los devuelve como parametros por referencia
		}

		int rondaCorrecta(int maximo){
			genera una ronda, 
			devuelve 0 si el usuario no ha acertado,
			uno si todo va bien
		}
*/
/* 
		# Ejemplo de ejecución

			Introduce el maximo: 12
			4 * 2  = 8
			4 * 7  = 34
			... Resultado incorrecto, vidas: 2
			12 * 8 = 96
			2 * 5  = 10
			9 * 11 = 99
			9 * 8  = 76
			... Resultado incorrecto, vidas:  1
			5 * 6  = 98
			... Resultado incorrecto, vidas:  0
			
				Game Over
				4 puntos
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

// Inicializamos las funciones
int  obtenerMaximo();
void obtenNumeros(int maximo, int *ope1, int *ope2);
int  rondaCorrecta(int maximo);

int main(){
	printf("\n________________________________________________\n\n");
	

	
	printf("\n________________________________________________\n\n");
	return 0;
}

// Definimos las funciones
int obtenerMaximo(){
	return 0;
}

void obtenNumeros(int maximo, int *ope1, int *ope2){

}

int rondaCorrecta(int maximo){
	return 0;
}