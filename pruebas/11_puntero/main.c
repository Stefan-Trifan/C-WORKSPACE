#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("El valor de argc es %d\n", argc);
    
    for (int i = 0; i < argc; i++) // Correccion: i < argc
    {
        printf("argv[%d] = %s\n", i, argv[i]); // Correccion: Sintaxis de printf
    }

    return 0;
}
