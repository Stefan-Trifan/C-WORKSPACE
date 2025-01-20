//* strlen(Cadena)
//* Devuelve un entero que representa la longitud de una cadena de texto (incluyendo espacios
//* en blanco, pero excluyendo el caracter nulo). 

#include <stdio.h>
#include <string.h> //? Recuerda incluir la nueva biblioteca

int main() {

//? La dimension del array es 200, pero la cadena puede ser menor

    char array[200];
    printf("Escribe cualquier cosa\n");
    fflush(stdin);
    scanf("%s",&array);
    printf("\n La longitud de la cadena digitada es: %i",strlen(array));

    return 0;
}