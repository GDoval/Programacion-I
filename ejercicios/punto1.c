#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int suma;
    int promedio;
    int x;
    suma = 0;
    for (x = 1; x < 6; x++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        suma = suma + num;
    }
    promedio = suma / 5;
    printf("El promedio de los numeros es %d \n ", promedio);
    system("pause");
    return 0;
}
