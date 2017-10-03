#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 5

int main()
{
    char res = 's';
    int opcion, Id,validar, proyecto;
    eProgramador equipo[TAM];
    eCategoria categoria[] ={"Junior", 1, 25, "SemiSenior", 2, 35, "Senior", 3, 50};
    eProyecto proyectos[] = {1, "AFIP", 2, "ARBA", 3, "Sysmika", 4, "Hollander", 5, "Porcupine S.A"};
    eProgProy listado[15];
    for (int i = 0; i < TAM; i++)
        equipo[i].estado = 0;
    for (int i = 0; i < 15; i++)
        listado[i].estado = 0;
    while (res == 's')
    {
        printf("1) Ingrese un programador. ");
        printf("\n2) Imprimir listado de programadores");
        printf("\n3) Borrar un programador");
        printf("\n4) Modificar programador");
        printf("\n5) Agregar proyecto a un programador");
        printf("\n6) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                ingresoProgramador(equipo,  listado, TAM, 15);
                break;

            case 2:
                imprimirProgramadorMasProyectos(equipo, proyectos, listado, TAM, 5, 15);
                //imprimirProgramador(equipo, categoria,proyectos, listado, TAM, 3, 15);
                break;

            case 3:
                printf("\nIngrese el ID del programador a borrar: ");
                scanf("%d", &Id);
                borrarProgramador(equipo,categoria, proyectos, listado, TAM, Id, 3, 15);
                break;

            case 4:
                printf("\nIngrese ID del programador a modificar: ");
                scanf("%d", &Id);
                modificarProgramador(equipo, listado,TAM, Id);
                break;
            case 5:
                printf("\nIngrese ID del programador: ");
                scanf("%d", &Id);
                validar = buscarProgramador(equipo, TAM, Id);
                if (validar == -1)
                {
                    printf("\nError! El ID ingresado no existe\n");
                    break;
                }else
                {
                    printf("\nIngrese numero de proyecto: ");
                    scanf("%d", &proyecto);
                    validar = validarProyecto(proyectos, 5, proyecto);
                    if (validar == -1)
                    {
                        printf("\nError! El proyecto ingresado no existe.");
                        break;
                    }else
                    {
                        agregarProyecto(equipo, listado, TAM, 15, Id, proyecto);
                    }
                }
                break;

            case 6:
                res = 'n';
                break;
        }

    }


    return 0;
}
