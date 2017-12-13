#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parse.h"


int main()
{
    ArrayList* clientes = al_newArrayList();
    ArrayList* ventas = al_newArrayList();
    ArrayList* clonada;
    parse_clientes(clientes);
    parsear_ventas(ventas);
    FILE* archivo;
    FILE* copia;
    char nombre[100];
    char apellido[100];
    int id, len, codigo, cantidad, idV;
    int flag, flag2, indice;
    long int dni;
    float precio;
    eCliente* aux;
    eVentas* auxV;
    int opcion;
    char resp = 's';
    while (resp == 's')
    {
        system("cls");
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
            dni = devuelve_dni();
            archivo = abrir_archivo("clientes.txt");
            rewind(archivo);
            fseek(archivo, 0L, SEEK_END);
            fprintf(archivo, "%d,%s,%s,%li\n", id+1, nombre, apellido, dni);
            fclose(archivo);
            system("pause");
            break;
        case 2:
            system("cls");
            id = pedir_ID_cliente();
            devuelve_nombre(nombre);
            devuelve_apellido(apellido);
            dni = devuelve_dni();
            modifica_clientes(clientes, id, dni, nombre, apellido);
            copia = abrir_archivo("clientes2.txt");
            crea_txt_cliente(clientes, copia);
            remove("clientes.txt");
            rename("clientes2.txt", "clientes.txt");
            system("pause");
            break;
        case 3:
            system("cls");
            id = pedir_ID_cliente();
            flag = buscar_id_cliente(clientes, id);
            if (flag == 1)
            {
                flag2 = buscar_id_ventas(ventas, id);
                indice = buscar_indice_clientes(clientes, id);
            }
            else
            {
                printf("El ID ingresado no se encuentra en la base de datos\n\n");
            }
            if (flag2 == 1)
            {
                clientes->remove(clientes,indice);
                copia = abrir_archivo("clientes2.txt");
                crea_txt_cliente(clientes, copia);
                remove("clientes.txt");
                rename("clientes2.txt", "clientes.txt");
            }
            else
            {
                printf("No pueden eliminarse clientes que tengan ventas asociadas.\n");
            }
            break;
        case 4:
            system("cls");
            clonada = clientes->clone(clientes);
            clonada->sort(clonada, ordenar_clientes_apellido, 1);
            imprimir_clientes(clonada);
            clonada->deleteArrayList(clonada);
            system("pause");
            break;
        case 5:
            system("cls");
            id = pedir_ID_cliente();
            printf("\nIngrese el codigo del producto: 1000-1001-1002: ");
            scanf("%d", &codigo);
            printf("\nIngrese la cantidad a comprar: ");
            scanf("%d", &cantidad);
            precio = buscar_precio(codigo);
            len = ventas->len(ventas);
            aux = ventas->get(ventas, len-1);
            idV = aux->id;
            archivo = abrir_archivo("ventas.txt");
            rewind(archivo);
            fseek(archivo, 0L, SEEK_END);
            fprintf(archivo, "\n%d,%d,%d,%d,%.2f", idV+1,id, codigo, cantidad,precio);
            fclose(archivo);
            system("pause");
            break;
        case 6:
            system("cls");
            printf("Ingrese el ID de la venta a dar de baja: ");
            scanf("%d", &id);
            flag = buscar_id_ventas(ventas, id);
            if (!flag)
            {
                indice = buscar_indice_ventas(ventas, id);
                ventas->remove(ventas, indice);
                copia = abrir_archivo("ventas2.txt");
                crea_txt_ventas(ventas, copia);
                remove("ventas.txt");
                rename("ventas2.txt", "ventas.txt");
            }else
            {
                printf("\nEl ID ingresado no se encuentra en la base de datos.\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            printf("Venta\tCliente\tProducto\tCantidad\tPrecio\n\n");
            imprimir_ventas(ventas);
            system("pause");
            break;
        case 8:
            system("cls");
            printf("Ingrese codigo del producto: ");
            scanf("%d", &id);
            imprimir_ventas_producto(ventas, id);
            system("pause");
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
    clientes->deleteArrayList(clientes);
    ventas->deleteArrayList(ventas);
    return 0;
}
