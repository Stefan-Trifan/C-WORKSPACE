/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado

		* Ejercicio B - Calificaciones alumnos

		- Realiza un programa que determine si un estudiante aprueba o suspende una asignatura 
		en función de sus calificaciones en tres pruebas, su examen y su asistencia a clase. 
		- Si se suspende algún apartado, se debe informar al usuario mediante la consola.

		* El programa debe solicitar:
		- Nota de primera prueba (0-10)
		- Nota de segunda prueba (0-10)
		- Nota de tercera prueba (0-10)
		- Nota examen final (0-10)
		- Asistencia a clase (0%-100%)

		* Cálculo de la nota final:
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

		* Ejemplos de ejecución:

		$ ./notas.exe
		Nota de la primera prueba: 4.5
		Nota de la segunda prueba: 4.7
		Nota de la tercera prueba: 5.0
		Nota del examen final: 5.0
		Nota de asistencia: 0.9
		El alumno ha suspendido.
		Las pruebas no han superado la nota mínima.

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

}