#include <stdio.h>

int main()
{
#ifdef __STDC__
    printf("Cumple con el estándar ANSI C\n");
#endif

#ifdef __STDC_VERSION__
    printf("STDC VERSION: %ld\n", __STDC_VERSION__);
    if (__STDC_VERSION__ == 199409L)
    {
        printf("C94\n");
    }
    else if (__STDC_VERSION__ == 199901L)
    {
        printf("C99\n");
    }
    else if (__STDC_VERSION__ == 201112L)
    {
        printf("C11\n");
    }
    else if (__STDC_VERSION__ == 201710L)
    {
        printf("C17\n");
    }
    else if (__STDC_VERSION__ >= 202000L)
    {
        printf("C2x (posiblemente C23 o superior)\n");
    }
#else
    printf("Probablemente es C89/C90\n");
#endif

    return 0;
}
