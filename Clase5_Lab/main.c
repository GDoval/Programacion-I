#include <stdio.h>
#include <stdlib.h>
#define MAX 1
int main()
{
    int codigo[MAX];
    float precio[MAX];
    char n[MAX];
    for (int i = 0; i < MAX; i++)
    {
        printf("Ingrese codigo de producto: ");
        scanf("%d", &codigo[i]);
        printf("\nIngrese precio: ");
        scanf("%f", &precio[i]);
        printf("\nIngrese inicial del producto: ");
        scanf(" %c", &n[i]);
    }
    for (int i = 0; i < MAX; i++)
    {
        printf("\nEl producto codigo %d ,tiene un precio de %f, y su incial es %c", codigo[i], precio[i], n[i]);
    }


    return 0;
}
