#include <stdio.h>
#include <stdlib.h>

int main()
{
    int importe = 0;
    int vendedor = 0;
    int comision1 = 0;
    int comision2 = 0;
    int comision3 = 0;
    printf("Ingrese ID de vendedor (1, 2 o 3): ");
    scanf("%d", &vendedor);
    while(vendedor != 1 && vendedor != 2 && vendedor != 3)
    {
        printf("Ingrese ID de vendedor valido (1, 2 o 3):  ");
        scanf("%d", &vendedor);
    }
    do
    {
        while(vendedor != 1 && vendedor != 2 && vendedor != 3)
        {
            printf("Ingrese ID de vendedor valido (1, 2 o 3):  ");
            scanf("%d", &vendedor);
        }
        printf("Ingrese el importe de la venta: ");
        scanf("%d", &importe);
        switch (vendedor)
        {
            case 1:
                importe = importe * 0.05;
                comision1 = comision1 + importe;
            case 2:
                importe = importe * 0.05;
                comision2 = comision2 + importe;
            case 3:
                importe = importe * 0.05;
                comision3 = comision3 + importe;
        }
        printf("Ingrese ID de vendedor (1,2 o 3) o 0 para salir: ");
        scanf("%d", &vendedor);

    }while(vendedor != 0);

    printf("La comision del vendedor ID 1 fue de $ %d ; la comision del vendedor ID 2 fue de $: %d ; la comision del vendedor ID 3 fue de $: %d", comision1, comision2, comision3);

    return 0;
}
