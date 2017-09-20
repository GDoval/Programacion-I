#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 3

typedef struct{
    int id;
    char nombre[20];
    int categoria;
    int proyecto;
    int estado;                         // Hacer todas estas funcionaes:
    int sueldo;                       //Mostrar todos los programadores semisenior
    int cantHoras;                    //Mostrar el monto total de sueldos a pagar para los progomadores junior
}eProgramador;                        //La/s categoria/s que tengan menos programadores/ hacerlo pensando en 50 categorias.

typedef struct{
    int id;
    char desc[20];
    int valorPorHora;
}eCategoria;
void programadorDefault(eProgramador[], int);
void imprimirProg (eProgramador[], eCategoria[]);
void categoria (eCategoria[], int);
int menu();

int main()
{
    eProgramador equipo[TAM];
    eCategoria listaCategoria[3];
    programadorDefault(equipo, 3);
    categoria(listaCategoria, 3);
    imprimirProg(equipo,listaCategoria);


    return 0;
}

void programadorDefault(eProgramador lista[], int tam)
{
    for (int i = 0; i < 3; i++)
    {
        switch (i){
            case 0:
                lista[0].categoria = 80;
                strcpy(lista[0].nombre, "Pepe");
                lista[0].estado = 1;
                lista[0].id = 1;
                lista[0].proyecto = 15;
                lista[0].cantHoras = 10;

            case 1:
                lista[1].categoria = 80;
                strcpy(lista[1].nombre, "Juan");
                lista[1].estado = 1;
                lista[1].id = 2;
                lista[1].proyecto = 20;
                lista[1].cantHoras = 50;

            case 2:
                lista[2].categoria = 70;
                strcpy(lista[2].nombre, "Luis");
                lista[2].estado = 1;
                lista[2].id = 3;
                lista[2].proyecto = 40;
                lista[2].cantHoras = 10;


        }
    }
}

void categoria (eCategoria cate[], int tam)
{
    for (int i = 0; i < tam; i++)
    switch(i){
        case 0:
            cate[0].id = 70;
            cate[0].valorPorHora = 50;
            strcpy(cate[0].desc, "Junior");
        case 1:
            cate[1].id = 75;
            cate[1].valorPorHora = 75;
            strcpy(cate[1].desc, "SemiSenior");
        case 2:
            cate[2].id = 80;
            cate[2].valorPorHora = 100;
            strcpy(cate[2].desc, "Senior");

    }
}


void imprimirProg(eProgramador lista[], eCategoria cate[])
{
    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                if (lista[i].categoria == cate[j].id)
                {
                    lista[i].sueldo = lista[i].cantHoras * cate[j].valorPorHora;
                    printf("\n%s\t%s\t\t%d\n", lista[i].nombre, cate[j].desc, lista[i].sueldo);
                    break;
                }
            }
        }

    printf("\n--------------------------------");
    printf("\n\nNombre\tCategoria\tSueldo\n\n");
}
