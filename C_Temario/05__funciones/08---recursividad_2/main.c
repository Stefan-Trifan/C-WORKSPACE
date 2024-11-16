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
		Hacer un programa que calcule el minimo, el maximo y la media 
		de tres numeros enteros que deban ser leidos de la entrada estandar

		La funcionalidad debe ser realizada mediante una funcion denominada calculos()
		que reciba como parametros los 3 numeros y devuelva los 3 resultados del siguiente modo:
			la media sera entregada como resultado de la funcion 
			mientras que el minimo y el maximo de los valores se devolveran en los parametros de la funcion 
			por lo que seran pasados por referencia
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

void calculos(int *max, int *min, int *media); // bien

int main(){

	int max, min, media; // bien
	// printf("El contenido de una variable normal es: %d", max)
	// calculos(&max, &min, &media);
	// printf("%d,%d,%d", max, min, media);

}

// bien
void calculos(int *max, int *min, int *media){ 

/* 	
	&max == Acceder a la direccion de memoria del puntero
	max  == Accediento a la direccion que apunta el puntero
/	*max == Accediendo al contenido 

/   *max=numUser;
	Codigo del otro dia
*/

}