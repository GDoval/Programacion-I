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
    int estado;
    int sueldo;
    int cantHoras;
}eProgramador;

typedef struct{
    int id;
    char desc[20];
    int valorPorHora;
}eCategoria;
void programadorDefault(eProgramador[], int);
void imprimirProg (eProgramador[], eCategoria[]);
void categoria (eCategoria[], int);
/*void mostrarProgramador(eProgramador);
int validaChar(char);
void inicializarVector(eProgramador[], int);
void mostrarProgramadores (eProgramador[], int);
void ingresarProgramador(eProgramador[], int);
int buscarVacio (eProgramador[], int );
int buscarProgramador(eProgramador[], int, int);
void sacarEnter(char[]);
void bajaProgramador (eProgramador[], int, int);*/


//a = Senior
//b = SemiSenior
//c = Junior

int menu();

int main()
{
    eProgramador equipo[TAM];
    //inicializarVector(equipo,TAM);
    //int salir = 1;
    eCategoria listaCategoria[3];
    programadorDefault(equipo, 3);
    categoria(listaCategoria, 3);
    imprimirProg(equipo,listaCategoria);
    /*for (int i = 0; i < 3; i++)
        printf("%s, %d %d\n", equipo[i].nombre, equipo[i].id, equipo[i].categoria);
    printf("\n-------------------------------------\n");
    for (int i = 0; i < 3; i++)
        printf("\n%d %s $%d\n", listaCategoria[i].id , listaCategoria[i].desc, listaCategoria[i].valorPorHora);*/
    /*do{
        switch(menu()){

    case 1:
        system("cls");
        printf("Opcion1\n");
        //ingresarProgramador(equipo, TAM);
        getch();
        break;

    case 2:
        system("cls");
        printf("Opcion2");
        getch();


        break;
    case 3:
        system("cls");
        printf("Opcion3");
        getch();

        break;

    case 4:
        system("cls");
        printf("Opcion4\n\n");
        //mostrarProgramadores(equipo, TAM);
        getch();
        break;



    case 5:
      salir = 0;



        break;

        }

    }while(salir);*/
    return 0;
}


    /*int menu(){
        int opcion;
        system("cls");
        printf("\n***Programadores***\n\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Listado Programadores\n");
        printf("5- Salir\n");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        return opcion;

    }*/

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
                lista[1].cantHoras = 20;

            case 2:
                lista[2].categoria = 80;
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
                }

            }


        }

    printf("\n------------------------");
    printf("\n\nNombre\tCategoria\tSueldo\n\n");
}
