#include "ArrayList.h"
#include "parse.h"


eArtista* constructor_artista()
{
    eArtista* aux;
    aux = (eArtista*) malloc(sizeof(eArtista));
    if (aux != NULL)
    {
        strcpy(aux->email, "");
        strcpy(aux->ip_adress, "");
        strcpy(aux->nombre, "");
        strcpy(aux->pais,"");
        strcpy(aux->password, "");
        aux->id = 0;
        strcpy(aux->sexo,"");
    }
    return aux;
}

eCanciones* constructor_canciones()
{
    eCanciones* aux;
    aux = (eCanciones*) malloc(sizeof(eCanciones));
    if (aux != NULL)
    {
        strcpy(aux->artista, "");
        strcpy(aux->nombre_tema, "");
        aux->id = 0;
    }
    return aux;
}


void parse_artista(ArrayList* lista)
{
    FILE* archivo;
    int validar;
    archivo = abrir_archivo("usuarios.dat");
    char auxId[1000];
    char auxNombre[100];
    char auxEmail[100];
    char auxSexo[100];
    char auxPais[100];
    char auxPassword[100];
    char auxIp_adress[20];
    eArtista* aux;
    fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n];", auxId, auxNombre, auxEmail, auxSexo, auxPais, auxPassword, auxIp_adress);
    while(!feof(archivo))
    {
        validar = fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n];", auxId, auxNombre, auxEmail, auxSexo, auxPais, auxPassword, auxIp_adress);
        if (validar == 7)
        {
            aux = constructor_artista();
            if (aux != NULL)
            {
                strcpy(aux->email, auxEmail);
                strcpy(aux->ip_adress, auxIp_adress);
                strcpy(aux->nombre, auxNombre);
                strcpy(aux->password, auxPassword);
                strcpy(aux->pais, auxPais);
                strcpy(aux->sexo, auxSexo);
                aux->id = atoi(auxId);
            }
            lista->add(lista, aux);
        }

    }
    fclose(archivo);
}


void parse_canciones(ArrayList* lista)
{
    FILE* archivo;
    archivo = abrir_archivo("temas.dat");
    eCanciones* aux;
    char auxArtista[1000];
    char auxId[1000];
    char auxTema[1000];
    int validar;
    fscanf(archivo, "%[^,],%[^,],%[^\n];", auxId, auxTema, auxArtista);
    while(!feof(archivo))
    {
        validar = fscanf(archivo, "%[^,],%[^,],%[^\n];", auxId, auxTema, auxArtista);
        if (validar == 3)
        {
            aux = constructor_canciones();
            if (aux != NULL)
            {
                strcpy(aux->artista, auxArtista);

            }

        }
    }
}


FILE* abrir_archivo(char* path)
{
    FILE* archivo;
    if ((archivo = fopen(path, "r+")) == NULL)
        if((archivo = fopen(path, "w+")) == NULL)
        {
            printf("\nNo se pudo abrir el archivo\n");
        }
    return archivo;
}


void imprimir_artistas(ArrayList* lista)
{
    eArtista* aux;
    int i;
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        printf("%d    %s     %s     %s     %s      %s\n", aux->id, aux->nombre, aux->pais, aux->sexo, aux->ip_adress, aux->password);
    }
}
