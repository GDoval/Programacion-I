#include "funciones.h"
#include "ArrayList.h"
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

eCliente* constructor_clientes()
{
    eCliente* aux = (eCliente*) malloc(sizeof(eCliente));
    if (aux != NULL)
    {
        strcpy(aux->nombre, "");
        strcpy(aux->apellido, "");
        aux->id = 0;
        aux->dni = 0;
        aux->estado = 0;
    }
    return aux;
}


eVentas* constructor_ventas()
{
    eVentas* aux = (eVentas*) malloc(sizeof(eVentas));
    if (aux != NULL)
    {
        aux->cantidad = 0;
        aux->idCliente = 0;
        aux->estado= 0;
        strcpy(aux->fecha, "");
        aux->costoUnitario = 0;
        strcpy(aux->codigoProducto, "");
    }
    return aux;
}



void parsear_cliente(ArrayList* cliente)
{
    FILE* archivo = abrir_archivo_texto("clientes.txt");
    eCliente* aux;
    int id, validar;
    char auxNombre[100];
    char auxApellido[100];
    //char auxId[100];
    char auxDni[100];
    fscanf(archivo, "%[^,],%[^,],%[^\n]\n",auxNombre, auxApellido, auxDni);
    while (!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^\n]\n",auxNombre, auxApellido, auxDni);
        aux = constructor_clientes();
        if (aux != NULL)
        {
            strcpy(aux->nombre, auxNombre);
            strcpy(aux->apellido, auxApellido);
            aux->dni = atol(auxDni);
            id = 1 + buscar_max_id_cliente(cliente);
            aux->id = id;
            aux->estado = 1;
        }
        validar = buscarRepetido(cliente, aux->dni);
        if(validar == 0)
        {
            cliente->add(cliente, aux);
        }
    }
    fclose(archivo);
}

int buscarRepetido(ArrayList* lista, long dni)//Devuelve 1 si hay repetido
{
    int i, resp = 0;
    eCliente* aux;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if(aux->dni == dni)
        {
            resp = 1;
            break;
        }
    }
    return resp;
}

int ordenarPorApellido (void* cliente, void* cliente2) //Funciona bien
{
    if (strcmp(((eCliente*)cliente)->apellido, ((eCliente*)cliente2)->apellido) > 0)
        return 1;
    return 0;
}


void imprimir_clientes(ArrayList* lista)
{
    eCliente* aux;
    int i;
    system("cls");
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        printf("%d   %s, %s, %ld \n",aux->id, aux->nombre, aux->apellido, aux->dni);
    }
    system("pause");
}


void agregar_cliente(ArrayList* lista, char* nombre, char* apellido, long dni)
{
    eCliente* aux = constructor_clientes();
    int len = lista->len(lista);
    int id = 1 + buscar_max_id_cliente(lista);
    FILE* archivo = abrir_archivo_texto("clientes.txt");
    rewind(archivo);
    fseek(archivo, 0L, SEEK_END);
    fprintf(archivo, "%s,%s,%ld\n", nombre, apellido, dni);
    strcpy(aux->apellido, apellido);
    strcpy(aux->nombre, nombre);
    aux->dni = dni;
    aux->id = id;
    aux->estado = 1;
    lista->add(lista, aux);
    fclose(archivo);
}



void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
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


