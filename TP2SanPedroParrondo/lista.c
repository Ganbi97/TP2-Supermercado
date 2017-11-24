#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "lista.h"
#include "arbol.h"
#include "fila.h"
#include "caja.h"
nodo * inicNodo()
{
    return NULL;
}

nodo * crearNodo(persona a)
{
    nodo * aux=(nodo*)malloc(sizeof(nodo));
    aux->cliente=a;
    aux->anterior=NULL;
    aux->siguiente=NULL;

    return aux;
}

nodo * agregarPrincipio(nodo * Lista,nodo * nuevo)
{
    nuevo->siguiente=Lista;
    if(Lista)
    {
        Lista->anterior=nuevo;
    }
    return nuevo;
}

nodo * agregarFinal(nodo * Lista,nodo * nuevo)
{
    nodo * ultimo=NULL;
    if(!Lista) Lista=nuevo;
    else
    {
        ultimo=buscarUltimo(Lista);
        ultimo->siguiente=nuevo;
        nuevo->anterior=ultimo;
    }
    return Lista;
}

nodo * buscarUltimo(nodo * Lista)
{
    nodo * seg=Lista;
    if(Lista)
    {
        while(seg->siguiente)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}

nodo * agregarEnOrdenTipoCli(nodo * Lista,nodo * nuevo)
{
    if(!Lista) Lista=nuevo;
    else
    {
        if((nuevo->cliente.tipo_cliente) < (Lista->cliente.tipo_cliente))
        {
            Lista=agregarPrincipio(Lista,nuevo);
        }
        else
        {
            nodo * seg = Lista->siguiente;
            nodo * ante = Lista;
            while((seg) && (nuevo->cliente.tipo_cliente > seg->cliente.tipo_cliente))
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevo;
            nuevo->anterior=ante;
            nuevo->siguiente=seg;
            if(seg) seg->anterior=nuevo;
        }
    }
    return Lista;
}

nodo * agregarEnOrdenPorCant(nodo * Lista,nodo * nuevo)
{
    if(!Lista) Lista=nuevo;
    else
    {
        if((nuevo->cliente.cantArticulos) < (Lista->cliente.cantArticulos))
        {
            Lista=agregarPrincipio(Lista,nuevo);
        }
        else
        {
            nodo * seg = Lista->siguiente;
            nodo * ante = Lista;
            while((seg) && (nuevo->cliente.cantArticulos > seg->cliente.cantArticulos))
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevo;
            nuevo->anterior=ante;
            nuevo->siguiente=seg;
            if(seg) seg->anterior=nuevo;
        }
    }
    return Lista;
}


void mostrarLista(nodo * Lista)
{
    nodo * seg=Lista;
    while(seg)
    {
        mostrarNodo(seg->cliente);
        seg=seg->siguiente;
    }
}

void mostrarListaPausado(nodo * Lista)
{
    nodo * seg=Lista;
    while(seg)
    {
        system("pause");
        mostrarNodo(seg->cliente);
        seg=seg->siguiente;
    }
}


void mostrarNodo(persona cliente)
{
    printf("Nombre Y Apellido: %s\n",cliente.nombre);
    printf("Cantidad de articulos: %d\n",cliente.cantArticulos);
    printf("Tiempo de espera: %d\n",cliente.tiempoDeEspera);
    printf("Tiempo de procesado: %d\n",cliente.tiempoProcesado);
    printf("Tipo de cliente: %d",cliente.tipo_cliente);tipodeCliente(cliente.tipo_cliente);
    printf("Tipo de pago: %d",cliente.tipo_pago);tipodePago(cliente.tipo_pago);
    puts("------------------------------------");
}

nodo * borrarNodo(nodo * Lista,char nombre[])
{
    nodo * seg;
    nodo * ante;
    if((Lista) && strcmp(Lista->cliente.nombre,nombre) ==0)
    {
        nodo * aux=Lista;
        Lista=Lista->siguiente;
        free(aux);
        Lista->anterior=NULL;

    }
    else
    {
        seg=Lista;
        while((seg) && (strcmp(seg->cliente.nombre,nombre) != 0 ))
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if(seg)
        {
            ante->siguiente=seg->siguiente;
            seg->anterior=ante;
            free(seg);
        }
    }
    return Lista;
}

nodo * borrarPrimero(nodo * Lista)
{
    if(Lista)
    {
        nodo * aux=Lista;
        Lista=Lista->siguiente;
        free(aux);
        Lista->anterior=NULL;
    }
    return Lista;
}

nodo * copiarArchivoALista(nodo * Lista,char nombre[])
{
    persona aux;
    FILE * archivo=fopen(nombre,"rb");
    if(archivo)
    {
        nodo * nuevo;
        while(fread(&aux,sizeof(persona),1,archivo)>0)
        {
           nuevo=crearNodo(aux);
           Lista=agregarPrincipio(Lista,nuevo);
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
    return Lista;
}


void ordenarporArticulos(Fila * filita)
{
    nodo * lista=inicNodo();
    persona p;
    while(filaVacia(filita))
    {
        p=quitar(filita);
        lista=agregarEnOrdenPorCant(lista,crearNodo(p));
    }
    while(lista)
    {
        agregar(filita,crearNodo(lista->cliente));
        lista=lista->siguiente;
    }
}

void ordenarporTipoCliente(Fila * filita)
{
    nodo * lista=inicNodo();
    persona p;
    while(filaVacia(filita))
    {
        p=quitar(filita);
        lista=agregarEnOrdenTipoCli(lista,crearNodo(p));
    }
    while(lista)
    {
        agregar(filita,crearNodo(lista->cliente));
        lista=lista->siguiente;
    }
}
