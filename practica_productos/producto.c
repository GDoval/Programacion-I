#include "producto.h"

void lista_borrarLista()
{
    int i;
    for(i = 0; i < 100; i++)
    {
        listado[i].flagEstado = 1;
    }
}

eProducto* lista_getProducto(int indice)
{
    if(indice < 0 || indice > 100)
        return NULL;
    eProducto* resp = NULL;
    int i;
    for(i = 0; i < 100;i++)
    {
        if( i == indice && listado[i].flagEstado == 0)
        {
            resp = &listado[i];
            break;
        }
    }
    return resp;
}

int lista_setProducto(eProducto* prod, int indice)
{
    if(indice < 0 || indice > 100)
        return 0;
    int i, resp = 0;
    for(i = 0; i < 100; i++)
    {
        if((indice == i) && listado[i].flagEstado== 1)
        {
            listado[i].codigo = prod->codigo;
            listado[i].precio = prod->precio;
            listado[i].flagEstado = 0;
            resp = 1;
            break;
        }
    }
    return resp;
}

eProducto* lista_getMasCaro()
{
    int i, flag = 0, indice = -1;
    float max = 0;
    eProducto* aux = (eProducto*)malloc(sizeof(eProducto));
    for(i = 0; i < 100; i++)
    {
        if((listado[i].precio > max) && (listado[i].flagEstado == 0)|| flag == 0)
        {
            max = listado[i].precio;
            flag = 1;
            indice = i;
        }
    }
    if( indice != -1)
    {
        aux->precio = listado[indice].precio;
        aux->codigo = listado[indice].codigo;
    }else
    {
        aux = NULL;
    }
    return aux;
}