int buscar_max_id_cliente(ArrayList* lista) //Devuelve el ID mayor del ArrayList
{
    eCliente* aux = constructor_clientes();
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


int baja_cliente (ArrayList* lista, long dni)
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

void cargarVenta(int id, ArrayList* lista)
{
    eVentas* aux = constructor_ventas();
    int buffer;
    printf("Ingrese codigo de producto: 1 = TV12; 2 = CPU32; 3 = LV87: ");
    scanf("%d", &buffer);
    printf("\nIngrese cantidad de producto a comprar: ");
    scanf("%d", &aux->cantidad);
    printf("\nIngrese fecha de la compra (DD/MM/YY):" );
    setbuf(stdin, NULL);
    fgets(aux->fecha, 101, stdin);
    sacarEnter(aux->fecha);
    switch (buffer)
    {
    case 1:
        aux->costoUnitario = TV12;
        strcpy(aux->codigoProducto, "TV12");
        break;
    case 2:
        aux->costoUnitario = CPU32;
        strcpy(aux->codigoProducto, "CPU32");
        break;
    case 3:
        aux->costoUnitario = LV87;
        strcpy(aux->codigoProducto, "LV87");
        break;
    }
    aux->estado = 1;
    aux->idCliente = id;
    lista->add(lista, aux);
}

void crea_txt_ventas(ArrayList* lista, ArrayList* listaClientes) //Crea un txt a partir del arraylist que se pasa como parametro
{
    int i, indice;
    FILE* archivo = abrir_archivo_texto("reporteventas.txt");
    eVentas* aux;
    float total;
    eCliente* cliente;
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = (eVentas*)lista->get(lista, i);
        indice = buscarIDCliente(listaClientes, aux->idCliente);
        cliente = (eCliente*)listaClientes->get(listaClientes, indice);
        total = (float)aux->costoUnitario * aux->cantidad;
        fprintf(archivo, "%s,%s,%d,%s,%.2f\n",cliente->nombre, cliente->apellido, cliente->dni, aux->codigoProducto, total);
    }
    fclose(archivo);
}



void imprimirVentas(ArrayList* lista)
{
    eVentas* aux;
    int i;
    system("cls");
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        printf("%d   %s, %d, %s \n",aux->idCliente, aux->codigoProducto, aux->cantidad, aux->fecha);
    }
    system("pause");
}

int buscarIDCliente(ArrayList* lista, int id)
{
    int i;
    eCliente* aux;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if(aux->id == id)
            return i;
    }
}

int ordenarVentasPrecio(void* venta1, void* venta2)
{
    float total1, total2;
    total1 = ((eVentas*)venta1)->cantidad * ((eVentas*)venta1)->costoUnitario;
    total2 = ((eVentas*)venta2)->cantidad * ((eVentas*)venta2)->costoUnitario;
    if(total1 > total2)
        return 0;
    else
        return 1;
}


void crea_txt_ventasFecha(ArrayList* lista, ArrayList* listaClientes, char fecha[]) //Crea un txt a partir del arraylist que se pasa como parametro
{
    int i, indice;
    FILE* archivo = abrir_archivo_texto("reporteventasfecha.txt");
    eVentas* aux = constructor_ventas();
    float total;
    eCliente* cliente;
    for (i = 0; i < lista->len(lista); i++)
    {
        aux = (eVentas*)lista->get(lista, i);
        if(strcmp(fecha, aux->fecha) == 0)
        {
            indice = buscarIDCliente(listaClientes, aux->idCliente);
            cliente = (eCliente*)listaClientes->get(listaClientes, indice);
            total = (float)aux->costoUnitario * aux->cantidad;
            fprintf(archivo, "%s,%s,%d,%s,%.2f\n",cliente->nombre, cliente->apellido, cliente->dni, aux->codigoProducto, total);
        }
    }
    fclose(archivo);
}

void informarMayorVentaProducto(ArrayList* listaVentas)
{
    eVentas* aux;
    char produ[100];
    int i, acumTV = 0, acumPC = 0, acumLV = 0, resp = 0;
    for(i = 0; i < listaVentas->len(listaVentas); i++)
    {
        aux = (eVentas*) listaVentas->get(listaVentas, i);
        if(strcmp("TV12", aux->codigoProducto) == 0)
            acumTV += aux->cantidad;
        else
            if(strcmp("CPU32", aux->codigoProducto) == 0)
            acumPC += aux->cantidad;
        else
            if((strcmp("LV87", aux->codigoProducto) == 0))
            acumLV += aux->cantidad;
    }
    resp = buscarMaximo(acumLV, acumPC, acumTV);
    if(resp == acumLV)
        strcpy(produ, "LV87");
    else
        if(resp == acumPC)
        strcpy(produ, "CPU32");
    else
        strcpy(produ, "TV12");
    system("cls");
    printf("El codigo de producto con mas ventas es: %s\n\n", produ);
    system("pause");
}

int buscarMaximo(int num1, int num2, int num3)
{
    if(num1 >= num2 && num1 >= num3)
        return num1;
    if(num2 >= num1 && num2 >= num3)
        return num2;
    if(num3 >= num2 && num3 >= num1)
        return num3;
}

