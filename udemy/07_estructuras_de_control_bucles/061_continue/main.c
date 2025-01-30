//* continue sirve para terminar una iteración y pasar a la siguiente.
//* break no sólo termina con una iteración, sino con el ciclo completo.

#include <stdio.h>

int main() {

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