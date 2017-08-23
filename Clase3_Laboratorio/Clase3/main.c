#include <stdio.h>
#include <stdlib.h>
int suma(int n1, int n2);
int resta(int n1, int n2);
int multi(int n1, int n2);
float division (int n1, int n2);
int pedirnumero();
int main()
{
    int num1, num2, s, r, m;
    float d;
    num1 = pedirnumero();
    num2 = pedirnumero();
    s = suma(num1, num2);
    r = resta(num1,num2);
    m = multi(num1, num2);
    d = division(num1, num2);
    printf("La suma es: %d ; la multiplicacion es: %d ; la division es: %.1f ; la resta es: %d  ", s, m, d, r);
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

int resta(int n1, int n2)
{
    int resta;
    resta = n1 - n2;
    return resta;
}

float division(int n1, int n2)
{
    float division;
    division = (float)n1 / n2;
    return division;
}

int multi(int n1, int n2)
{
    int multi;
    multi = n1 * n2;
    return multi;
}
