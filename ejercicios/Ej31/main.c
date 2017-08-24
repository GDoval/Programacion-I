#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  horatrab, anti;
    float horavalor, bruto, neto;
    char nombre[100];
    printf("Ingrese el nombre del empleado: ");
    setbuf(stdin, NULL);
    scanf("%s", &nombre);
    setbuf(stdin, NULL);
    printf("Ingrese antiguedad del empleado: ");
    scanf("%d", &anti);
    printf("Ingrese el valor de la hora de trabajo: ");
    scanf("%f", &horavalor);
    printf("Ingrese cantidad de horas trabajadas: ");
    scanf("%d", &horatrab);
    bruto = horavalor * horatrab + (anti * 30);
    neto = (float)bruto - (bruto * 0.13);
    printf("El trabajador %s acredito $%.2f brutos, por lo que el pago neto es de :$%.2f", nombre, bruto, neto);
    return 0;
}
