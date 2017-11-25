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
            person_SetMail(nuevaPersona, auxMail);
            person_SetName(nuevaPersona, auxNom);
        }
        arrayLista->add(arrayLista, nuevaPersona);
    }
    return 0;
}

int parseNegra (FILE* lista, ArrayList* origen, ArrayList* listaNegra)
{
    if (origen == NULL || listaNegra == NULL)
        return -1;
    char auxNom[100];
    char auxMail[150];
    ePersona* aux;
    ePersona* aux2;
    ePersona* nuevaPersona;
    int r, f = 0, t;
    int flag;
    while (!feof(lista))
    {
        flag = 1;
        fscanf(lista, "%[^,],%s \n", auxNom, auxMail);
        nuevaPersona = persona_constructor();
        if (nuevaPersona != NULL)
        {
            person_SetMail(nuevaPersona, auxMail);
            person_SetName(nuevaPersona, auxNom);
        }
        for (int i = 0; i < origen->len(origen); i++)
        {
            aux = origen->get(origen, i);
            r = compararMails(nuevaPersona, aux);
            if (r == 0)
            {
                listaNegra->add(listaNegra, aux);
                break;
            }else
            {
                flag = 0;
            }
        }
        if (flag == 0)
        {
            listaNegra->add(listaNegra, nuevaPersona);
        }
    }
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
    int flag;
    int r;
    for (int i = 0; i < lista->len(lista); i++)
    {
        aux = (ePersona*)lista->get(lista, i);
        flag = listaNegra->contains(listaNegra, aux);
        if (flag == 0)
        {
            definitiva->add(definitiva, aux);
        }
    }
    for (int i = 0; i < definitiva->len(definitiva); i++)
    {
        aux = definitiva->get(definitiva, i);
        flag = 1;
        for (int j = 0; j < definitiva->len(definitiva); j++)
        {
            aux2 = definitiva->get(definitiva, j);
            r = compararMails(aux, aux2);
            if (r == 0)
            {
                definitiva->remove(definitiva, j);
                break;
            }
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


void person_SetName(ePersona* persona, char* nombre)
{
    strcpy(persona->nombre, nombre);
}

void person_SetMail(ePersona* persona, char* mail)
{
    strcpy(persona->mail, mail);
}
