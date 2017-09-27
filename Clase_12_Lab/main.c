#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int id;
    char nombre[50];
    int categoria;
    int estado;
    int sueldo;
}eProgramador;

typedef struct
{
    int idProyec;
    char desc[50];
    int horas;
} eProyecto;

typedef struct
{
    int idProg;
    int idProyec;
    int horasTrabajadas;
} eProgProy;



void programadorDefault(eProgramador[], int);
void proyectoDefault(eProyecto[], int);
void progProyDefault(eProgProy[], int);
int buscarProgramador(eProgramador[], int, char[]);


int main()
{
    eProgramador equipo[4];
    eProyecto proyectos[4];
    eProgProy listado[7];
    char nombre[20];
    int idProg;
    programadorDefault(equipo, 4);
    proyectoDefault(proyectos, 4);
    progProyDefault(listado, 7);
    printf("Ingrese el nombre del programador: ");
    setbuf(stdin, NULL);
    gets(nombre);
    idProg = buscarProgramador(equipo, 5, nombre);
    if (idProg == -1)
    {
        printf("\n No se encontro al programador.");
    }else
    {
        printf("\nEl ID del programador %s es %d ", nombre, idProg);
    }
    for (int i = 0; i < 7; i++)
    {
        if (idProg == listado[i].idProg)
        {
            printf("\nEl programador %s trabaja en el proyecto %d\n", nombre, listado[i].idProyec);
        }
    }
    return 0;
}



int buscarProgramador(eProgramador lista[], int tam, char nombre[])
{
    int id = -1;
    for (int i = 0; i < tam +1; i++)
    {
        if (strcmp(lista[i].nombre, nombre) == 0)
        {
            id = i;
            break;
        }
    }
    return id;
}

void programadorDefault(eProgramador lista[], int tam) // Corregir para que no quede el ID en 0. No hacer un switch
{
    for (int i = 0; i < tam; i++)
    {
        switch (i){
            case 0:
                lista[0].categoria = 70;
                strcpy(lista[0].nombre, "Pepe");
                lista[0].estado = 1;
                lista[0].id = 0;

            case 1:
                lista[1].categoria = 70;
                strcpy(lista[1].nombre, "Juan");
                lista[1].estado = 1;
                lista[1].id = 1;

            case 2:
                lista[2].categoria = 80;
                strcpy(lista[2].nombre, "Gaston");
                lista[2].estado = 1;
                lista[2].id = 2;

            case 3:
                lista[3].categoria = 80;
                strcpy(lista[3].nombre, "Roberto");
                lista[3].estado = 1;
                lista[3].id = 3;

            case 4:
                lista[4].categoria = 80;
                strcpy(lista[4].nombre, "Luis");
                lista[4].estado = 1;
                lista[4].id = 4;


        }
    }
}

void proyectoDefault(eProyecto proyecto[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        switch (i){
            case 0:
                proyecto[0].idProyec = 10;
                strcpy(proyecto[0].desc, "SS.Gestion");
            case 1:
                proyecto[1].idProyec = 11;
                strcpy(proyecto[1].desc, "AFIP");
            case 2:
                proyecto[2].idProyec = 12;
                strcpy(proyecto[2].desc, "ARBA");
            case 3:
                proyecto[3].idProyec = 13;
                strcpy(proyecto[3].desc, "Web Service");

        }
    }
}

void progProyDefault(eProgProy listado[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        switch (i){
            case 0:
                listado[0].idProyec = 11;
                listado[0].idProg = 1;
            case 1:
                listado[1].idProyec = 13;
                listado[1].idProg = 3;
            case 2:
                listado[2].idProyec = 10;
                listado[2].idProg = 2;
            case 3:
                listado[3].idProyec = 13;
                listado[3].idProg = 2;
            case 4:
                listado[4].idProyec = 10;
                listado[4].idProg = 1;
            case 5:
                listado[5].idProyec = 12;
                listado[5].idProg = 1;
            case 6:
                listado[6].idProyec = 11;
                listado[6].idProg = 2;
        }
    }
}
