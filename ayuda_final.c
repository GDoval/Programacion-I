//Buscar minimo o maximo y devolver el/los indices

void buscarMinimos(int arr[], int lenght)
{
    int* ptr = (int*)malloc(sizeof(int));
    int* aux;
    int indice = 0, i, min = 0, flag = 0;
    int flag2 = 0;
    for(i = 0; i < lenght; i++)
    {
        if(arr[i] < min || flag == 0)
        {
            min = arr[i];
            flag = 1;
        }
    }
    for(i = 0; i < lenght; i++)
    {
        if(min == arr[i])
        {
            if (flag2 > 0)
            {
                aux = (int*)realloc(ptr, sizeof(int)*(indice+1));
                if(aux != NULL)
                    ptr = aux;
            }
            *(ptr+indice) = i;
            indice++;
            flag2 = 1;
        }
    }

    printf("Indice/s del numero minimo: ");
    for(i = 0; i < indice ; i++)
    {
        printf("%d\n", *(ptr+i));
    }
}


//Aritmetica de punteros
    int *ptr = (int*)malloc(sizeof(int) * 5);
    int i;
    for(i = 0; i < 5; i++)
    {
        *(ptr+i) = i;
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", *(ptr+i));
    }



 //Funciones seters de uno de los modelos de parcial

    int auto_setMarca(eAuto *pAuto, char *marca)
{
    int validar = 0,  resp = 1;
    validar = strlen(marca);
    if(validar >= 3)
    {
        strcpy(pAuto->marca, marca);
    }
    else
        resp = 0;
    return resp;
}


int auto_setModelo(eAuto *pAuto, int modelo)
{
    int  resp = 1;
    if(modelo >= 1970 && modelo <= 2015)
        pAuto->modelo = modelo;
    else
        resp = 0;
    return resp;
}

int auto_setColor(eAuto *pAuto, int color)
{
    int resp = 1;
    if(color >= 1 && color <= 6)
        pAuto->color = color;
    else
        resp = 0;
    return resp;
}


int auto_setPatente(eAuto *pAuto, char *patente) //Separa una cadena en 3 partes, faltaria validar que sea de longitud 7 (3 letras y espacio 3 numeros)
{
    char letras[3] = {patente[0], patente[1], patente[2]};
    int numeros[3] = {patente[4], patente[5], patente[6]};
    int i, resp = 1;
    for(i = 0; i < 3; i++)
    {
        if(isalpha(letras[i]) == 0)
            return resp = 0;
    }
    for (i = 0; i < 3; i++)
    {
        if((isalpha(numeros[i]) != 0))
        {
            return resp = 0;
        }
    }
    if(patente[3] != ' ')
        return resp = 0;
    return resp;
}


//Funcion de parseo binario

void parsear_cliente_binario(ArrayList* clientes)// Parseo binario usando una variable del tipo estructura ante de pasar los datos al puntero a estructura
{
    FILE* archivo = abrir_archivo_binario("clientes.bin");
    eCliente bogus;
    int validar;
    rewind(archivo);
    while (!feof(archivo))
    {
        validar = fread(&bogus, sizeof(eCliente), 1, archivo);
        eCliente* aux = constructor_clientes();
        if (validar)
        {
            strcpy(aux->nombre, bogus.nombre);
            strcpy(aux->apellido, bogus.apellido);
            aux->dni = bogus.dni;
            aux->id = bogus.id;
            clientes->add(clientes, aux);
        }
    }
    fclose(archivo);
}


//Crear archivo binario

void crea_binario(ArrayList* lista) //Crea un archivo binario a partir del arraylist que se pasa como parametro
{
    int i;
    eCliente* aux;
    FILE* archivo = abrir_archivo_binario("clientes.bin");
    rewind(archivo);
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = (eCliente*)lista->get(lista, i);
        fseek(archivo, 0L, SEEK_END);
        fwrite(aux, sizeof(eCliente), 1, archivo);
    }
    fclose(archivo);
}


//Abrir/Crear archivos texto y binario

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

FILE* abrir_archivo_binario(char* path)// Crea o abre un archivo binario en el path que se pasa como parametro
{
    FILE* archivo;
    if ((archivo = fopen(path, "rb+")) == NULL)
        if((archivo = fopen(path, "wb+")) == NULL)
        {
            printf("\nNo se pudo abrir el archivo\n");
        }
    return archivo;
}