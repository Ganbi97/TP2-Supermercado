#include "arbol.h"
#include "string.h"

nodoArbol*inicArbol()
{
    return NULL;
}

nodoArbol*crearNodoArbol(persona per)
{
    nodoArbol*arbol=(nodoArbol*)malloc(sizeof(arbol));
    arbol->p=per;
    arbol->izq=NULL;
    arbol->der=NULL;
    return arbol;
}

nodoArbol* insertarNodoArbol(nodoArbol*arbol,persona per)
{
    if(arbol=NULL)
    {
        arbol=crearNodoArbol(per);
    }
    else
    {
        if(strcmp(arbol->p.apellido,per.apellido)>=0)
        {
            arbol->der=insertarNodoArbol(arbol,per);
        }
        else
        {
            arbol->izq=insertarNodoArbol(arbol,per);
        }
    }
}

void mostrarArbolPreO(nodoArbol* arbol)
{
    mostrarPersona(arbol->p);
    mostrarArbolPreO(arbol->izq);
    mostrarArbolPreO(arbol->der);
}

void mostrarArbolInO(nodoArbol* arbol)
{
    mostrarArbolInO(arbol->izq);
    mostrarPersona(arbol->p);
    mostrarArbolInO(arbol->der);
}
void mostrarArbolPostO(nodoArbol* arbol)
{
    mostrarArbolPostO(arbol->izq);
    mostrarArbolPostO(arbol->der);
    mostrarPersona(arbol->p);
}

nodoArbol* borrarUnNodoArbol(nodoArbol* arbol,char dato[40])
{
    if(arbol)
    {
        if(strcmpi(dato,arbol->p.nombres)<0)
        {
            arbol->der=borrarUnNodoArbol(arbol->der,dato);
        }
        else if(strcmpi(dato,arbol->p.nombres)>0)
        {
            arbol->izq=borrarUnNodoArbol(arbol->izq,dato);
        }
        else
        {
            if(arbol->der)
            {
                arbol->p=(nodomasderecha(arbol->der))->p;
                arbol->der=borrarUnNodoArbol(arbol->der,arbol->p.nombres);
            }
            else if(arbol->izq)
            {
                arbol->p=(nodomasizquierda(arbol->izq))->p;
                arbol->izq=borrarUnNodoArbol(arbol->izq,arbol->p.nombres);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
    }
    return arbol;
}

nodoArbol* nodomasderecha(nodoArbol* arbol)
{
    nodoArbol* aux;
    if(!arbol->der)
    {
        aux=arbol;

    }
    else
    {
        arbol=nodomasderecha(arbol->der);
    }
          return aux;
}

nodoArbol* nodomasizquierda(nodoArbol* arbol)
{
    nodoArbol* aux;
    if(!arbol->izq)
    {
        aux=arbol;

    }
    else
    {
        arbol=nodomasizquierda(arbol->izq);
    }
          return aux;
}
