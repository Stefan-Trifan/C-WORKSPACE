//* continue sirve para terminar una iteracion y pasar a la siguiente.
//* break no solo termina con una iteracion, sino con el ciclo completo.

#include <stdio.h>

int main(int argc, char *argv[]) {

    int numero,i;
    printf("Escribe el numero que sera ignorado (0-10): ");
    scanf("%d",&numero);

    for (i = 0; i < 10; i++){
        if (i == numero)
            continue;
            printf("\n%d",i);
    }

    printf("\n\n");

    return 0;
}