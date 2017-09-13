#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct { // crea el tipo de dato.
    int dni;
    char nombre[50];
    float peso;
}ePersona; //nombre del tipo de dato
void mostrarPersonas(ePersona, int);

int main()
{
    //ePersona otraPersona;
    ePersona listaPersona[3];
    /*ePersona unaPersona; //crea una variable del tipo estructura. Se asigna espacio en memoria para todos los campos de la estructura
    printf("Ingrese DNI: \n");
    scanf("%d", &unaPersona.dni);
    printf("Ingrese nombre: \n");
    setbuf(stdin, NULL); // limpia el buffer. Vale en Linux. Usar siempre que se pida un char o un string.
    gets(unaPersona.nombre);
    printf("Ingrese peso: \n");
    scanf("%f", &unaPersona.peso);
    otraPersona = unaPersona; // se pasan todos los campos.
    //printf("Una persona: DNI : %d, Nombre: %s  Peso: %f \n Otra Persona:  DNI %d  Nombre: %s   Peso: %f \n", unaPersona.dni, unaPersona.nombre, unaPersona.peso, otraPersona.dni, otraPersona.nombre, otraPersona.peso);
    */
    for (int i = 0; i < 3; i++)
    {
        printf("\nIngrese DNI: ");
        scanf("%d", &listaPersona[i].dni);
        printf("\nIngrese nombre: ");
        setbuf(stdin, NULL);
        gets(listaPersona[i].nombre);
        printf("\nIngrese peso: ");
        scanf("%f", &listaPersona[i].peso);
    }
    for (int i = 0; i <3 ; i++)
    {
        mostrarPersonas(listaPersona[i], 3);
    }

    return 0;
}


void mostrarPersonas(ePersona personita, int tam)
{

    printf("\n%d // %s // %f \n", personita.dni, personita.nombre, personita.peso);

}
