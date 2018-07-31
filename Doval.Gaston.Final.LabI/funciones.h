#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"

typedef struct
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
    int id;
}eLetra;

int es_Vocal(char letra);
ArrayList* remover_Letra(ArrayList* lista, char letra);
