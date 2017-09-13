#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct { // crea el tipo de dato.
    int dni;
    char nombre[50];
    float peso;
}ePersona; //nombre del tipo de dato

int main()
{
    ePersona unaPersona; //crea una variable del tipo estructura. Se asigna espacio en memoria para todos los campos de la estructura
    printf("Ingrese DNI: \n");
    scanf("%d", &unaPersona.dni);
    printf("Ingrese nombre: \n");
    setbuf(stdin, NULL);
    gets(unaPersona.nombre);
    printf("Ingrese peso: \n");
    scanf("%f", &unaPersona.peso);
    printf("%d //%s // %.1f", unaPersona.dni, unaPersona.nombre, unaPersona.peso);
    return 0;
}
