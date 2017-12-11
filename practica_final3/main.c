#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parse.h"

int main()
{
    ArrayList* clientes = al_newArrayList();
    ArrayList* ventas = al_newArrayList();
    parse_clientes(clientes);
    parsear_ventas(ventas);
    FILE* archivo;
    FILE* copia;
    char nombre[100];
    char apellido[100];
    int id, dni, len;
    eCliente* aux;
    int opcion;
    char resp = 's';
    while (resp == 's')
    {
        printf("1) Agregar nuevo cliente\n");
        printf("2) Modificar cliente\n");
        printf("3) Baja de cliente\n");
        printf("4) Listar clientes\n");
        printf("5) Procesar venta\n");
        printf("6) Anular venta\n");
        printf("7) Informar ventas\n");
        printf("8) Informar ventas por producto\n");
        printf("9) Generar informe de ventas\n");
        printf("10) Informar cantidad ventas por cliente\n");
        printf("11) Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            len = clientes->len(clientes);
            aux = clientes->get(clientes, len-1);
            id = aux->id;
            devuelve_nombre(nombre);
            devuelve_apellido(apellido);
            printf("\nIngrese DNI del cliente: ");
            scanf("%d", &dni);
            archivo = abrir_archivo("clientes.txt");
            rewind(archivo);
            fseek(archivo, 0L, SEEK_END);
            fprintf(archivo, "%d,%s,%s,%d\n", id+1, nombre, apellido, dni);
            fclose(archivo);
            break;
        case 2:
            system("cls");
            printf("Ingrese DNI del cliente: ");
            scanf("%d", &dni);
            devuelve_apellido(apellido);
            devuelve_nombre(nombre);
            abrir_archivo("clientes.txt");
            int i;
            for (i = 0; i < clientes->len(clientes); i++)
            {
                aux = clientes->get(clientes, i);
                if (aux->id == id)
                {
                    strcpy(aux->apellido, apellido);
                    strcpy(aux->nombre, nombre);
                    clientes->set(clientes, i+1, aux);
                    break;
                }
            }
            abrir_archivo("clientes2.txt");

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            resp = 'n';
            break;
        default:
            resp = 'n';
            break;
        }
    }
    return 0;
}
