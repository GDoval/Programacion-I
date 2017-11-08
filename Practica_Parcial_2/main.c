#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parse.h"
int main()
{
    FILE* pLista;
    FILE* pListaNegra;
    ArrayList* lista = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* definitiva;
    definitiva = lista->clone(lista);
    int opcion;
    char resp = 's';
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
            pLista = fopen("destinatarios.csv", "r");
            parseLista(pLista, lista);
            printf("\nListo\n\n");
            system("pause");
            break;
        case 2:
            pListaNegra = fopen("black_list.csv", "r");
            parseLista(pListaNegra, listaNegra);
            printf("\nListo\n\n");
            system("pause");
            break;
        case 3:
            definitiva = lista->clone(lista);
            lista = nuevaLista(lista, listaNegra);
            break;
        case 4:
            imprimir(lista);
            system("pause");
            break;
        case 5:
            resp = 'n';
            break;
        }
    }
    return 0;
}
