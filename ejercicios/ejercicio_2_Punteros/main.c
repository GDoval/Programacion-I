#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    char respuesta = 's';
    int opcion;
    int vector[TAM];
    while (respuesta == 's')
    {
        printf("1) Cargar el vector");
        printf("\n2) Ordenar el vector");
        printf("\n3) Mostrar el vector");
        printf("\n4) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                system("clear");
                for (int i = 0 ; i < TAM ; i++ )
                {
                    printf("Ingrese un numero: ");
                    scanf("%d", (vector+i));
                }
                break;
            case 2:
                system("clear");
                ordenarVector(&vector, TAM);
                break;
            case 3:
                system("clear");
                for (int i = 0; i < TAM ; i++)
                {
                    printf("%d\n", *(vector+i));
                }
                printf("\n\n");
                break;
            case 4:
                respuesta = 'n';
                break;
        }
    }
    return 0;
}

void ordenarVector (int* vector, int tam)
{
    int aux;
    for (int i = 0; i < tam; i++)
    {
        for (int j = i +1; j < tam; j++)
        {
            if (*(vector+i) > *(vector+j))
            {
                aux = *(vector+i);
                *(vector+i) = *(vector+j);
                *(vector+j) = aux;
            }
        }
    }
}
