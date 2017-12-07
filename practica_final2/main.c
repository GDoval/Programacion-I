#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parse.h"


int main()
{
    ArrayList* artistas = al_newArrayList();
    parse_artista(artistas);
    imprimir_artistas(artistas);
    return 0;
}
