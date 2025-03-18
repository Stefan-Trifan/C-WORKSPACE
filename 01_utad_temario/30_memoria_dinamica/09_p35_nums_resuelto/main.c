#include <stdio.h>
#include <stdlib.h>

int main()
{
    int primerNum = 1, cont = 0;
    int *numActual = (int *)malloc(sizeof(int));

    if (numActual == NULL)
    {
        printf("Error: No hay espacio de memoria\n");
        return 1;
    }

    *numActual = 0;
    while (
		*(numActual + (cont - 1)) <= primerNum || cont == 0)
    {
        printf("Introduce un numero: ");
        scanf("%i", (numActual + cont));

        if (cont == 0)
		{
			primerNum = *numActual;
		} 
        cont++;

        if (*(numActual + cont) < primerNum)
        {
            numActual = (int *)realloc(numActual, sizeof(int) * (cont + 1));
            *(numActual + cont) = 0;
        }
    }
    for (int i = 0; i < cont; i++)
        printf("El %i numero es: %i\n", i, *(numActual + i));
    free(numActual);
    return 0;
}
