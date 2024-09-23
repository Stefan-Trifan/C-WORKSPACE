/*
	Autor: Stefan Trifan

	Compilar (dentro de la carpeta): gcc main.c -o main

	Enunciado: 
	Porg que solicite 3 caracteres al usuario y verifique que el usuario no haya introducido otro tipo de datos.
	En caso correcto mostrar por pantalla "Se han introducido 3 caracteres", en otro caso "No se han introdicods los datos correctamente"
*/



#include <stdio.h>

int main(){
	// Declaramos char como variables vacíos
	char caracter1 = ' ';
	char caracter2 = ' ';
	char caracter3 = ' ';


	// Pedimos los 3 caracteres
	printf("Introduce el primer caracter:\n");
	scanf("%c", &caracter1);
	while(getchar() != '\n');

	printf("Introduce el segundo caracter:\n");
	scanf("%c", &caracter2);
	while(getchar() != '\n');

	printf("Introduce el tercer caracter:\n");
	scanf("%c", &caracter3);
	while(getchar() != '\n');

	if ((caracter1 >= 33 && caracter1 <= 126) && 
		(caracter2 >= 33 && caracter2 <= 126) && 
		(caracter3 >= 33 && caracter3 <= 126)){
		printf("Se han introducido 3 caracteres");
	} else {
		printf("No se han introducido los datos correctamente");
	}
}
