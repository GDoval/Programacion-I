#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parse.h"

int main()
{
    //FILE* archivo;
    ArrayList* listaArray = al_newArrayList();
    ArrayList* arrayService = al_newArrayList();
    /*parse_Log(listaArray);
    imprimir(listaArray);*/
    /*FILE* archivo;
    char auxId[100];
    char auxEmail[100];
    char auxName[100];
    S_Service* auxiliar;
    S_Service* uno = constructor_service();
    archivo = fopen("service.txt", "r");
    fscanf(archivo, "%[^;];%[^;];%[^\n]\n", auxId, auxEmail, auxName);
    strcpy(uno->name, auxName);
    printf("%s", uno->name);*/
    parse_sistema(arrayService);
    imprimir_service(arrayService);
    return 0;
}
