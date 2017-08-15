#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int num1;
    int num2;
    int resta;
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);
    resta = num1 - num2;
    if (resta < 0)
    {
        printf("El resultado %d  es negativo!! ", resta);
    }
    else
    {
        printf("El resultado %d es positivo!! ", resta);
    }

    return 0;
}
