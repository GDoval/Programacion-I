#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 5

int main()
{
    char res = 's';
    int opcion, Id;
    eProgramador equipo[TAM];
    eCategoria categoria[] ={"Junior", 1, 25, "SemiSenior", 2, 35, "Senior", 3, 50};
    eProyecto proyectos[] = {1, "AFIP", 2, "ARBA", 3, "Sysmika", 4, "Hollander", 5, "Porcupine S.A"};
    eProgProy listado[15];
    for (int i = 0; i < TAM; i++)
        equipo[i].estado = 0;

    while (res == 's')
    {
        printf("1) Ingrese un programador. ");
        printf("\n2) Imprimir listado de programadores");
        printf("\n3) Borrar un programador");
        printf("\n4) Modificar programador");
        printf("\n5) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                ingresoProgramador(equipo,  listado, TAM);
                break;

            case 2:
                imprimirProgramador(equipo, categoria,proyectos, listado, TAM);
                break;

            case 3:
                printf("\nIngrese el ID del programador a borrar: ");
                scanf("%d", &Id);
                borrarProgramador(equipo,categoria, proyectos, listado, TAM, Id);
                break;

            case 4:
                printf("\nIngrese ID del programador a modificar: ");
                scanf("%d", &Id);
                borrarProgramador(equipo, categoria, proyectos, listado, TAM, Id);
                break;
            case 5:
                res = 'n';
                break;
        }

    }


    return 0;
}
