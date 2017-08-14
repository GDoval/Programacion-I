#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int suma;
    int promedio;
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);
    printf("Ingrese otro numero: ");
    scanf("%d", &num3);
    printf("Ingrese otro numero: ");
    scanf("%d", &num4);
    printf("Ingrese otro numero: ");
    scanf("%d", &num5);
    suma = num1 + num2 + num3+ num4 + num5;
    promedio = suma / 5;
    printf("El promedio de los numeros es %d \n ", promedio);
    system("pause");
    return 0;
}
