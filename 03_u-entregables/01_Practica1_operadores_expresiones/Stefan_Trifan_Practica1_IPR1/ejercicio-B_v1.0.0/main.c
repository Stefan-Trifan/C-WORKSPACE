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

		* Ejercicio B - Calificaciones alumnos

		- Realiza un programa que determine si un estudiante aprueba o suspende una asignatura 
		en funcion de sus calificaciones en tres pruebas, su examen y su asistencia a clase. 
		- Si se suspende algun apartado, se debe informar al usuario mediante la consola.

		* El programa debe solicitar:

		- Nota de primera prueba (0-10)
		- Nota de segunda prueba (0-10)
		- Nota de tercera prueba (0-10)
		- Nota examen final (0-10)
		- Asistencia a clase (0%-100%)

		* Calculo de la nota final:

		- Pruebas (40% del total):
			- Prueba 1 (20%)
			- Prueba 2 y 3 (40%) cada una
		- Examen final (55%)
		- Asistencia (5%)

		* Criterios para aprobar:
		
		- Nota de examen superior o igual a 4
		- Media de las pruebas superior o igual a 5
		- Nota final superior o igual a 5
		- Asistencia mayor al 80%

		* Ejemplos de ejecucion:

		$ ./notas.exe
		Nota de la primera prueba: 4.5
		Nota de la segunda prueba: 4.7
		Nota de la tercera prueba: 5.0
		Nota del examen final: 5.0
		Nota de asistencia: 0.9
		El alumno ha suspendido.
		Las pruebas no han superado la nota minima.

		$ ./grades.exe
		Nota de la primera prueba: 7.0
		Nota de la segunda prueba: 6.7
		Nota de la tercera prueba: 5.0
		Nota del examen final: 5.0
		Nota de asistencia: 0.9
		El alumno ha aprobado.

*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

	// Declaramos las variables que utilizaremos en el programa
	float prueba1       = 0;
	float prueba2       = 0;
	float prueba3	    = 0;
	float examen        = 0; // 55%
	float pctAsistencia = 0; // Porcentaje asistencia

	float pruebas    = 0; // 40%
	float asistencia = 0; // 5%
	float notaFinal  = 0;

	// Pedimos las notas del usuario por consola
	printf("Nota de la primera prueba (0-10): ");
	scanf("%f", &prueba1);
	
	printf("Nota de la segunda prueba (0-10): ");
	scanf("%f", &prueba2);

	printf("Nota de la tercera prueba (0-10): ");
	scanf("%f", &prueba3);

	printf("Nota del examen final (0-10): ");
	scanf("%f", &examen);

	printf("Porcentaje de asistencia (0-100): ");
	scanf("%f", &pctAsistencia);

	// Calculamos la nota ponderada de las pruebas
	pruebas = 0.2 * prueba1 + 0.4 * prueba2 + 0.4 * prueba3;

	// Calculamos la nota de la asistencia
	asistencia = pctAsistencia / 10;

	// Calculamos la nota final
	notaFinal = 0.4 * pruebas + 0.55 * examen + 0.05 * asistencia;

	// Comprobamos si el alumno ha aprobado
	if ((examen >= 4) && (pruebas >= 5) && (notaFinal >= 5) && (pctAsistencia > 80)){
		printf("El alumno ha aprobado.\n");
	} else {
		printf("El alumno ha suspendido.\n");
		printf("Las pruebas no han superado la nota minima.\n");
	}
		
	printf("La nota final es %f\n", notaFinal);
}