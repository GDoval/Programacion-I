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
        return 1;
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
    printf("ID     Nombre     Mail\n\n ");
    for (int i = 0; i < lista->size; i++)
    {
        persona = (ePersona*)lista->get(lista, i);
        printf("%s       %s\n",persona->nombre, persona->mail);
    }
}


ArrayList* nuevaLista (ArrayList* lista, ArrayList* listaNegra)
{
    if (lista == NULL || listaNegra == NULL)
        return NULL;
    int resp;
    ePersona* aux;
    ePersona* aux2;
    for (int i = 0; i < lista->size; i++) // indice de la lista
    {
        aux = lista->get(lista, i);
        for (int j = i+1; j < lista->size; j++) // indice de la black_list
        {
            aux2 = listaNegra->get(listaNegra, j);
            resp = compararMails(aux->mail, aux2->mail);
            if (resp)
            {
                lista->remove(lista, i);
                break;
            }
        }
    }
    return lista;
}
