//* strcat(Destino, Fuente)
//* Concatena (agrega) la cadena fuente en el destino. Debes considerar que la cadena destino
//* debe tener un tamaño tal que pueda albergar la cadena resultante.

#include <stdio.h>
#include <string.h> //? Recuerda incluir la nueva biblioteca

int main() {

    char Cadena1[] = "Jorge",Cadena2[]="Ricardo";
    char Final[50];

    //* Concatenamos
    strcat(Final,Cadena1);
    strcat(Final,"-");
    strcat(Final,Cadena2);
    printf("%s",Final); //! Imprime 'Jorge-Ricardo'

    return 0;
} 