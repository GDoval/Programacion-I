#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 3

typedef struct{
    int id;
    char nombre[20];
    char categoria;
    int proyecto;
    int estado;
}
eProgramador;
void mostrarProgramador(eProgramador);
void inicializarVector(eProgramador[], int);
void mostrarProgramadores (eProgramador[], int);
void ingresarProgramador(eProgramador[], int);
int buscarVacio (eProgramador[], int );
int buscarProgramador(eProgramador[], int, int);


//a = Senior
//b = SemiSenior
//c = Junior

int menu();

int main()
{
    eProgramador equipo[TAM];
    inicializarVector(equipo,TAM);
    int salir = 1;

    do{
        switch(menu()){

    case 1:
        system("cls");
        printf("Opcion1\n");
        ingresarProgramador(equipo, TAM);
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
        mostrarProgramadores(equipo, TAM);
        getch();
        break;



    case 5:
      salir = 0;



        break;

        }

    }while(salir);
    return 0;
}


    int menu(){
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

    }


void inicializarVector(eProgramador ini[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        ini[i].estado = 0;
    }
}

void mostrarProgramador(eProgramador programador)
{
    char cate[20];
    switch(programador.categoria)
    {
    case 'a':
        strcpy(cate, "Senior");
    case 'b':
        strcpy(cate, "SemiSenior");
    case 'c':
        strcpy(cate, "Junior");

    }
    printf("ID\tNombre\tCategoria\tProyecto \n\n");
    printf("%d\t%s\t%s\t%d ", programador.id,  programador.nombre, cate, programador.proyecto);
}

void mostrarProgramadores (eProgramador lista[], int tam)
{
    int flag = 0;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].estado != 0)
        {
            flag = 1;
            mostrarProgramador(lista[i]);
            printf("\n");
        }

    }
        if (flag == 0)
            printf("\nNo hay programadores para mostrar");


}


void ingresarProgramador(eProgramador ingreso[], int tam)
{
    int posicion, validaId;
    int comodin;
    posicion = buscarVacio(ingreso, tam);
    printf("%d\n", posicion);
    if (posicion != -1)
    {
        ingreso[posicion].estado = 1;
        printf("Ingrese ID del programador: ");
        scanf("%d", &comodin);
        validaId = buscarProgramador(ingreso, comodin, tam);
        printf("%d\n", validaId);
        if (validaId == -1)
        {
            printf("Ese ID ya se encuentra cargado.");
            return;
        }
        ingreso[posicion].id = comodin;
        printf("Ingrese nombre del programador: ");
        setbuf(stdin, NULL);
        fgets(ingreso[posicion].nombre, 20, stdin);
        printf("Ingrese categoria del programador: a = Senior, b=SemiSenior, c=Junior: ");
        scanf("%c", &ingreso[posicion].categoria);
        while (ingreso[posicion].categoria != 'a' && ingreso[posicion].categoria != 'b' && ingreso[posicion].categoria != 'c')
        {
            printf("\nError. Por favor ingrese categoria del programador: a = Senior, b=SemiSenior, c=Junior: ");
            setbuf(stdin, NULL);
            scanf("%c", &ingreso[posicion].categoria);
            setbuf(stdin, NULL);
        }
        printf("Ingrese proyecto: ");
        scanf("%d", &ingreso[posicion].proyecto);
    }else
    {
        printf("\n No hay lugar en el sistema\n");
    }


}

int buscarVacio (eProgramador listado[], int tam)
{
    int resultado = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listado[i].estado == 0)
        {
            resultado = i;
            return resultado;
        }
    }
    return resultado;
}


int buscarProgramador(eProgramador listado[], int id, int tam)
{
    int resultado = 5;
    for (int i = 0; i < tam; i++)
    {
        if (listado[i].id == id && listado[i].estado == 1)
        {
            resultado = -1;
            break;
        }
    }
    return resultado;
}
