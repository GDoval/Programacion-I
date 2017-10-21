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
#define TAM_AUTOS 4
#define TAM_DUENIOS 4


int main()
{
    char res ='s';
    int opcion, validar, id, horario;
    char patente[8];
    eDuenio clientes[TAM_DUENIOS] = {{1,"Gaston Doval", "Evergreen 255", 1564891,1}, {2, "Pepe Aramado", "Calle 123", 4578748, 1},{3,"Juan Perez", "OtraCalle 456 ", 897747,1}, {4, "Rope Lope", "Ortuzarabal 6741", 6548741, 1}};
    eAlquiler autos[TAM_AUTOS] = {{"JKO 987", 3, 1, 16,18, 1}, {"ZBC 123", 2, 2, 16, 22,1}, {"BCA 984", 3, 3, 15, 18, 1}, {"UPB 147", 4, 4, 15,24, 1}};
    eAlquiler autosOrdenados[TAM_AUTOS];
    /*for (int i = 0; i < TAM_DUENIOS; i++)
    {
        clientes[i].estado = 0;
        clientes[i].idDuenio = 0;

    }*/
    for (int i = 0; i < TAM_AUTOS; i++)
    {
        //autos[i].estado = 0;
        autos[i].horarioSalida = 0;
    }


    while (res == 's')
    {
        printf("1) Ingrese duenio");
        printf("\n2) Ingrese autos");
        printf("\n3) Modificar tarjeta de credito");
        printf("\n4) Imprimir auris");
        printf("\n5) Imprimir listado de autos estacionados con sus dueños");
        printf("\n6) Calcular estadia");
        printf("\n7) Calcular total por marca");
        printf("\n8) Calcular total del estacionamiento");
        printf("\n9) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                system("clear");
                ingresoDuenio(clientes, TAM_DUENIOS);
                break;
            case 2:
                system("clear");
                ingresoAuto(autos, clientes, TAM_AUTOS, TAM_DUENIOS);
                break;

            case 3:
                system("clear");
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
                system("clear");
                imprimirAudi(autos, clientes, TAM_AUTOS, TAM_DUENIOS);
                break;
            case 5:
                system("clear");
                for (int  i = 0; i < TAM_AUTOS; i++)
                {
                    autosOrdenados[i] = autos[i];
                }
                ordenarAutosHorario(autosOrdenados, TAM_AUTOS);
                imprimirListado(clientes, autosOrdenados, TAM_DUENIOS, TAM_AUTOS);
                printf("\n\n");
                break;
            case 6:
                system("clear");
                printf("Ingrese patente del auto: ");
                setbuf(stdin, NULL);
                fgets(patente, 15, stdin);
                sacarEnter(patente);


                printf("\nIngrese el horario de salida: ");
                scanf("%d", &horario);
                validar = validaInt(horario,0, 24);
                while (validar == -1)
                {
                    printf("\nError! Por favor ingrese un horario entre 1 y 24: ");
                    scanf("%d", &horario);
                    validar = validaInt(horario,1,24);
                }
                calcularEstadia(clientes, autos, TAM_AUTOS, TAM_DUENIOS, patente, horario);
                break;

            case 7:
                system("clear");
                totalPorMarca(autos, TAM_AUTOS);
                break;
            case 8:
                system("clear");
                totalEstacionamiento(autos, TAM_AUTOS);
                break;
            case 9:
                res = 'n';
                break;
        }

    }
    return 0;
}
