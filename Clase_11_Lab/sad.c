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
int validaChar(char);
void inicializarVector(eProgramador[], int);
void mostrarProgramadores (eProgramador[], int);
void ingresarProgramador(eProgramador[], int);
int buscarVacio (eProgramador[], int );
int buscarProgramador(eProgramador[], int, int);
void sacarEnter(char[]);
void bajaProgramador (eProgramador[], int, int);


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
    char cat[11];
    if (programador.categoria == 'a')
        strcpy(cat, "Senior");
    if (programador.categoria == 'b')
        strcpy(cat, "SemiSenior");
    if (programador.categoria == 'c')
        strcpy(cat, "Junior");
    printf("%d\t%s\t%s\t%d ", programador.id,  programador.nombre, cat, programador.proyecto);
}

void mostrarProgramadores (eProgramador lista[], int tam)
{
    int flag = 0;
    printf("ID\tNombre\tCategoria\tProyecto \n\n");
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
    int comodin, validaCate;
    char categoria;
    posicion = buscarVacio(ingreso, tam);
    if (posicion != -1)
    {
        printf("Ingrese ID del programador: ");
        scanf("%d", &comodin);
        validaId = buscarProgramador(ingreso, comodin, tam);
        if (validaId == -1)
        {
            printf("Ese ID ya se encuentra cargado.");
            return;
        }
        ingreso[posicion].id = comodin;
        printf("Ingrese nombre del programador: ");
        setbuf(stdin, NULL);
        fgets(ingreso[posicion].nombre, 20, stdin);
        sacarEnter(ingreso[posicion].nombre);
        //setbuf(stdin, NULL);
        printf("Ingrese categoria del programador: a-Senior, b-SemiSenior, c-Junior: ");
        //setbuf(stdin, NULL);
        fflush(stdin);
        categoria = getchar();
       // scanf("%c", &categoria);
       // validaCate =;
        while ( validaChar(categoria) == -1)
        {
            //setbuf(stdin, NULL);
          //  fflush(stdin);
            printf("\nError. Ingrese categoria del programador: a-Senior, b-SemiSenior, c-Junior:");
            fflush(stdin);
            //setbuf(stdin, NULL);
            //scanf("%c", &categoria);
            categoria = getchar();

           // validaCate = validaChar(categoria);
        }
        ingreso[posicion].categoria = categoria;
        printf("Ingrese proyecto: ");
        scanf("%d", &ingreso[posicion].proyecto);
        ingreso[posicion].estado = 1;
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



void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}


int validaChar(char posicion)
{
    int resultado = -1;
    if (posicion == 'a' || posicion == 'b' || posicion == 'c')
    {
        resultado = 5;
    }
    return resultado;
}

/*void bajaProgramador (eProgramador lista[], int tam, int id)
{
    int esta;
    esta = buscarProgramador(lista, id, tam);
    if (esta == -1)
    {
        printf("El ID ingresado no existe");
    }else
    {
        mostrarProgramador(lista[]);
    }
}
*/
