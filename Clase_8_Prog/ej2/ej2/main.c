#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
int validarCadena(char vec[], int);
void mostrarNombre(char[]);
void mostrarNombres(char[][TAM], int);
void ordenarNombres(char [][TAM], int);
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
    mostrarNombres(nombres, 5);
    printf("\n\n");
    ordenarNombres(nombres, 5);
    mostrarNombres(nombres,5);

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


void mostrarNombre(char vec[])
{
    printf("%s\n", vec);
}

void mostrarNombres(char nombres[][TAM], int filas)
{
    for (int i = 0; i < filas; i++)
    {
        mostrarNombre(nombres[i]);
    }
}

void ordenarNombres(char nombre[][TAM], int filas)
{
    char temporal[TAM];
    int j;
    for (int i = 1; i < filas; i++)
    {
        strcpy(temporal, nombre[i]);
        j = i -1;
        while ((strcmp(temporal, nombre[j]) < 0) && j >=0)
        {
            strcpy(nombre[j+1], nombre[j]);
            j--;
        }
        strcpy(nombre[j+1], temporal);
    }
}
