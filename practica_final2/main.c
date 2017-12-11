#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parse.h"


int main()
{
    ArrayList* artistas = al_newArrayList();
    ArrayList* canciones = al_newArrayList();
    parse_artista(artistas);
    parse_canciones(canciones);
    //imprimir_artistas(artistas);
    imprimir_canciones(canciones);
    return 0;
}
