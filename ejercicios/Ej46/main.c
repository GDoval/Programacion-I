#include <stdio.h>
#include <stdlib.h>
#define TAM 50
int main()
{
    int temp, tempmax, tempmin, flag,i;
    char fecha[TAM],  fechamax[TAM], fechamin[TAM];
    flag = 0;
    for ( i = 0; i < 2; i++)
    {
        printf("Ingrese la fecha: ");
        scanf("%s", &fecha);
        printf("Ingrese la temperatura: ");
        scanf("%d", &temp);
        if (temp > tempmax || flag == 0)
        {
            tempmax = temp;
            strcpy(fechamax, fecha);
        }
        if (temp < tempmin || flag == 0)
        {
            tempmin = temp;
            strcpy(fechamin, fecha);
            flag = 1;
        }
    }
    printf("La temperatura mas baja se registro en la fecha: %s y fue de %d grados.\n", fechamin, tempmin);
    printf("La temperatura mas alta se registro en la fecha: %s y fue de %d grados. \n", fechamax, tempmax);

    return 0;
}
