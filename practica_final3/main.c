#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parse.h"

int main()
{
    ArrayList* clientes = al_newArrayList();
    ArrayList* ventas = al_newArrayList();
    /*parse_clientes(clientes);
    imprimir_clientes(clientes);*/
    parsear_ventas(ventas);
    imprimir_ventas(ventas);
    return 0;
}
