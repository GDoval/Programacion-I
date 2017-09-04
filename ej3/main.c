#include <stdio.h>
#include <stdlib.h>
int buscarNumero(int, int[], int);
int main()
{
    int leg[] ={128, 356, 198, 215, 320};
    int n1[] = {2,2,2, 7, 10};
    int n2[] = {7,2,8,6,9};
    int i, posi, num;
    float promedio[5];
    for (i = 0; i < 5; i++)
   {
        promedio[i] =(float) (n1[i] + n2[i]) / 2;
   }
    printf("    Legajo   Nota1   Nota2  Promedio\n");
    printf("\n------------------------------------\n");
    for (i = 0; i < 5; i++)
    {

     printf("\n    %4d     %4d      %4d    %4.2f \n", leg[i], n1[i], n2[i], promedio[i]);
    }
    printf("\n************************************\n");
    printf("\nIngrese un numero: ");
    scanf("%d", &num);
    posi = buscarNumero(num, leg, 5);
    if (posi == -1)
    {
        printf("\nEl numero %d no se encuentra en el array. \n\n", num);
    }else{
        printf("\nEl legajo %d se saco un %d y un %d , promediando %.2f \n\n", num, n1[posi], n2[posi], promedio[posi] );
    }
    return 0;
}
int buscarNumero(int num, int vec[], int tam)
{
     int resp = -1,i;
     for (i = 0; i < tam; i++)
    {
        if (vec[i] == num)
        {
            resp = i;
            break;
        }
}
    return resp;
}

