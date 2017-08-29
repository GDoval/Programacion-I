#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int main()
{
    int promedio, nota, acum, i;
    char nom[TAM], resp;
    acum = 0;
    resp = 's';
    i = 0;
    do
    {
        system("clear");
        promedio = 0;
        acum = 0;
        printf("\nIngrese el apellido del alumno: \n");
        scanf("%s", &nom);
        while ( i < 6)
        {
        i++;
        printf("Ingrese la nota: \n");
        scanf("%d", &nota);
        acum = acum + nota;
        }
        promedio = acum / 6;
        printf("\nEl alumno %s tuvo un promedio de %d: ", nom, promedio);
        printf("\n\n");
        i = 0;
        printf("\nQuiere seguir cargando alumnos? s/n: \n");
        scanf(" %c",&resp);


    }while (resp =='s');


    return 0;
}
