#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
