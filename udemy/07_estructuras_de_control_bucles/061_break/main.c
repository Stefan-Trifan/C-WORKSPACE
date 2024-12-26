//* continue sirve para terminar una iteración y pasar a la siguiente.
//* break no sólo termina con una iteración, sino con el ciclo completo.

#include <stdio.h>

int main() {

    int num = 0;

	printf("En que numero desea usted que se detenga el ciclo (0-100): ");
    scanf("%i", &num);

    for (int i = 0; i < 100; i++){
        printf("\n%i",i);
        if (i == num) break;
    }

    printf("\n\n");

    return 0;
}