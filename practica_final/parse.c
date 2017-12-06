#include "parse.h"
#include "ArrayList.h"


int parse_Log(ArrayList* lista)
{
    FILE* archivo;
    char auxDate[110];
    char auxTime[60];
    char AuxServiceId[100];
    char AuxGravedad[100];
    char AuxMsg[650];
    archivo = fopen("log.txt", "r");// falta validar que no sea NULL
    S_LogEntry* nuevoLog;
    while(!feof(archivo))
    {   //Funciona bien, la ultima mascara lee todo hasta el salto de pagina
        fscanf(archivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", auxDate, auxTime, AuxServiceId, AuxGravedad, AuxMsg);
        nuevoLog = log_constructor();
        if (nuevoLog != NULL) //faltaria usar los setters
        {
            strcpy(nuevoLog->date, auxDate);
            strcpy(nuevoLog->time, auxTime);
            nuevoLog->gravedad = atoi(AuxGravedad);
            nuevoLog->serviceId = atoi(AuxServiceId);
            strcpy(nuevoLog->msg, AuxMsg);
        }
        lista->add(lista, nuevoLog);
    }
    fclose(archivo);
}


S_LogEntry* log_constructor()
{
    S_LogEntry* aux;
    aux = (S_LogEntry*) malloc(sizeof(S_LogEntry));
    if (aux != NULL)
    {
        strcpy(aux->date, "");
        strcpy(aux->msg, "");
        strcpy(aux->time, "");
        aux->gravedad = 0;
        aux->serviceId = 0;
    }
    return aux;
}


S_Service* constructor_service()
{
    S_Service* aux;
    aux = (S_Service*) malloc(sizeof(S_Service)); //el sizeof es del tamaño de la estructura, no del puntero a estructura
    if (aux != NULL)                              //Lo que se castea es lo que devuelve malloc()
    {
        aux->id = 0;
        strcpy(aux->email, "");
        strcpy(aux->name, "");
    }
    return aux;
}


int parse_sistema(ArrayList* lista)
{
    FILE* archivo;
    char auxId[100];
    char auxEmail[100];
    char auxName[100];
    S_Service* auxiliar;
    archivo = fopen("service.txt", "r"); // falta validar que no sea NULL archivo
    while (!feof(archivo))
    {
        fscanf(archivo,"%[^;];%[^;];%[^\n]\n", auxId, auxEmail, auxName);
        auxiliar =constructor_service();
        if (auxiliar != NULL)
        {
            auxiliar->id = atoi(auxId);
            set_Name(auxiliar, auxName);
            set_Mail(auxiliar, auxEmail);
        }
        lista->add(lista, auxiliar);
    }
    fclose(archivo);
}


void imprimir(ArrayList* lista)
{
    S_LogEntry* log;
    int i;
    for (i = 0; i < lista->len(lista); i++)
    {
        log = lista->get(lista, i);
        printf("%s   %s   %d   %d   %s \n", log->date, log->time, log->serviceId, log->gravedad, log->msg);
    }
}


void imprimir_service(ArrayList* lista)
{
    S_Service* service;
    int i;
    for (i = 0; i < lista->len(lista); i++)
    {
        service = lista->get(lista, i);
        printf("%d     %s     %s\n", service->id, service->email, service->name);
    }
}

void set_Name(S_Service* persona, char* nombre)
{
    strcpy(persona->name, nombre);
}


void set_Mail(S_Service* persona, char* mail)
{
    strcpy(persona->email, mail);
}
