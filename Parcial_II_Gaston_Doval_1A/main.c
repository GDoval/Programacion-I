#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parse.h"
int main()
{
    FILE* pLista;
    FILE* pListaNegra;
    ArrayList* lista = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* definitiva = al_newArrayList();
    char destina[100];
    char negra[100];
    int opcion;
    char resp = 's';
    int r, flag = 0;
    while (resp == 's')
    {
        system("cls");
        printf("1) Parsear lista\n");
        printf("2) Parsear blackList\n");
        printf("3) Depurar\n");
        printf("4) Lista definitiva\n");
        printf("5) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            system("cls");
            printf("Ingrese nombre de la lista de destinatarios: ");
            setbuf(stdin, NULL);
            fgets(destina, 100, stdin);
            sacarEnter(destina);
            strcat(destina, ".csv");
            pLista = fopen(destina, "r");
            r = parseLista(pLista, lista);
            if (r == -1)
            {
                printf("\nNo se pudo parsear el archivo\n\n");
            }
            else
            {
                flag = 1;
                printf("\nListo\n\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            printf("Ingrese nombre de la lista negra: ");
            setbuf(stdin, NULL);
            fgets(negra, 100, stdin);
            sacarEnter(negra);
            strcat(negra, ".csv");
            pListaNegra = fopen(negra, "r");
            r = parseNegra(pListaNegra, lista, listaNegra);
            if (r == -1)
            {
                printf("\nNo se pudo parsear el archivo\n\n");
            }
            else
            {
                flag = 1;
                printf("\nListo\n\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if (flag == 0)
            {
                printf("\nNo se puede depurar, las listas no estan cargadas.\n\n");
                system("pause");
                break;
            }
            nuevaLista(lista, listaNegra, definitiva);
            system("pause");
            break;
        case 4:
            system("cls");
            imprimir(definitiva);
            system("pause");
            break;
        case 5:
            resp = 'n';
            break;
        }
    }
    return 0;
}
