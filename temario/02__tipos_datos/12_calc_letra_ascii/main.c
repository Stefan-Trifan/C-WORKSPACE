/*
	Autor: Stefan Trifan

	Compilar (dentro de la carpeta): gcc main.c -o main

	Enunciado: 
	Pedir por pantalla 2 letras
	Calcular la diferencia entre las 2 letras
*/



#include <stdio.h>

int main(){

	char caracter1 = ' ';
	char caracter2 = ' ';
	int resta = 0;
	
	// Pedimos el primer caracter
	printf("Introduce la primera letra: \n");
	scanf("%c", &caracter1);
	// Importante despues de cadascanf eliminar el \n (enter)
	while(getchar() != '\n');

	// Pedimos el segundo caracter
	printf("Introduce la segunda letra: \n");
	scanf("%c", &caracter2);
	while(getchar() != '\n');

	// Declaramos las restas
	

	if( caracter1 > caracter2 ){
		resta = caracter1 - caracter2;
		printf("La resta es %d \n", resta);
	} else if (caracter2 > caracter1){
		resta = caracter2 - caracter1;
		printf("La resta es %d \n", resta);
	}
}