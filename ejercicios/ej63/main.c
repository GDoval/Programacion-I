#include <stdio.h>
#include <stdlib.h>
#define TAM 3
int main()
{
    int leg[TAM], edad[TAM], salario[TAM];
    float promedio = 0;
    for (int i = 0; i < TAM; i++)
    {
        printf("Ingrese numero de legajo: \n");
        scanf("%d", &leg[i]);
        printf("Ingrese la edad: \n");
        scanf("%d", &edad[i]);
        printf ("Ingrese salario: \n");
        scanf("%d", &salario[i]);
        system("clear");

    }
    for (int i = 0; i < TAM; i++)
    {
        promedio = promedio + edad[i];
    }
    promedio = promedio / TAM;
    for (int i = 0; i < TAM; i++)
    {
        if (edad[i] > promedio)
        {
            printf("\nLegajo %d, Edad %d, Salario %d", leg[i], edad[i], salario[i]);
        }


    }
    return 0;
}
