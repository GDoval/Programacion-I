#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parse.h"
int main()
{
    FILE* pLista;
    FILE* pListaNegra;
    ArrayList* lista = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* definitiva;
    definitiva = lista->clone(lista);
    int opcion;
    char resp = 's';
    char auxNom[100];
    char auxMail[150];
    pLista = fopen("destinatarios.csv", "r");
    pListaNegra = fopen("black_list.csv", "r");
    parseLista(pListaNegra, listaNegra);
    parseLista(pLista, lista);
    definitiva = lista->clone(lista);
    nuevaLista(definitiva, listaNegra);
    //imprimir(definitiva);
    return 0;
}
