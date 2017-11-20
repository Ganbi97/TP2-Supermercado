#include "fila.h"

nodo*iniclista()
{
    return NULL;
}

nodo*crearNodolista(persona p)
{
    nodo*aux=(nodo*)malloc(sizeof(nodo));
    aux->anterior=NULL;
    aux->siguiente=NULL;
    aux->cliente=p;
    return aux;
}

nodo*agregarAlPrincipio(nodo*lista,nodo*nuevo)
{
    nuevo->siguiente=lista;
    if(lista)
    {
        lista->anterior=nuevo;
    }
    return nuevo;
}

nodo*agregarAlFinal(nodo*lista,nodo*nuevo)
{
    //
    nodo*ultimo=NULL;
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        ultimo=buscarElUltimo(lista);
        ultimo->siguiente=nuevo;
        nuevo->anterior=ultimo;
    }
    return lista;
}

nodo*buscarElUltimo(nodo* lista)
{
    nodo*seguidora=lista;
    if(lista)
    {
        while(seguidora->siguiente!=NULL)
        {
            seguidora=seguidora->siguiente;
        }
    }
    return seguidora;
}

nodo* agregarEnOrdenTipoCliente(nodo* lista,nodo* nuevo)
{
    if(!lista)
        lista=nuevo;
        else
    {
        if((nuevo->cliente.tipoCliente) < (lista->cliente.tipoCliente))
        {
            lista=agregarAlPrincipio(lista,nuevo);
        }
        else
        {
            nodo * seg = lista->siguiente;//seguidora
            nodo * ante = lista;
            while((seg) && (nuevo->cliente.tipoCliente > seg->cliente.tipoCliente))
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
    return lista;
}

nodo* agregarEnOrdenPorCantidadP(nodo* lista,nodo* nuevo)
{
        if(!lista) lista=nuevo;
    else
    {
        if((nuevo->cliente.cantArticulos) < (lista->cliente.cantArticulos))
        {
            lista=agregarAlPrincipio(lista,nuevo);
        }
        else
        {
            nodo * seg = lista->siguiente;
            nodo * ante = lista;
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
    return lista;
}

void mostrarlista(nodo* lista)
{
    nodo * seg=lista;
    while(seg)
    {
        mostrarPersona(seg->cliente);
        seg=seg->siguiente;
    }
}

int contarlista(nodo* lista)
{
    nodo * seg=lista;
    int i=0;
    while(seg)
    {
        i++;
        seg=seg->siguiente;
    }
    return i;
}

nodo * borrarNodo(nodo* lista,char nombre[])
{
    nodo * seg;
    nodo * ante;
    if((lista) && strcmp(lista->cliente.nombres,nombre) ==0)
    {
        nodo * aux=lista;
        lista=lista->siguiente;
        free(aux);
        lista->anterior=NULL;

    }
    else
    {
        seg=lista;
        while((seg) && (strcmp(seg->cliente.nombres,nombre) != 0 ))
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
    return lista;
}

nodo * borrarPrimero(nodo * lista)
{
    if(lista)
    {
        nodo* aux=lista;
        lista=lista->siguiente;
        free(aux);
        lista->anterior=NULL;
    }
    return lista;
}
