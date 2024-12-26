//* continue sirve para terminar una iteración y pasar a la siguiente.
//* break no sólo termina con una iteración, sino con el ciclo completo.

#include <stdio.h>

int main() {

		
    //* El ciclo esta definido hasta 99
    for (int i = 0; i < 100; i++){
        if (i == 5)
        break;
        printf("\n%i",i);
        
    }

    printf("\n\n");

    return 0;
}