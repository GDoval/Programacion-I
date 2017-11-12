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
    int opcion = 0;
    char resp = 's';
    while (resp == 's')
    {
        printf("1) Parsear lista\n");
        printf("2) Parsear blackList\n");
        printf("3) Depurar\n");
        printf("4) Lista definitiva\n");
        printf("5) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            pLista = fopen("destinatarios.csv", "r");
            parseLista(pLista, lista);
            printf("\nListo\n\n");
            //system("pause");
            break;
        case 2:
            system("clear");
            pListaNegra = fopen("black_list.csv", "r");
            parseLista(pListaNegra, listaNegra);
            printf("\nListo\n\n");
            //system("pause");
            break;
        case 3:
            system("clear");
            nuevaLista(lista, listaNegra, definitiva);
            break;
        case 4:
            system("clear");
            imprimir(definitiva);
            //system("pause");
            break;
        case 5:
            resp = 'n';
            break;
        }
    }
    return 0;
}
