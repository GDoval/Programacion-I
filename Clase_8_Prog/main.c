#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
int validarCadena(char vec[], int);
int main()
{
    char nombre[TAM];
    char buffer[100]
    printf("Ingrese un nombre ingrese: ");
    gets(buffer);
    while (!validarCadena(buffer, TAM)) //niega la funcion. Si la cadena es  invalida se ingresa un cero, que negado da true. Si es valida no entra al while
    {
        printf("Error, reingrese: ");
        gets(buffer);
    }
    strcpy(nombre, buffer);
    printf("\n%s", nombre);
    return 0;
}


int validarCadena(char vec[], int lengt) // devuelve cero si la cadena es invalida
{
    int resultado = 1, cadena;
    cadena = strlen(vec);
    if (cadena > lengt)
    {
        resultado = 0;
    }
    return resultado;
}
