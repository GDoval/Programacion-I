#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Estacionamiento.h"

void ingresoDuenio (eDuenio lista[], int tam)
{
    int indice;
    indice = buscarVacioDuenios( lista, tam);
    if (indice != -1)
   {
        printf("Ingrese el ID del cliente: ");
        scanf("%d", &lista[indice].idDuenio);
        printf("\nIngrese nombre y apellido del cliente: ");
        setbuf(stdin, NULL);
        fgets(lista[indice].nombreApellido, 60, stdin);
        sacarEnter(lista[indice].nombreApellido);
        printf("\nIngrese la direccion de cliente: ");
        setbuf(stdin, NULL);
        fgets(lista[indice].direccion, 30, stdin);
        sacarEnter(lista[indice].direccion);
        printf("\nIngrese el numero de la tarjeta de credito del cliente: ");
        scanf("%d", &lista[indice].tarjetaCredito);
        lista[indice].estado = 1;
    }
}


void ingresoAuto (eAlquiler autos[], eDuenio lista[], int tam, int tamDuenios)
{
    int indice, validar;
    indice = buscarVacioAlquiler(autos, tam);
    if (indice != -1)
    {
        printf("Ingrese patente del auto: ");
        setbuf(stdin, NULL);
        fgets(autos[indice].patente, 15, stdin);
        sacarEnter(autos[indice].patente);
        printf("\nIngrese marca del auto: 1-ALPHA ROMEO; 2-FERRARI; 3-AUDI; 4-OTROS");
        scanf("%d", &autos[indice].marca);



        printf("\nIngrese ID del dueño del auto: ");
        scanf("%d", &autos[indice].idDuenio);
        validar = idDuenio(lista, tamDuenios,autos[indice].idDuenio);
        while (validar == -1)
        {
            printf("\n Error! El ID ingrsado no corresponde a un duenio. Reingrese: ");
            scanf("%d", &autos[indice].idDuenio);
            validar = idDuenio(lista, tamDuenios,autos[indice].idDuenio);
        }

        printf("\nIngrese horario de entrada en horas: ");
        scanf("%d", &autos[indice].horarioEntrada);
        autos[indice].estado = 1;
    }else
    {
        printf("\nCochera llena.\n");
    }
}




int buscarVacioDuenios (eDuenio listado[], int tam)
{
    int resultado = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listado[i].estado == 0)
        {
            resultado = i;
            break;
        }
    }
    return resultado;
}


int buscarVacioAlquiler (eAlquiler listado[], int tam)
{
    int resultado = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listado[i].estado == 0)
        {
            resultado = i;
            break;
        }
    }
    return resultado;
}



void sacarEnter(char vec[])
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}


void ordenarAutosHorario (eAlquiler autos[], int tam)
{
    eAlquiler aux;
    for (int i = 0; i < tam; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(autos[i].horarioEntrada > autos[j].horarioEntrada)
            {
                aux = autos[i];
                autos[i] = autos[j];
                autos[j] = aux;
            }else
            {
                if(autos[i].horarioEntrada == autos[j].horarioEntrada)
                {
                    if(strcmp(autos[i].patente, autos[j].patente) > 0)
                    {
                        aux = autos[i];
                        autos[i] = autos[j];
                        autos[j] = aux;
                    }
                }
            }
        }
    }
}
void imprimirListado (eDuenio clientes[], eAlquiler autos[], int tamClientes, int tamAutos)
{
    printf("Duenio\tAuto \tHorario de Entrada\t Patente\t  Tarjeta de credito");
    printf("\n-----------------------------------------\n");
    char coche[20];
    for (int i = 0; i < tamAutos; i++)
    {
            switch (autos[i].marca)
            {
            case 1:
                strcpy(coche, "ALPHA_ROMEO");
                break;
            case 2:
                strcpy(coche, "FERRARI");
                break;
            case 3:
                strcpy(coche, "AUDI");
                break;
            case 4:
                strcpy(coche, "OTROS");
                break;
            }
            for (int j = 0; j < tamClientes; j++)
            {
                if (clientes[j].estado != 0)
                {
                    if (clientes[j].idDuenio == autos[i].idDuenio)
                    {
                        printf("\n%s\t%s\t%d\t%s\t%d\n", clientes[j].nombreApellido, coche, autos[i].horarioEntrada, autos[i].patente, clientes[j].tarjetaCredito);
                    }
                }

            }
    }
}


int idDuenio(eDuenio lista[], int tam, int id)
{
    int respuesta = -1;
    for (int i = 0; i < tam; i++)
    {
        if(lista[i].idDuenio == id)
        {
             respuesta = 1;
            break;
        }

    }
    return respuesta;
}



void modificarTarjeta (eDuenio lista[], int tam, int id)
{
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].idDuenio == id)
        {
            printf("\nIngrese nuevo numero de tarjeta de credito: ");
            scanf("%d", &lista[i].tarjetaCredito);
        }
    }
}

void imprimirAudi (eAlquiler autos[], eDuenio lista[], int tamAutos, int tamDuenio)
{
   printf("Usuarios con autos AURI\n\n");
   printf("\nNombre\tPatente\n\n");
   for (int i = 0; i < tamAutos; i++)
    {
        for (int j = 0; j < tamDuenio; j++)
        {
            if ((autos[i].idDuenio == lista[j].idDuenio) && autos[i].marca == 3)
            {
                printf("\n%s\t%s\n", lista[j].nombreApellido, autos[i].patente);
            }
        }
    }
}


int calcularEstadia (eAlquiler autos[], int tam, int id)
{
    int respuesta, horario;
    for (int i = 0; i < tam; i++)
    {
        if (autos[i].idDuenio == id)
        {
            printf("\nIngrese el horario de salida: ");
            scanf("%d", &autos[i].horarioSalida);
            if (autos[i].horarioEntrada < autos[i].horarioSalida)
            {
                horario = autos[i].horarioSalida - autos[i].horarioEntrada;
                switch (autos[i].marca)
                {
                case 1:
                    respuesta = horario * 150;
                    break;
                case 2:
                    respuesta = horario *175;
                    break;
                case 3:
                    respuesta = horario * 200;
                    break;
                case 4:
                    respuesta = horario * 250;
                    break;
                }
            }else
            {
                printf("\nTiempo de estadia excedido\n")
            }
        }
    }

}
