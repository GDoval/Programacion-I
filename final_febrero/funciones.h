#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TV12 108.52
#define CPU32 500.12
#define LV87 45.25

typedef struct
{
    char nombre[100];
    char apellido[100];
    long dni;
    int id;
    int estado;
}eCliente;


typedef struct
{
    float costoUnitario;
    int cantidad;
    char fecha[50];
    int estado;
    int idCliente;
    char codigoProducto[100];
}eVentas;

int ordenarPorApellido (void* cliente, void* cliente2);
int ordenarVentasPrecio(void* venta1, void* venta2);
