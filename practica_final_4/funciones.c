#include "funciones.h"
#include "ArrayList.h"


/* Funciones para crear archivos */


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


void crea_txt_cliente(ArrayList* lista, FILE* archivo) //Crea un txt a partir del arraylist que se pasa como parametro
{
    int i;
    eCliente* aux;
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = (eCliente*)lista->get(lista, i);
        fprintf(archivo, "%d,%s,%s,%li\n", aux->id, aux->nombre, aux->apellido, aux->dni);
    }
    fclose(archivo);
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


void crea_copia_binario(ArrayList* lista, FILE* copia) //Hace lo mismo que crea_binario, no copiar al final
{
    int i;
    eCliente* aux;
    rewind(copia);
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = (eCliente*)lista->get(lista, i);
        fseek(copia, 0L, SEEK_END);
        fwrite(aux, sizeof(eCliente), 1, copia);
    }
    fclose(copia);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Funciones de Parseo */

void parsear_cliente(ArrayList* cliente)
{
    FILE* archivo = abrir_archivo_texto("clientes.txt");
    eCliente* aux;
    char auxNombre[100];
    char auxApellido[100];
    char auxId[100];
    char auxDni[100];
    while (!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxApellido, auxDni);
        aux = constructor_clientes();
        if (aux != NULL)
        {
            strcpy(aux->nombre, auxNombre);
            strcpy(aux->apellido, auxApellido);
            aux->dni = atoi(auxDni);
            aux->id = atoi(auxId);
        }
        cliente->add(cliente, aux);
    }
    fclose(archivo);
}


void parsear_ventas(ArrayList* lista)
{
    FILE* archivo = abrir_archivo_texto("ventas.txt");
    eVentas* aux;
    char auxIdVenta[100];
    char auxIdCliente[100];
    char auxCodProducto[100];
    char auxCantidad[100];
    char auxPrecio[100];
    while(!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdVenta, auxIdCliente, auxCodProducto, auxCantidad, auxPrecio);
        aux = constructor_ventas();
        if (aux != NULL)
        {
            aux->id_venta = atoi(auxIdVenta);
            aux->id_cliente = atoi(auxIdCliente);
            aux->cantidad = atoi(auxCantidad);
            aux->precioUnitario = atof(auxPrecio);
            aux->codProducto = atoi(auxCodProducto);
        }
        lista->add(lista, aux);
    }
    fclose(archivo);
}



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


////////////////////////////////////////////////////////////////////////////////////////////////


/* Constructores genericos */

eCliente* constructor_clientes()
{
    eCliente* aux = (eCliente*) malloc(sizeof(eCliente));
    if (aux != NULL)
    {
        strcpy(aux->nombre, "");
        strcpy(aux->apellido, "");
        aux->id = 0;
        aux->dni = 0;
    }
    return aux;
}

eVentas* constructor_ventas()
{
    eVentas* aux = (eVentas*) malloc(sizeof(eVentas));
    if (aux != NULL)
    {
        aux->cantidad = 0;
        aux->codProducto = 0;
        aux->id_cliente = 0;
        aux->id_venta = 0;
        aux->precioUnitario = 0;
    }
    return aux;
}



////////////////////////////////////////////////////////////////////////////////////


/*Funciones para ABM's de ArrayList ya cargados */

void imprimir_clientes(ArrayList* lista)
{
    eCliente* aux;
    int i;
    system("cls");
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        printf("%d, %s, %s, %d \n", aux->id, aux->nombre, aux->apellido, aux->dni);
    }
    system("pause");
}


void agregar_cliente(ArrayList* lista, char* nombre, char* apellido, int dni)
{
    eCliente* aux = constructor_clientes();
    int len = lista->len(lista);
    int id = 1 + buscar_max_id_cliente(lista);
    FILE* archivo = abrir_archivo_texto("clientes.txt");
    rewind(archivo);
    fseek(archivo, 0L, SEEK_END);
    fprintf(archivo, "%d,%s,%s,%d\n", id, nombre, apellido, dni);
    strcpy(aux->apellido, apellido);
    strcpy(aux->nombre, nombre);
    aux->dni = dni;
    aux->id = id;
    lista->add(lista, aux);
    fclose(archivo);
}





int modifica_clientes(ArrayList* lista, int dni, int dni_viejo, char* nombre, char* apellido)
{
    eCliente* aux;
    int i;
    int flag = 1;
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = (eCliente*) lista->get(lista, i);
        if (aux->dni == dni_viejo)
        {
            strcpy(aux->nombre, nombre);
            strcpy(aux->apellido, apellido);
            aux->dni = dni;
            lista->set(lista, i, aux);
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("\n El ID ingresado no se encuentra en el listado\n");
        return 0;
    }
    else
    {
        return 1;
    }
}


int baja_cliente (ArrayList* lista, int dni)
{
    eCliente* aux;
    int i;
    char resp;
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = (eCliente*) lista->get(lista, i);
        if (aux->dni == dni)
        {
            system("cls");
            printf("%s      %s      %d\n", aux->nombre, aux->apellido, aux->dni);
            setbuf(stdin, NULL);
            printf("¿Desea borrar este registro? s/n");
            scanf("%c", &resp);
            if (resp == 's')
            {
                lista->remove(lista, i);
                return 1;
            }
            else
            {
                printf("\n Operacion cancelada\n\n");
                system("pause");
                return 0;
            }
        }
    }
}


void agregar_cliente_binario(ArrayList* lista, char* nombre, char* apellido, int dni) //Funciona
{
    eCliente* aux = constructor_clientes();
    int id = 1 + buscar_max_id_cliente(lista);
    FILE* archivo = abrir_archivo_binario("clientes.bin");
    strcpy(aux->apellido, apellido);
    strcpy(aux->nombre, nombre);
    aux->dni = dni;
    aux->id = id;
    lista->add(lista, aux);
    rewind(archivo);
    fseek(archivo, 0L, SEEK_END);
    fwrite(aux, sizeof(eCliente), 1, archivo);
    fclose(archivo);
}


////////////////////////////////////////////////////////////////////////////////////////

/*Funciones genericas para pedir datos al usuario, bucar mayores, editar strings, etc */


int buscar_max_id_cliente(ArrayList* lista) //Devuelve el ID mayor del ArrayList
{
    eCliente* aux;
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


int devuelve_dni()
{
    int dni;
    printf("\nIngrese el DNI del cliente: ");
    scanf("%d", &dni);
    return dni;
}


void devuelve_nombre(char nom[])
{
    printf("Ingrese el nombre del cliente: ");
    setbuf(stdin, NULL);
    fgets(nom, 101, stdin);
    sacarEnter(nom);
}

void devuelve_apellido(char ape[])
{
    printf("\nIngrese apellido del cliente: ");
    setbuf(stdin, NULL);
    fgets(ape, 101, stdin);
    sacarEnter(ape);
}

void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}
