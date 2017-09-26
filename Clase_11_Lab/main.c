#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct{
    int id;
    char nombre[50];
    int categoria;
    int proyecto;
    int estado;                         // Hacer todas estas funcionaes:
    int sueldo;                       //Mostrar todos los programadores semisenior -- LISTO
    int cantHoras;                    //Mostrar el monto total de sueldos a pagar para los programadores junior -- LISTO
}eProgramador;                        //La/s categoria/s que tengan menos programadores/ hacerlo pensando en 50 categorias.

typedef struct{
    int id;
    char desc[50];
    int valorPorHora;
}eCategoria;




void imprimirProg (eProgramador[], eCategoria[], int);
void categoria (eCategoria[], int);
void sacarEnter(char[]);
void ingresoProgramador (eProgramador[], int);
int buscarVacio (eProgramador[], int);
void imprimirSemi(eProgramador[], eCategoria[], int);
int sueldosJunior (eProgramador[], eCategoria[], int);
void programadorDefault(eProgramador[], int);
void menosProgramadores (eProgramador[], eCategoria[], int, int);


int main()
{
    eProgramador equipo[TAM];
    eCategoria listaCategoria[3];
    categoria(listaCategoria,3);
    int sueldos;
    for (int i = 0; i < TAM; i++)
        equipo[i].estado = 0;
    char opcion = 's';
    int op;
    while (opcion == 's')
    {
        printf("1) Ingrese un programador");
        printf("\n2) Imprimir programadores");
        printf("\n3) Imprimir SemiSeniors");
        printf("\n4) Imprimir Sueldos de los Junior");
        printf("\n5) Imprimir menor cantidad de programadores\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                system("clear");
                ingresoProgramador(equipo, TAM);
                //programadorDefault(equipo, TAM);
                break;
            case 2:
                system("clear");
                imprimirProg(equipo, listaCategoria, TAM);
                break;
            case 3:
                system("clear");
                imprimirSemi(equipo, listaCategoria, TAM);
                break;
            case 4:
                system("clear");
                sueldos = sueldosJunior(equipo, listaCategoria, TAM);
                printf("\nEl sueldo total de los programadores Juniors es: %d\n\n", sueldos);
                break;
            case 5:
                system("clear");
                menosProgramadores(equipo, listaCategoria, TAM, 3);
                break;
            case 6:
                opcion = 'n';
                break;
        }
    }

    return 0;
}

void ingresoProgramador (eProgramador lista[], int tam)
{
    int indice;
    indice = buscarVacio(lista, tam);
    printf("\n\n%d\n\n", indice);
    if (indice != -1)
    {
        system("clear");
        printf("\nIngrese ID del programador: ");
        scanf("%d", &lista[indice].id);

        printf("Ingrese el nombre del programador: "); // aca habria que validar que ingrese un nombre correcto
        setbuf(stdin, NULL);
        fgets(lista[indice].nombre, 50, stdin);
        sacarEnter(lista[indice].nombre);

        printf("\nIngrese la categoria: 70-Junior 75-SemiSenior 80-Senior: "); // aca habria que validar que no ingrese otra categoria.
        scanf("%d", &lista[indice].categoria);

        printf("Ingrese la cantidad de horas trabajadas: ");
        scanf("%d", &lista[indice].cantHoras);
        lista[indice].estado = 1;

    }else
        {
            system("clear");
            printf("\nNo hay mas lugar en el sistema\n\n");
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


void imprimirProg(eProgramador lista[], eCategoria cate[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
            if (lista[i].estado != 0)
                for (int j = 0; j < tam; j++)
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


int buscarVacio (eProgramador listado[], int tam)
{
    int resultado = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listado[i].estado == 0)
        {
            resultado = i;
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


void imprimirSemi (eProgramador lista[], eCategoria cate[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
            for (int j = 0; j < tam; j++)
            {
                if (lista[i].categoria == 75)
                {
                    lista[i].sueldo = lista[i].cantHoras * cate[1].valorPorHora;
                    printf("\n%s\t%s\t\t%d\n", lista[i].nombre, cate[1].desc, lista[i].sueldo);
                    break;
                }
            }
        }

    printf("\n--------------------------------");
    printf("\n\nNombre\tCategoria\tSueldo\n\n");
}

int sueldosJunior (eProgramador lista[], eCategoria cate[], int tam)
{

    int total = 0;
    for (int i = 0; i < tam; i++)
    {
            for (int j = 0; j < tam; j++)
            {
                if (lista[i].categoria == 70)
                {
                    lista[i].sueldo = lista[i].cantHoras * cate[0].valorPorHora;
                    total = total + lista[i].sueldo;
                    break;
                }
            }
        }

    return total;
}

void menosProgramadores (eProgramador lista[], eCategoria cat[], int tam, int tamCat)
{
    int cont, min, flag = 0, vueltas = 0;
    char categorias[tamCat][30];
    for (int i = 0; i < tamCat; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (lista[j].categoria == cat[i].id )
            {
                cont++;
            }
        }
        if (flag == 0)
            {
                min = cont;
                flag = 1;
            }else
            {
                if (cont < min)
                {
                    min = cont;
                }
            }

        cont = 0;
    }
    cont = 0;
    for (int i = 0; i < tamCat; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (lista[j].categoria == cat[i].id)
            {
                cont++;
            }
        }
        if (cont == min)
        {
            strcpy(categorias[i], cat[i].desc);
            cont = 0;
            vueltas++;
        }else
        {
            cont = 0;
        }

    }
    printf("\n\n%d", min);
    printf("\n\n\n%d", cont);
    for (int i = 0; i < vueltas; i++)
    {
        printf("\n\nMenor cantidad de programadores: Categoria %s   Cantidad: %d \n\n", categorias[i], min);
    }
}



void programadorDefault(eProgramador lista[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        switch (i){
            case 0:
                lista[0].categoria = 70;
                strcpy(lista[0].nombre, "Pepe");
                lista[0].estado = 1;
                lista[0].id = 1;
                lista[0].proyecto = 15;
                lista[0].cantHoras = 10;

            case 1:
                lista[1].categoria = 70;
                strcpy(lista[1].nombre, "Juan");
                lista[1].estado = 1;
                lista[1].id = 2;
                lista[1].proyecto = 20;
                lista[1].cantHoras = 50;

            case 2:
                lista[2].categoria = 80;
                strcpy(lista[2].nombre, "Luis");
                lista[2].estado = 1;
                lista[2].id = 3;
                lista[2].proyecto = 40;
                lista[2].cantHoras = 10;
            case 3:
                lista[3].categoria = 80;
                strcpy(lista[3].nombre, "Luis");
                lista[3].estado = 1;
                lista[3].id = 4;
                lista[3].proyecto = 70;
                lista[3].cantHoras = 10;
            case 4:
                lista[4].categoria = 80;
                strcpy(lista[4].nombre, "Luis");
                lista[4].estado = 1;
                lista[4].id = 3;
                lista[4].proyecto = 40;
                lista[4].cantHoras = 10;


        }
    }
}
