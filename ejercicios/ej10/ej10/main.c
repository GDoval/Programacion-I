#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contimp = 0;
    for (int x = 0; x < 100; x++)
    {
        if (x % 2 != 0 && x !=0)
        {
            contimp++;
            printf("EL numero %d es impar \n", x);
        }
    }
    printf("Cantidad de numeros impares entre 0 y 100: %d", contimp);
    return 0;
}
