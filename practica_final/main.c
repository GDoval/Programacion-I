#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

int main()
{
    FILE* archivo;
    ArrayList* listaArray = al_newArrayList();
    parse_Log(listaArray);
    imprimir(listaArray);
    return 0;
}
