// Invertir una cadena con la funcion strrev().

#include<stdio.h>
#include<string.h>

int main(){

	char cadena[] = "Jorge";
	
	strrev(cadena); //Invertimos la cadena con la funcion strrev
	
	printf("Cadena Invertida: %s",cadena); 
	//mostramos la cadena invertida
	
	
	return 0;
}
