#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int num1;
    int num2;
    int producto;
    int cuad;
    printf("Ingrese un numero _que no sea_ cero:");
    scanf("%d", &num1);
    while(num1 == 0)
    {
        printf("Dije distinto de cero!!");
        scanf("%d", &num1);
    }
    printf("Ingrese otro numero _que no sea cero_: ");
    scanf("%d", &num2);
    while (num2 == 0)
    {
        printf("Dije distinto de cero!!");
        scanf("%d", &num2);
    }
    producto = num1 * num2;
    cuad = num1 * num1;
    printf("El producto de ambos numeros es %d y el cuadrado del primer numero es %d : \n", producto, cuad);
    system("pause");
    return 0;
}
