#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "lista.h"
#include "persona.h"


void inicFila(Fila * fila)
{
    fila->cabecera=inicNodo();
    fila->ultimo=inicNodo();
}

void agregar(Fila * fila,nodo * nuevo)
{
    if(!fila->cabecera) fila->cabecera=nuevo;
    else
    {
        fila->cabecera=agregarFinal(fila->cabecera,nuevo);
    }
    fila->ultimo=nuevo;
}

persona quitar(Fila * fila)
{
    persona a;
    if(fila->cabecera)
    {
        nodo * aux=fila->cabecera;
        nodo * sig=aux->siguiente;
        if(fila->cabecera != fila->ultimo)
        {
            sig->anterior=NULL;
            fila->cabecera=sig;
        }
        else
        {
            fila->cabecera=NULL;
            fila->ultimo=NULL;
        }
        a=aux->cliente;
        free(aux);
    }
    return a;
}

int filaVacia(Fila * fila)
{
    int rta=0;
    if(fila->cabecera)
    {
        rta=1;
    }
    return rta;
}

void mostrarFila(Fila * fila)
{
    if(fila->cabecera)
    {
       nodo * aux=fila->cabecera;
       mostrarLista(aux);
    }
    else
    {
        printf("La fila esta vacia \n");
    }
}

void mostrarFilaPausado(Fila * fila)
{
    if(fila->cabecera)
    {
       nodo * aux=fila->cabecera;
       mostrarListaPausado(aux);
    }
    else
    {
        printf("La fila esta vacia \n");
    }
}

int contarElementosFila(Fila * fila)
{
    int contador = 0;
    if(fila->cabecera)
    {
       nodo * aux=fila->cabecera;
       while(aux)
       {
           contador++;
           aux=aux->siguiente;
       }

    }
    return contador;
}
