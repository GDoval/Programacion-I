#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void ingresoProgramador (eProgramador lista[], eProgProy tabla[], int tam, int tamProy )
{
    int indice, indice2, validar;
    indice = buscarVacio(lista, tam);
    indice2 = buscarVacioProg(tabla,tamProy);
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
        tabla[indice2].idProg = lista[indice].id;


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
        scanf("%d", &tabla[indice2].horasTrabajadas);




        tabla[indice2].idProyec = lista[indice].idProye;
        lista[indice].estado = 1;
        tabla[indice2].estado = 1;
    }else
    {
        printf("\nNo hay lugar en el sistema no hay.");
        printf("\n\n");
    }

}


void imprimirProgramador (eProgramador lista[], eCategoria cates[], eProyecto proyes[], eProgProy tabla[], int cantProg, int cantCate, int cantProy)
{

    int indiceProyecto, horas;
    printf("\nNombre\tCategoria\tProyecto\n");
    for (int i = 0; i < cantProg; i++)
    {
        if (lista[i].estado != 0)
        {
            printf("\n%s", lista[i].nombre);
            for (int j = 0; j < cantCate; j++ )
            {
                if (cates[j].idCat == lista[i].idCate)
                {
                    printf("\t%s", cates[j].desc);
                    for (int k = 0; k < cantProy; k++ )
                    {
                        if (lista[i].id == tabla[k].idProg)
                        {
                            printf("\t%s\n", proyes[k].desc);
                        }
                    }
                }
            }
        }
    }
}


void imprimirProgramadorMasProyectos(eProgramador lista[], eProyecto proyectos[], eProgProy tabla[], int tamProg, int tamProy, int tamTabla)
{
    for(int i = 0; i < tamProg; i++)
    {
        if (lista[i].estado != 0)
        {
            printf("\n%s", lista[i].nombre);
            for (int j = 0; j < tamTabla; j++)
                {
                if (lista[i].id == tabla[j].idProg)
                {
                for (int k = 0; k < tamProy; k++)
                    {
                        if (tabla[j].idProyec == proyectos[k].idProyec)
                        {
                            printf("\n\t%s", proyectos[k].desc);
                        }
                    }
                }
            }
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





void borrarProgramador (eProgramador lista[], eCategoria cate[], eProyecto proyecto[], eProgProy tabla[], int cantProg, int id, int cantCat, int cantProy)
{

    char respuesta = 's';
    for (int i = 0; i < cantProg; i++)
    {
        if (lista[i].id == id)
        {
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
            imprimirProgramador(lista,cate,proyecto, tabla, cantProg, cantCat, cantProy);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
            printf("\n¿Desea eliminar este registro? s/n ");
            setbuf(stdin, NULL);
            scanf("%c", &respuesta);
            if (respuesta == 's')
            {
             lista[i].estado = 0;
             break;
            }else
                {
                    printf("\nEl registro no fue eliminado\n");
                    break;
                }
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

int buscarProgramador (eProgramador lista[], int tam, int id) // devuelve el indice donde esta el ID pasado como parametro
{
    int respuesta = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].id == id)
        {
            respuesta = i;
            break;
        }
    }
    return respuesta;
}



int validarProyecto (eProyecto lista[], int tam, int proyecto) // se fija que el numero de proyecto que se pasa este dentro de la estructura eProyecto
{
    int respuesta = -1;
    for (int i = 0; i < tam; i++)
    {
        if(lista[i].idProyec == proyecto)
        {
            respuesta = i;
            break;
        }
    }
    return respuesta;
}

void agregarProyecto (eProgramador lista[], eProgProy tabla[], int tamProg, int tamProy, int id, int proyecto)
{

    int indice, flag = 0;
    for (int i = 0; i < tamProy; i++)
    {
        if(tabla[i].idProg == id && tabla[i].idProyec == proyecto)
        {
            flag = 1;
            printf("\nEl programador %s ya se encuentra asociado al proyecto %d", lista[i].nombre, proyecto);
            break;
        }
    }
    if (flag == 0)
    {
        indice = buscarVacioProg(tabla, tamProy);
        if(indice != -1)
        {
            tabla[indice].idProyec = proyecto;
            tabla[indice].idProg = id;
            tabla[indice].estado = 1;
        }else
        {
            printf("\nNo hay mas lugar en el sistema.\n");
        }
    }
    for (int i = 0; i < tamProy; i++)
    {
        printf("\n\n%d     %d ", tabla[i].idProg, tabla[i].idProyec);
    }
}




int buscarVacioProg (eProgProy listado[], int tam)
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
