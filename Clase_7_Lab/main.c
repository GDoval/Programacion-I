#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[30];
    char apellido[30];
    char buffer[2000];
    char apellidoNombre[60];
    int cant;
    printf("Ingrese su nombre: ");
    fgets(buffer, 2000, stdin);
    cant = strlen(buffer);
    while (cant > 28)
    {
        printf("Error, reingrese: ");
        fgets(buffer, 2000, stdin);
        cant = strlen(buffer);
    }
    strcpy(nombre, buffer);
    nombre[cant - 1] = '\0';
    printf("Ingrese su apellido: ");
    fgets(buffer, 2000, stdin);
    cant = strlen(buffer);
    while (cant > 28)
    {
        printf("Error, reingrese: ");
        fgets(buffer, 2000, stdin);
        cant = strlen(buffer);
    }
    strcpy(apellido, buffer);
    apellido[cant - 1] = '\0';
    strupr(&nombre[0]);
    strupr(&apellido[0]);
    strlwr(&nombre[1]);
    strlwr(&apellido[1]);
    strcat(apellido, ",");
    strcat(apellido, " ");
    strcat(apellido, nombre);
    strcpy(apellidoNombre, apellido);
    printf("%s", apellidoNombre);

    return 0;
}
