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
