#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    if(this !=NULL)
    {
        printf("ID: %d\nNAME: %s\nLAST NAME: %s",this->id,this->name,this->lastName);
    }
    else
    {
        printf("\nThere is nothing to print, dog\n");
        return;
    }
}


Employee* employee_new(void)
                              //Esto es un constructor: devuelve un puntero a una direccion de memoria del tamaño de la
{                             // estructura, e inicializa todos los campos en 0 o en espacio vacio si son string.
                              //Se puede hacer de otra manera: pasarle como parametro los valores con los que se van a completar
                              // los campos de la estructura. O sea, para hardcodear.


    Employee* empleado;
    empleado= (Employee*)malloc(sizeof(Employee));
    if(empleado!=NULL)
    {
        empleado->id=0;
        strcpy(empleado->name, "");
        strcpy(empleado->lastName, "");
        empleado->isEmpty=1;
    }

    return empleado;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


