#include "funciones.h"


eLetra* constructor_letra()
{
    eLetra* aux = (eLetra*)malloc(sizeof(eLetra));
    if(aux != NULL)
    {
        aux->letra = ' ';
        strcpy(aux->nombre, "");
        aux->consonante = 0;
        aux->vocal = 0;
        aux->id = 0;
    }
    return aux;
}

FILE* abrir_archivo_texto(char* path) //Crea o abre un archivo txt en el path que se pasa como parametro
{
    FILE* archivo;
    if ((archivo = fopen(path, "r+")) == NULL)
        if((archivo = fopen(path, "w+")) == NULL)
        {
            printf("\nNo se pudo abrir el archivo\n");
        }
    return archivo;
}

void parsear_datos(ArrayList* lista)
{
    FILE* archivo = abrir_archivo_texto("datos.csv");
    eLetra* aux;
    int id;
    rewind(archivo);
    char aux_letra[100];
    char aux_nombre[21];
    char aux_vocal[100];
    char aux_consonante[100];
    fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]",aux_letra, aux_nombre, aux_vocal, aux_consonante);
    while (!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]",aux_letra, aux_nombre, aux_vocal, aux_consonante);
        aux = constructor_letra();
        if(aux != NULL)
        {
            strcpy(aux->nombre, aux_nombre);
            aux->letra = aux_letra[1];
            aux->consonante = atoi(aux_consonante);
            aux->vocal = atoi(aux_vocal);
            id = buscar_max_id(lista);
            aux->id = id+1;
            lista->add(lista, aux);
        }
    }
    fclose(archivo);
}

void imprimir(ArrayList* lista)
{
    int i;
    eLetra* aux;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        printf("%10d%10c%10s%10d%10d\n",aux->id,aux->letra, aux->nombre, aux->consonante, aux->vocal );
    }
}

void set_Vocal(ArrayList* list, int indice, char letra)
{
    int i;
    if(isdigit(letra))
    {
        printf("Se ingrso un numero\n\n");
        return;
    }

    eLetra* aux = constructor_letra();
    for( i = 0; i < list->len(list); i++)
    {
        if(i == indice)
        {
            aux = list->get(list, i);
            if(es_Vocal(letra))
                aux->vocal = 1;
            else
                aux->vocal = 0;
            break;
        }
    }
}


int es_Vocal(char letra)
{
    int resp = 0;
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        resp = 1;
    return resp;
}

void set_Consonante(ArrayList* list, int indice, char letra)
{
    int i;
    if(isdigit(letra))
    {
        printf("Se ingrso un numero\n\n");
        return;
    }
    eLetra* aux = constructor_letra();
    for( i = 0; i < list->len(list); i++)
    {
        if(i == indice)
        {
            aux = list->get(list, i);
            if(!(es_Vocal(letra)))
                aux->consonante = 1;
            else
                aux->consonante = 0;
            break;
        }
    }
}

void set_Letra(ArrayList* list, int indice, char letra)
{
    int i;
    eLetra* aux = constructor_letra();
    for( i = 0; i < list->len(list); i++)
    {
        if(i == indice)
        {
            aux = list->get(list, i);
            aux->letra = letra;
            break;
        }
    }
}

int buscar_max_id(ArrayList* lista) //Devuelve el ID mayor del ArrayList
{
    eLetra* aux = constructor_letra();
    int max = 0;
    int i;
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if (aux->id > max)
        {
            max = aux->id;
        }
    }
    return max;
}
int ordenar_Letras(void* letra1, void* letra2)
{
    if(((eLetra*)letra1)->letra > ((eLetra*)letra2)->letra)
        return 0;
    return 1;
}

void ordenar_Descendente(ArrayList* lista, char cadena[])
{
    int i, j;
    todoMinus(cadena);
    ArrayList* ordenado = al_newArrayList();
    int lenght = strlen(cadena);
    eLetra* aux = constructor_letra();
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        for(j = 0; j < lenght; j++)
        {
            if(aux->letra == cadena[j])
            {
                set_Consonante(lista, i, cadena[j]);
                set_Vocal(lista, i, cadena[j]);
                ordenado->add(ordenado, aux);
            }
        }
    }
    ordenado->sort(ordenado, ordenar_Letras, 1);
    imprimir(ordenado);
}

void ordenar_Ascendente (ArrayList* lista, char cadena[])
{
    int i, j;
    todoMinus(cadena);
    ArrayList* ordenado = al_newArrayList();
    ordenado = lista->clone(lista);
    int lenght = strlen(cadena);
    eLetra* aux = constructor_letra();
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        for(j = 0; j < lenght; j++)
        {
            if(aux->letra == cadena[j])
            {
                ordenado = remover_Letra(ordenado, i);
            }
        }
    }
    ordenado->sort(ordenado, ordenar_Letras, 0);
    imprimir(ordenado);
}


void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}

void todoMinus(char * temp) // Recibe un string y lo pasa _todo_ a minuscula.
{
    char *s = temp;
    while (*s)
    {
        *s = tolower((unsigned char) *s);
        s++;
    }
}

ArrayList* remover_Letra(ArrayList* lista, char letra)
{
    int i;
    eLetra* aux =  constructor_letra();
    for(i = 0; i < lista->len(lista);i++)
    {
        aux = lista->get(lista, i);
        if(aux->letra == letra)
            lista->remove(lista, i);
    }
    return lista;
}


