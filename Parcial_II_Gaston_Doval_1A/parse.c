#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parse.h"

ePersona* persona_constructor()
{
    ePersona* aux;
    aux = (ePersona*) malloc(sizeof(ePersona));
    if (aux != NULL)
    {
        strcpy(aux->nombre, "");
        strcpy(aux->mail, "");
    }
    return aux;
}


int compararMails (void* mailUno, void* mailDos)
{
    if (strcmp(((ePersona*)mailUno)->mail, ((ePersona*)mailDos)->mail) == 0)
        return 0;
    return -1;
}


int parseLista (FILE* lista, ArrayList* arrayLista)
{
    if (lista == NULL || arrayLista == NULL)
        return -1;
    char auxNom[100];
    char auxMail[150];
    ePersona* nuevaPersona;
    while (!feof(lista))
    {
        fscanf(lista, "%[^,],%s \n", auxNom, auxMail);
        nuevaPersona = persona_constructor();
        if (nuevaPersona != NULL)
        {
            strcpy(nuevaPersona->nombre, auxNom);
            strcpy(nuevaPersona->mail, auxMail);
        }
        arrayLista->add(arrayLista, nuevaPersona);
    }
    return 0;
}



void imprimir(ArrayList* lista)
{
    ePersona* persona;
    printf("Nombre          Mail\n\n");
    for (int i = 0; i < lista->len(lista); i++)
    {
        persona = (ePersona*)lista->get(lista, i);
        printf("%s       %s\n\n",persona->nombre, persona->mail);
    }
}


int nuevaLista (ArrayList* lista, ArrayList* listaNegra, ArrayList* definitiva)
{
    if (lista == NULL || listaNegra == NULL || definitiva == NULL)
        return -1;
    ePersona* aux;
    ePersona* aux2;
    int flag = 1;
    int r;
    for (int i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        flag = 1;
        for (int j = 0; j < listaNegra->len(listaNegra); j++)
        {
            aux2 = listaNegra->get(listaNegra, j);
            r = compararMails(aux, aux2);
            if (r == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            definitiva->add(definitiva, aux);
        }
    }
    return 0;
}



void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}




