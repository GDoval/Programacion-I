#include <stdio.h>
#include <stdlib.h>
int suma(int n1, int n2);
int pedirnumero();
int main()
{
    int num1, num2, rta;
    num1 = pedirnumero();
    num2 = pedirnumero();
    rta = suma(num1, num2);
    printf("La suma es: %d ", rta);
    return 0;
}
int suma(int n1, int n2) // Esto iria en un archivo aparte, pero por hoy se deja aca.
{
    int rsp;
    rsp = n1 + n2;
    return rsp;
}

int pedirnumero()// Esto iria en un archivo aparte, pero por hoy se deja aca.
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    return num;
}
