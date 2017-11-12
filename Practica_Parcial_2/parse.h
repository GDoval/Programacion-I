#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nombre[100];
    char mail[150];
}ePersona;



int parseLista (FILE*, ArrayList* );

void nuevaLista (ArrayList*, ArrayList*, ArrayList*);

void imprimir(ArrayList*);
