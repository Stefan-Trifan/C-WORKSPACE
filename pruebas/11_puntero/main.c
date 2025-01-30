#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("El valor de argc es %d\n", argc);
    
    for (int i = 0; i < argc; i++) // Corrección: i < argc
    {
        printf("argv[%d] = %s\n", i, argv[i]); // Corrección: Sintaxis de printf
    }

    return 0;
}
