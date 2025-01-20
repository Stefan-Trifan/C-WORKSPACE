//* strlwr(Cadena)
//* Convierte a minúsculas todas las letras de una cadena de texto. 

#include <stdio.h>
#include <string.h> //? Recuerda incluir la nueva biblioteca

int main() {

    char texto[100];
    printf("Escribe un texto con mayusculas y minusculas\n");
    fflush(stdin);
    gets(texto);

    printf("El nuevo texto es el siguiente:\n");
    printf("%s\n",strlwr(texto));

    return 0;
}