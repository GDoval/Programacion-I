#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int buscarNumero(int, int[], int);

int main()
{
   int legajo[TAM], parcial1[TAM], parcial2[TAM], i, posi;
   float promedio[TAM];
   legajo[0] = 128;
   legajo[1] = 356;
   legajo[2] = 198;
   legajo[3] = 215;
   legajo[4] = 320;
   parcial1 [0] = 2;
   parcial1 [1] = 2;
   parcial1 [2] = 2;
   parcial1 [3] = 7;
   parcial1 [4] = 10;
   parcial2[0] = 7;
   parcial2[1] = 2;
   parcial2[2] = 8;
   parcial2[3] = 6;
   parcial2[4] = 9;
   for (i = 0; i < TAM; i++)
   {
        promedio[i] =(float) (parcial1[i] + parcial2[i]) / 2;
   }
    printf("Legajo   Nota1   Nota2  Promedio\n");
    printf("\n----------------------------\n");
    for (i = 0; i < TAM; i++)
    {

     printf("\n%d     %d      %d    %.2f \n", legajo[i], parcial1[i], parcial2[i], promedio[i]);
    }
    printf("\n-----------------------------\n");
    posi = buscarNumero(128, legajo, 5);
    if (posi != -1)
    {
        printf("El numero 356 se encuentra en la posicion %d", posi);
    }


   return 0;
}



int buscarNumero(int num, int vec[], int tam)
{
    int resp, i = 0;
    for (i = 0; i < tam; i++)
    {
        if (vec[i] == num)
        {
            resp = i;
            return resp;
        }
        else{
            return -1;
        }
    }

}
