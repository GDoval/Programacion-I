
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Estacionamiento.h"

void ingresoDuenio (eDuenio lista[], int tam)
{
    int indice, validar, id;
    indice = buscarVacioDuenios( lista, tam);
    if (indice != -1)
   {
        printf("Ingrese el ID del cliente: ");
        scanf("%d", &id);
        validar = idDuenio(lista,tam,id);
        while (validar == 1)
        {
            printf("\nError! El ID ingresado ya se encuentra asociado a un cliente. Reingrese: ");
            scanf("%d", &id);
            validar = idDuenio(lista,tam, id);

        }
        lista[indice].idDuenio = id;
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


    }else
    {
        printf("\nNo hay lugar en el sistema.\n");
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


        printf("\nIngrese marca del auto: 1-ALPHA ROMEO; 2-FERRARI; 3-AUDI; 4-OTROS: ");
        scanf("%d", &autos[indice].marca);
        validar = validaInt(autos[indice].marca, 1, 4);
        while (validar == -1)
        {
            printf("\nError! Ingrese un numero del 1 al 4: ");
            scanf("%d", &autos[indice].marca);
            validar = validaInt(autos[indice].marca, 1, 4);
        }



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
        validar = validaInt(autos[indice].horarioEntrada,0, 24);
        while (validar == -1)
        {
            printf("\nError! Por favor ingrese un horario entre 1 y 24: ");
            scanf("%d", &autos[indice].horarioEntrada);
            validar = validaInt(autos[indice].horarioEntrada,1,24);
        }
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
    printf("Duenio    \t Auto\t   Horario de Entrada\tPatente  \tTarjeta de credito");
    printf("\n----------------------------------------------------------------------------\n");
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
                        printf("\n%s   \t%s   %d\t    %s  \t      %d\n", clientes[j].nombreApellido,coche, autos[i].horarioEntrada, autos[i].patente, clientes[j].tarjetaCredito);
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


void calcularEstadia (eDuenio lista[], eAlquiler autos[], int tamAutos, int tamDuenios, int id, int salida)
{
    int respuesta = 0, horario, flag = 0;
    char nombre[60], patente[7], modelo[15];
    for (int i = 0; i < tamDuenios; i++)
    {
        if(lista[i].idDuenio == id)
        {
            strcpy(nombre, lista[i].nombreApellido);
            for (int j = 0; j < tamAutos; j++)
            {
                if (lista[i].idDuenio == autos[j].idDuenio)
                {
                    if (autos[j].horarioEntrada < salida)
                        {
                            horario = salida - autos[j].horarioEntrada;
                            strcpy(patente, autos[j].patente);
                            switch (autos[j].marca)
                            {
                            case 1:
                                respuesta = horario * 150;
                                strcpy(modelo, "ALPHA_ROMEO");
                                break;
                            case 2:
                                respuesta = horario *175;
                                strcpy(modelo, "FERRARI");
                                break;
                            case 3:
                                respuesta = horario * 200;
                                strcpy(modelo, "AUDI");
                                break;
                            case 4:
                                respuesta = horario * 250;
                                strcpy(modelo, "OTROS");
                                break;
                            }
                        }else
                            {
                                flag = 1;
                                printf("\nTiempo de estadia excedido\n");
                                break;
                            }
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("\nNombre     Patente      Marca     Tarifa\n");
        printf("\n%s        %s        %s     %d\n\n",nombre, patente, modelo, respuesta);
    }
}


int validaInt (int input, int lowLimit, int hiLimit)
{
    int resultado = 0;
    if (input < lowLimit || input > hiLimit)
    {
        resultado = -1;
    }
    return resultado;
}
