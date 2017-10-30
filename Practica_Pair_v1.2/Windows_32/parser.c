#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/*Trae los campos que estan en el archivo .csv y los pasa adentro del ArrayList. Recibe un puntero al archivo,
que se abre fuera de la funcion, y un puntero al ArrayList, que se crea en el main(). Como el scanf() lee solo texto
se tienen que hacer buffers de tipo char para guardar los campos del archivo. Esos buffer se parsean al tipo de datos
que corresponde, y esos son los valores que se guardan en el ArrayList.
*/
int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char auxInt[10];
    char auxNombre[51];
    char auxApellido[51];
    char auxEmpty[10];
    Employee* nuevoEmpleado; // Crea una variable de tipo puntero para guardar despues la direccion de memoria que devuelve la funcion new_Employee()

    if(pFile == NULL || pArrayListEmployee == NULL){ //si no pudo abrir alguno de los punteros sale de la funcion
            return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty); // descarta la primer linea del archivo xq tiene basura

    while(!feof(pFile)){
         fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

         nuevoEmpleado = employee_new(); // se guarda espacio en memoria para la estructura que se va a guardar en el ArrayList

         if(nuevoEmpleado !=NULL){                          //Aca se parsean los buffer
            nuevoEmpleado->id = atoi(auxInt);
            strcpy(nuevoEmpleado->name, auxNombre);
            strcpy(nuevoEmpleado->lastName, auxApellido);
            if(strcmp(auxEmpty, "false")== 0){
                nuevoEmpleado->isEmpty = 0;
            }
            else{
                nuevoEmpleado->isEmpty = 1;
            }

            pArrayListEmployee->add(pArrayListEmployee, nuevoEmpleado); // aca se agregan al ArrayList

            }

         }

    return 0;
}
