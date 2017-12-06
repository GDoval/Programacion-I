#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parse.h"

int main()
{
    ArrayList* logs = al_newArrayList();
    ArrayList* servicios = al_newArrayList();
    int opcion, validar;
    char resp = 's';
    while (resp == 's')
    {
        system("cls");
        printf("1) Parsear Logs\n");
        printf("2) Parsear Servicios\n");
        printf("3) Procesar Gravedad\n");
        printf("4) Mostrar Estadisticas\n");
        printf("5) Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            validar = parse_Log(logs);
            if (!validar)
            {
                printf("\nExito.\n\n");
                system("pause");
            }else
            {
                printf("\nError!!!!");
                system("pause");
            }
            break;
        case 2:
            validar = parse_sistema(servicios);
            if (!validar)
            {
                printf("\nExito\n\n");
                system("pause");
            }else
            {
                printf("\nError!!!");
                system("pause");
            }
            break;
        case 3:
            imprimir(logs);
            printf("\n\n");
            imprimir_service(servicios);
            system("pause");
            break;
        case 4:
            break;
        case 5:
            resp = 'n';
            break;
        }
    }
    return 0;
}
