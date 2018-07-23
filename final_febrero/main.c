#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    ArrayList* listaClientes = al_newArrayList();
    ArrayList* clonadaClientes = al_newArrayList();
    ArrayList* listaVentas = al_newArrayList();
    char seguir = 's';
    int opcion, validar;
    char nombre[100], apellido[100];
    long dni;
    char fecha[50];
    while (seguir == 's')
    {
        system("cls");
        printf("1) Ingresar cliente");
        printf("\n2) Modificar cliente");
        printf("\n3) Baja de cliente");
        printf("\n4) Listar clientes");
        printf("\n5) Importar clientes");
        printf("\n6) Realizar venta");
        printf("\n7) Generar informe de venta por producto");
        printf("\n8) Generar informe de venta por fecha");
        printf("\n9) Producto con mayor numero de ventas");
        printf("\n10) Cliente que mas cantidad compro");
        printf("\n11) Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            devuelve_nombre(nombre);
            devuelve_apellido(apellido);
            printf("\nIngrese el DNI del cliente: ");
            scanf("%ld", &dni);
            validar = buscarRepetido(listaClientes, dni);
            if(validar != 1)
                agregar_cliente(listaClientes, nombre, apellido, dni);
            else
                printf("\nEl DNI ingresado ya se encuentra en la base de datos\n");
            break;
        case 2:
            break;
        case 3:
            system("cls");
            printf("\nIngrese el DNI del cliente a eliminar: ");
            scanf("%d",&dni);
            baja_cliente(listaClientes, dni);
            break;
        case 4:// Funciona bien
            clonadaClientes = listaClientes->clone(listaClientes);
            clonadaClientes->sort(clonadaClientes, ordenarPorApellido,1);
            imprimir_clientes(clonadaClientes);
            break;
        case 5:
            parsear_cliente(listaClientes);
            break;
        case 6:
            system("cls");
            printf("Ingrese ID del cliente: ");
            scanf("%d", &validar);
            cargarVenta(validar, listaVentas);
            break;
        case 7:
            listaVentas->sort(listaVentas, ordenarVentasPrecio, 1);
            crea_txt_ventas(listaVentas, listaClientes);
            break;
        case 8:
            listaVentas->sort(listaVentas, ordenarVentasPrecio, 1);
            printf("Ingrese fecha para generar el reporte: DD/MM/YY: ");
            setbuf(stdin, NULL);
            fgets(fecha, 51, stdin);
            sacarEnter(fecha);
            crea_txt_ventasFecha(listaVentas, listaClientes,fecha);
            break;
        case 9:
            informarMayorVentaProducto(listaVentas);
            break;
        case 10:
            break;
        case 11:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
