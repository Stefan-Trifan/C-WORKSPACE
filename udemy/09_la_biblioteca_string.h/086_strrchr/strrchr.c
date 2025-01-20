//* strrchr(Cadena, Caracter)
//* Regresa el restante de la cadena a partir de la primera aparición del carácter indicado.

#include <stdio.h>
#include <string.h> //? Recuerda incluir la nueva biblioteca

int main() {

    char Abecedario[] = "abcdefghijklmnopqrstuvwxyz";
    char Corte;

    printf("\nLetra donde se cortara el abecedario: ");
    fflush(stdin);
    scanf("%c",&Corte);
    printf("\n%s",strrchr(Abecedario,Corte));

    return 0;
}
