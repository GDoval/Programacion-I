#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int contp = 0;
    int contn = 0;
    for (int x = 0; x < 10; x++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if (num < 0)
        {
            contn ++;
        }
        else
        {
            contp++;
        }

    }
    printf("La cantidad de numeros positivos es %d y la cantidad de negativos es %d ", contp, contn);
    return 0;
}
