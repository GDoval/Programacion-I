#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    Employee* aux;
    char id[500], name[500], lastName[500], isEmpty[500];
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName, isEmpty);
    int id;
    id = atoi(id);
    aux->id = id;
    strcpy(aux->name, name);
    strcpy(aux->lastName, lastName);
    if (strcmp(isEmpty, "true") == 0)
    {
        aux->isEmpty = 1;
    }else
    {
        aux->isEmpty = 0;
    }
    return 0;
}
