//* strupr(Cadena)
//* Contrario a strlwr, esta función convierte a mayúsculas las letras de una cadena.

#include <stdio.h>
#include <string.h> //? Recuerda incluir la nueva biblioteca

int main() {

    char texto[100];
    printf("Escribe un texto con mayusculas y minusculas\n");
    fflush(stdin);
    gets(texto);

    printf("El nuevo texto es el siguiente:\n");
    printf("%s\n",strupr(texto));


    return 0;
}