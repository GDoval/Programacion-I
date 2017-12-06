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
    archivo = fopen("log.txt", "r");
    S_LogEntry* nuevoLog;
    while(!feof(archivo))
    {   //Funciona bien, la ultima mascara lee todo hasta el salto de pagina
        fscanf(archivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", auxDate, auxTime, AuxServiceId, AuxGravedad, AuxMsg);
        nuevoLog = log_constructor();
        if (nuevoLog != NULL)
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
