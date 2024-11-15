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

		Se deberán implementar las siguientes funciones:
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

/* _________________________________________
   Inicio cabecera del programa */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

// Inicializamos las funciones
int obtenerMaximo();
void obtenNumeros(int maximo, int *ope1, int *ope2);
int rondaCorrecta(int maximo);

/* _________________________________________
   Inicio main() */

int main(){

	printf("\n________________________________________________START\n\n");
	
	// Declaración de variables
	int maximo  = 0;
	int vidas   = 3;
	int rondas  = 10;
	int puntos  = 0;

	// Pedimos el numero maximo de los operadokres
	maximo = obtenerMaximo();

	// Inicializamos la semilla de los numeros aleatorios
	srand(getpid());

	// Seguimos ejecutando el programa mientras haya vidas y rondas
	while (rondas > 0 && vidas >0){

		if(rondaCorrecta(maximo) == 0){
			vidas--;
			printf("... Resultado incorrecto, vidas: %i\n", vidas);
		} else{
			puntos++;
		}
		rondas--;
	}

	if(rondas == 0){
		printf("\n¡FELICIDADES! Te las sabes todas.");
	}

	if(vidas == 0){
		printf("\nGame Over. Haber estudiado.\n%i puntos", puntos);
	}
	
	printf("\n________________________________________________END\n\n");
	return 0;

}

/* _________________________________________
   Inicio definición de funciones */

// Pide el número máximo que tendran operandos
int obtenerMaximo(){

	int maximo = 0;
	// Seguimos pidiendo el num maximo hasta que sea mayor o igual a 2
	do{
		printf("introduce el máximo: ");
		scanf("%d", &maximo);
	} while (maximo <= 2);
	return maximo;

}
	
// Obtiene dos numeros aleatorios entre 2 y el maximo incluido
// Los devuelve como parametros por referencia
void obtenNumeros(int maximo, int *ope1, int *ope2){

	*ope1 = (rand() % (maximo - 1)) + 2;
	*ope2 = (rand() % (maximo - 1)) + 2;

}

// Genera una ronda
// Devuelve 0 si el usuario no ha acertado, 1 si todo va bien
int rondaCorrecta(int maximo){

	int ope1 = 0, ope2 = 0, resultadoUsuario = 0;
	obtenNumeros(maximo, &ope1, &ope2);
	printf("%d * %d: ", ope1, ope2);
	scanf("%d", &resultadoUsuario);
	if(resultadoUsuario == ope1 * ope2){
		return 1;
	} else {
		return 0;
	}

}