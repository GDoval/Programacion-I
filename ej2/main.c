#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int, int[], int);
int main()
{
    int leg[] ={128, 356, 198, 215, 320};
    int posi, num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    posi = buscarNumero(num, leg, 5);
    if (posi == -1)
    {
        printf("El numero %d no se encuentra en el array. ", num);
    }else{
        printf("El numero %d se encuentra en el indice %d ", num, posi);

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
