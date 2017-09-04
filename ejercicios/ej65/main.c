#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main()
{
    int vec[TAM], opcion, aux;
    char respuesta ='s';


    while (respuesta == 's')
    {
        printf("Presione 1 para cargar el vector: \n");
        printf("Presione 2 para ordenar el vector: \n");
        printf("Presione 3 para mostrar el vector: \n");
        printf("Presione 4 para salir: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", &vec[i]);
            }

            break;
        case 2:
            for (int i = 0; i < TAM-1; i++)
            {
                for (int j = i+1 ; j < TAM; j++)
                {
                    if (vec[i] > vec[j])
                    {
                        aux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = aux;
                    }
                }
            }
            break;

        case 3:
            system("clear");
            for (int i = 0; i < TAM; i++)
            {
                printf("  %d  ", vec[i]);
                printf("\n\n");
            }
            break;
        case 4:
            respuesta = 'n';
            break;

        }
    }

    return 0;
}
