#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"


typedef struct
{
    int id;
    char nombre[100];
    char email[100];
    char sexo[100];
    char pais[100];
    char password[100];
    char ip_adress[20];
}eArtista;

typedef struct
{
    int id;
    char nombre_tema[100];
    char artista[100];
}eCanciones;

FILE* abrir_archivo(char*);
