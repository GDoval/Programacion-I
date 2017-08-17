#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int conta = 0;
    int conte = 0;
    int conti = 0;
    int conto = 0;
    int contu = 0;
    for (int x = 0; x < 20; x++)
    {
        printf("Ingrese una letra: ");
        getchar();
        scanf("%c", &letra);
        printf("Letra ingresada: %c", letra);
        /*if (letra == 'a')
        {
            conta++;
        }
        else
        {
            if (letra == 'e')
            {
                conte++;
            }
            else
            {
                if(letra == 'i')
                {
                    conti++;
                }
                else
                {
                    if (letra == 'o')
                    {
                        conto++;
                    }
                    else
                    {
                        if (letra == 'u')
                        {
                            contu++;
                        }
                    }
                }
            }
        }*/
    }


    //printf("La cantidad de A es %d, la cantidad de E es %d, la cantidad de I es %d, la cantidad de O es %d, la cantidad de U es %d", conta,conte,conti,conto,contu);


    return 0;
}
