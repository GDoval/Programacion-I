#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Estacionamiento.h"
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4
#define TAM_AUTOS 3
#define TAM_DUENIOS 3


int main()
{
    char res ='s';
    int opcion, validar, id;
    eDuenio clientes[TAM_DUENIOS];//={{1,"Gaston Doval", "Evergreen 255", 1564891,1}, {2, "Pepe Aramado", "Calle 123", 4578748, 1}};
    eAlquiler autos[TAM_AUTOS]; //= {{"JKO 987", 1, 1, 16, 1}, {"ZBC 123", 2, 2, 16, 1}, {"BCA 984", 3, 7, 15, 1}};
    eAlquiler autosOrdenados[TAM_AUTOS];
    for (int i = 0; i < 5; i++)
    {
        clientes[i].estado = 0;
        autos[i].estado = 0;
    }
    while (res == 's')
    {
        printf("1) Ingrese duenio");
        printf("\n2) Ingrese autos");
        printf("\n3) Modificar tarjeta de credito");
        printf("\n4) Imprimir auris");
        printf("\n5) Imprimir listado de autos estacionados con sus dueños");
        printf("\n6) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                ingresoDuenio(clientes, TAM_DUENIOS);
                break;
            case 2:
                ingresoAuto(autos, clientes, TAM_AUTOS, TAM_DUENIOS);
                break;

            case 3:
                system("cls");
                printf("Ingrese su ID: ");
                scanf("%d", &id);
                validar = idDuenio(clientes, TAM_DUENIOS, id);
                while (validar == -1)
                {
                    printf("\nEl ID ingresado no es valido. Reingrese: ");
                    scanf("%d", &id);
                    validar = idDuenio(clientes, TAM_DUENIOS, id);
                }
                modificarTarjeta(clientes, TAM_DUENIOS, id);
                break;

            case 4:
                system("cls");
                imprimirAudi(autos, clientes, );
                break;
            case 5:
                system("cls");
                for (int  i = 0; i < TAM_AUTOS; i++)
                {
                    autosOrdenados[i] = autos[i];
                }
                ordenarAutosHorario(autosOrdenados, TAM_AUTOS);
                imprimirListado(clientes, autosOrdenados, TAM_DUENIOS, TAM_AUTOS);
                printf("\n\n");
                break;
            case 6:
                res = 'n';
                break;
        }

    }
    return 0;
}
