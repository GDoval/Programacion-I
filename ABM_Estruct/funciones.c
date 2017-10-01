#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void ingresoProgramador (eProgramador lista[], eProgProy tabla[], int tam )
{
    int indice, validar;
    indice = buscarVacio(lista, tam);
    if (indice != -1)
    {
        printf("Ingrese el nombre del programador: ");
        setbuf(stdin, NULL);
        fgets(lista[indice].nombre, 50, stdin);
        sacarEnter(lista[indice].nombre);
        validar = validaString(lista[indice].nombre);
        while (validar == 0)
        {
            printf("\nError! Ingrese el nombre del programador: ");
            setbuf(stdin, NULL);
            fgets(lista[indice].nombre, 50, stdin);
            sacarEnter(lista[indice].nombre);
            validar = validaString(lista[indice].nombre);
        }

        printf("\nIngrese el ID del programador: ");
        scanf("%d", &lista[indice].id);
        tabla[indice].idProg = lista[indice].id;


        printf("Ingrese la categoria del programdor: 1-Junior; 2-SemiSenior, 3-Senior: ");
        scanf("%d", &lista[indice].idCate);
        validar = validarCate(lista[indice].idCate);
        while (validar == -1)
        {
            printf("\nError! Ingrese la categoria del programdor: 1-Junior; 2-SemiSenior, 3-Senior: ");
            scanf("%d", &lista[indice].idCate);
            validar = validarCate(lista[indice].idCate);
        }




        printf("Ingrese el proyecto al que pertenece el programador: ");
        scanf("%d", &lista[indice].idProye);



        printf("\nIngrese la cantidad de horas trabajadas: ");
        scanf("%d", &tabla[indice].horasTrabajadas);




        tabla[indice].idProyec = lista[indice].idProye;
        lista[indice].estado = 1;
        tabla[indice].estado = 1;
    }else
    {
        printf("\nNo hay lugar en el sistema no hay.");
        printf("\n\n");
    }

}


void imprimirProgramador (eProgramador lista[], eCategoria cates[], eProyecto proyes[], eProgProy tabla[], int cantProg)
{

    int indiceProyecto, horas;
    for (int i = 0; i < cantProg; i++)
    {
        if (lista[i].estado != 0)
        {

            indiceProyecto = buscarProyecto(lista,cantProg,tabla, i);
            horas = buscarHorasTrabajo(lista,cantProg,tabla,i);
            lista[i].sueldo = cates[lista[i].idCate -1].valorHora * horas;
            printf("\n%s       %d      %s         %s                  %d\n\n", lista[i].nombre, lista[i].id, cates[lista[i].idCate -1].desc, proyes[indiceProyecto-1].desc, lista[i].sueldo);
        }
    }
}




int buscarProyecto (eProgramador listado[], int tam, eProgProy tabla[], int indice)
{
    int proyecto;
    for (int i = 0; i < tam; i++)
    {
        if (listado[indice].id == tabla[i].idProg)
        {
            proyecto = tabla[i].idProyec;
            break;
        }
    }
    return proyecto;
}






int buscarHorasTrabajo (eProgramador listado[], int tam, eProgProy tabla[], int indice)
{
    int horas;
    for (int i = 0; i < tam; i++)
    {
        if (listado[indice].id == tabla[i].idProg)
        {
            horas = tabla[i].horasTrabajadas;
            break;
        }
    }
    return horas;
}





int buscarVacio (eProgramador listado[], int tam)
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





void borrarProgramador (eProgramador lista[], int cantProg, int id)
{
    for (int i = 0; i < cantProg; i++)
    {
        if (lista[i].id == id)
        {
            lista[i].estado = 0;
            break;
        }
    }
}

int validarCate (int categoria)
{
    int respuesta = 1;
    if (categoria != 1 && categoria != 2 && categoria != 3)
        respuesta = -1;
    return respuesta;
}


int validaString (char cadena[])
{
    char letra;
    int respuesta, len;
    letra = cadena[0];
    len = strlen(cadena);
    for (int i = 0; i < len; i++)
    {
        letra = cadena[i];
        if (!isalpha(letra))
        {
            respuesta = 0;
            break;
        }else
            {
                respuesta = -1;
            }
    }

    return respuesta;
}


void modificarProgramador (eProgramador lista[], eProgProy tabla[], int cantProg, int id)
{
        int validar;
        for (int i = 0; i < cantProg; i++)
        {
            if (lista[i].id == id)
            {
                printf("Ingrese el nombre del programador: ");
                setbuf(stdin, NULL);
                fgets(lista[i].nombre, 50, stdin);
                sacarEnter(lista[i].nombre);
                validar = validaString(lista[i].nombre);
                while (validar == 0)
                {
                    printf("\nError! Ingrese el nombre del programador: ");
                    setbuf(stdin, NULL);
                    fgets(lista[i].nombre, 50, stdin);
                    sacarEnter(lista[i].nombre);
                    validar = validaString(lista[i].nombre);
                }

                printf("\nIngrese el ID del programador: ");
                scanf("%d", &lista[i].id);
                tabla[i].idProg = lista[i].id;

                printf("Ingrese la categoria del programdor: 1-Junior; 2-SemiSenior, 3-Senior: ");
                scanf("%d", &lista[i].idCate);
                validar = validarCate(lista[i].idCate);
                while (validar == -1)
                {
                    printf("\nError! Ingrese la categoria del programdor: 1-Junior; 2-SemiSenior, 3-Senior: ");
                    scanf("%d", &lista[i].idCate);
                    validar = validarCate(lista[i].idCate);
                }

                printf("Ingrese el proyecto al que pertenece el programador: ");
                scanf("%d", &lista[i].idProye);

                printf("\nIngrese la cantidad de horas trabajadas: ");
                scanf("%d", &tabla[i].horasTrabajadas);
            }
        }
}
