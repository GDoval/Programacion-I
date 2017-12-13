#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#define TV_LG_32 8999.99
#define PS4 12999.99
#define IPHONE7 19480.99


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
void imprimir_clientes_ordenado(ArrayList*);
void parse_clientes(ArrayList*);
void parsear_ventas(ArrayList*);
void sacarEnter(char[]);
void crea_txt_cliente(ArrayList*, FILE*);
void devuelve_apellido(char[]);
void devuelve_nombre(char []);
long int devuelve_dni();
void modifica_clientes(ArrayList*, int, long int, char[], char[]);
int buscar_indice_clientes(ArrayList*, int);
int buscar_id_cliente(ArrayList*, int);
int buscar_id_ventas(ArrayList*, int);
int ordenar_clientes_apellido(eCliente*, eCliente*);
int buscar_precio(int);
