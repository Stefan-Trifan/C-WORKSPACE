#include <stdio.h>
#define LTEXTO 10

int main(){
    char saludo[LTEXTO] = "Hola";
    char nombre[LTEXTO] = "Pepe";
    char pregunta[LTEXTO] = "ke ase?";

    char *frase[] = {saludo, nombre, pregunta};

    printf("%X ", frase);

}