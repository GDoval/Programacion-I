#include <stdio.h>
#include <stdlib.h>

/*while / do-while : no conocemos la cantidad de iteraciones
    for : conocemos la cantidad de iteraciones
*/

/*Se ingresan numeros (distintos de 0), no se sabe cuantos.
Determinar:
    - cantidad de positivos y negativos
    - promedio de todos los numeros
    - cantidad de pares e impares
    - maximo y minimo*/

int main()
{
    char seguir;
    int cont=0;
    int numero;
    int contPositivos = 0;
    int contNegativos = 0;
    int acumuladoDeNumeros = 0; //CamelCase
    int cantNumeros;
    int contParesPositivos = 0;
    int contImparesPositivos = 0;
    float promedio;
    int flag = 0;
    int maximo, minimo;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        while(numero==0)
        {
            printf("Reingrese un numero distinto de 0: ");
            scanf("%d", &numero);

        }

        if(numero>0)
        {
            contPositivos++; // contPositivos = contPositivos + 1;
            if(numero%2==0)
            {
                contParesPositivos++;
            }
            else
            {
                contImparesPositivos++;
            }
        }
        else
        {
            contNegativos++;
        }


        acumuladoDeNumeros = acumuladoDeNumeros + numero;

        if(flag==0 || numero>maximo)
        {
            maximo=numero;

        }
        if(flag==0 || numero<minimo)
        {
            minimo=numero;
            flag=1;
        }

        /*if(flag==0)
        {
            maximo=numero;
            minimo=numero;
            flag=1;
        }
        else
        {
            if(numero>maximo)
            {
                maximo= numero;
            }
            if(numero<minimo)
            {
                minimo=numero;
            }
        }*/



        printf("Desea continuar ingresando numeros? s/n");
        //fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%c", &seguir);


    } while(seguir=='s');

    cantNumeros = contPositivos + contNegativos;
    promedio = (float)acumuladoDeNumeros/cantNumeros;

    printf("Cantidad de positivos %d\n", contPositivos);

    printf("Cantidad de negativos %d\n", contNegativos);
    printf("El promedio de los numeros es: %f\n", promedio);
    printf("Cantidad de positivos pares %d\n", contParesPositivos);

    printf("Cantidad de positivos impares %d\n", contImparesPositivos);
    printf("El maximo es: %d y el minimo es: %d", maximo, minimo);
    return 0;
}
