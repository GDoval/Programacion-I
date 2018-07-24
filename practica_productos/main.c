#include <stdio.h>
#include <stdlib.h>
#include "producto.h"

int main()
{
    eProducto* produ = (eProducto*)malloc(sizeof(eProducto));
    produ->codigo = 12;
    produ->precio = 10.5;
    eProducto* produ2 = (eProducto*)malloc(sizeof(eProducto));
    produ2->codigo = 87;
    produ2->precio = 54.5;
    lista_borrarLista();
    lista_setProducto(produ, 0);
    lista_setProducto(produ2, 1);
    eProducto* aux;
    aux = lista_getMasCaro();
    printf("%f", aux->precio);
    return 0;
}
