#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

typedef struct{

    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];

}S_LogEntry;

typedef struct
{
    int id;
    char name[33];
    char email[65];
}S_Service;

S_LogEntry* log_constructor();


FILE* abrir_archivo(char*);

int parse_Log(ArrayList*);

S_LogEntry* log_constructor();

S_Service* constructor_service();

int parse_sistema(ArrayList* );

void imprimir(ArrayList*);

void imprimir_service(ArrayList*);

void set_Name(S_Service*, char*);

void set_Mail(S_Service*, char*);

void generar_reporte(ArrayList* , ArrayList*);



