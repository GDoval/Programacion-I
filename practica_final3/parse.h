#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[100];
    char apellido[100];
    long int dni;
}eCliente;

typedef struct
{
    int id_venta;
    int id_cliente;
    int codProducto;
    int cantidad;
    int precioUnitario;
}eVentas;


eCliente* constructor_clientes();
FILE* abrir_archivo(char* );
eVentas* constructor_ventas();
void imprimir_clientes(ArrayList*);
void parse_clientes(ArrayList*);
void parsear_ventas(ArrayList*);
void sacarEnter(char[]);
void crea_txt_cliente(ArrayList*, FILE*);
void devuelve_apellido(char[]);
void devuelve_nombre(char []);
long int devuelve_dni();
void modifica_clientes(ArrayList*, int, long int, char[], char[]);
