#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
int validarCadena(char vec[], int);
int main()
{
    char nombres[5][TAM];
    char buffer[100];
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese un nombre ingrese: ");
        gets(buffer);
        while (!validarCadena(buffer, TAM))
        {
            printf("Error, reingrese: ");
            gets(buffer);
        }
        strcpy(nombres[i], buffer);
    }

    for ( int i= 0; i <5; i++)
    {
        printf("\n%s", nombres[i]);
    }
    printf("\n\n");

    return 0;
}


int validarCadena(char vec[], int lengt)
{
    int resultado = 1, cadena;
    cadena = strlen(vec);
    if (cadena > lengt)
    {
        resultado = 0;
    }
    return resultado;
}
