
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
        validar = validaString(lista[indice].nombreApellido);
        while (validar != -1)
        {
            printf("\nError! Reingrese: ");
            setbuf(stdin, NULL);
            fgets(lista[indice].nombreApellido, 60, stdin);
            sacarEnter(lista[indice].nombreApellido);
            validar = validaString(lista[indice].nombreApellido);
        }

        printf("\nIngrese la direccion de cliente: ");
        setbuf(stdin, NULL);
        fgets(lista[indice].direccion, 30, stdin);
        sacarEnter(lista[indice].direccion);

        printf("\nIngrese el numero de la tarjeta de credito del cliente: ");
        scanf("%li", &lista[indice].tarjetaCredito);
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
        validar = validaInt(autos[indice].horarioEntrada,1, 24);
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
                if (clientes[j].estado != 0 && autos[i].estado != 0)
                {
                    if (clientes[j].idDuenio == autos[i].idDuenio)
                    {
                        printf("\nID: %d\nNombre: %s\nAuto: %s\nHorario de entrada: %dhs\nPatente: %s\nTarjeta: %li\n",clientes[j].idDuenio, clientes[j].nombreApellido,coche, autos[i].horarioEntrada, autos[i].patente, clientes[j].tarjetaCredito);
                        printf("\n------------------------------------------------------------------------------\n");
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
            scanf("%li", &lista[i].tarjetaCredito);
        }
    }
}

void imprimirAudi (eAlquiler autos[], eDuenio lista[], int tamAutos, int tamDuenio)
{
   printf("Usuarios con autos AURI\n\n");
   printf("-----------------------------");
   for (int i = 0; i < tamAutos; i++)
    {
        for (int j = 0; j < tamDuenio; j++)
        {
            if ((autos[i].idDuenio == lista[j].idDuenio) && autos[i].marca == 3)
            {
                printf("\nNombre: %s\nPatente: %s\n", lista[j].nombreApellido, autos[i].patente);
                printf("\n-----------------------------\n");
            }
        }
    }
}


void calcularEstadia (eDuenio lista[], eAlquiler autos[], int tamAutos, int tamDuenios, char patente[], int salida)
{
    int respuesta = 0, horario, flag = 0, flag2 = 0;
    int id;
    char nombre[60], modelo[15];
        for (int j = 0; j < tamAutos; j++)
        {
            if (strcmp(patente, autos[j].patente) == 0 && autos[j].estado == 1)
            {
                flag2 = 1;
                id = autos[j].idDuenio;
                if (autos[j].horarioEntrada < salida)
                {
                    autos[j].horarioSalida = salida;
                    horario = salida - autos[j].horarioEntrada;
                    autos[j].estado = 0;
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
                    printf("\n\nTiempo de estadia excedido.\n\n");
                    break;
                }
            }
        }

    for (int i = 0; i < tamDuenios; i++)
    {
        if (id == lista[i].idDuenio)
        {
            strcpy(nombre, lista[i].nombreApellido);
            break;
        }

    }
    if (flag2 == 0)
    {
        printf("\n\nLa patente ingresada no se encuentra en la base de datos\n\n");

    }else
    {
        if (flag == 0)
        {
            printf("\nNombre: %s\nPatente: %s\nMarca: %s\nTarifa: %d\n\n",nombre, patente, modelo, respuesta);
            printf("\n------------------------------------------------------\n");
        }
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



void totalPorMarca ( eAlquiler autos[], int tamAutos)
{

    int acum1 = 0, acum2 = 0, acum3 = 0, acum4 = 0;
    int resultado;
    for (int i = 0; i < tamAutos; i++)
    {
        if (autos[i].estado != 0)
        {
            resultado = 0;
            switch(autos[i].marca)
            {
                case 1:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 150;
                    acum1 = acum1 + resultado;
                    break;
                case 2:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 175;
                    acum2 = acum2 + resultado;
                    break;
                case 3:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 200;
                    acum3 = acum3 + resultado;
                    break;
                case 4:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 250;
                    acum4 = acum4 + resultado;
                    break;
            }
        }
    }
    printf("\nALPHA ROMEO: %d\nFERRARI: %d\nAUDI: %d\nOTROS: %d\n\n", acum1, acum2, acum3, acum4);
}




void totalEstacionamiento (eAlquiler autos[], int tam)
{
    int acum[4];
    int resultado;
    for (int i = 0; i < 4; i++)
        acum[i] = 0;
    for (int i = 0; i < tam; i++)
    {
        if (autos[i].estado != 0)
        {
            resultado = 0;
            switch(autos[i].marca)
            {
                case 1:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 150;
                    acum[0] = acum[0] + resultado;
                    break;
                case 2:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 175;
                    acum[1] = acum[1] + resultado;
                    break;
                case 3:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 200;
                    acum[2] = acum[2] + resultado;
                    break;
                case 4:
                    resultado = (autos[i].horarioSalida - autos[i].horarioEntrada) * 250;
                    acum[3] = acum[3] + resultado;
                    break;
            }
        }
    }resultado = 0;
    resultado = acum[0] + acum[1] + acum[2] + acum[3];
    printf("\nEl total facturado por el estacionamiento es de: $ %d\n\n", resultado);

}


int validaString (char cadena[])
{
    char letra;
    char buffer[30], buffer2[30];
    int len, k, i = 0, f = 0;
    int respuesta, respuesta2;
    letra = cadena[0];
    len = strlen(cadena);
    while (cadena[i] != 32)         //Como la variable es compuesta por nombre y apellido primero se corrobora que el nombre no tenga errores
    {                               // y despues lo mismo pero con el apellido. Para eso se usan dos buffer para eliminar el espacio en blanco que queda
        i++;                        // entre los dos y que la funcion isalpha() toma como caracter invalido.
    }
    for (int j = 0; j < i; j++)
    {
        buffer[j] = cadena[j];
    }
    i++;
    k = i;
    while (cadena[i] != 32 && i <= len)
    {
        i++;
    }
    for (int j = k; j < i; j++)
    {
        buffer2[f] = cadena[j];
        f++;
    }
    len = strlen(buffer);
    letra = buffer[0];
    for (int i = 0; i < len; i++)
    {
        letra = buffer[i];
        if (!isalpha(letra))
        {
            respuesta = 0;
            break;
        }else
            {
                respuesta = -1;
            }
    }
    len = strlen(buffer2);
    letra = buffer2[0];
    for (int i = 0; i < len; i++)
    {
        letra = buffer2[i];
        if (!isalpha(letra))
        {
            respuesta2 = 0;
            break;
        }else
            {
                respuesta2 = -1;
            }
    }
    if (respuesta == -1 && respuesta2 == -1)
        return respuesta;
    else{
        respuesta = 0;
        return respuesta;
    }
}


