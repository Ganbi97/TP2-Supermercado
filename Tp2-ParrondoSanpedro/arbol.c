#include "arbol.h"
#include "string.h"
#include "fila.h"
#include "caja.h"

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

void pasarDeArbolToLineaDeCajas(nodoArbol*arbol,caja cajero[])
{
    int eleccion=0;
    printf("\nElija como se pasaran:\n1.Preorder\n2.Inorder\n3.Postorder\n");
    scanf("%d",&eleccion);
    switch(eleccion)
    {
        case 1:
        pasarpreorder(arbol,cajero);
        break;
        case 2:
        pasarinorder(arbol,cajero);
        break;
        case 3:
        pasarpostorder(arbol,cajero);
        break;
    }
}

void pasarpreorder(nodoArbol* arbol,caja cajero[])
{
        if(arbol)
    {
        addtocaja(arbol->p,cajero);
        pasarpreorder(arbol->izq,cajero);
        pasarpreorder(arbol->der,cajero);
    }
}

void  pasarinorder(nodoArbol* arbol,caja cajero[])
{
    if(arbol)
    {
        pasarinorder(arbol->izq,cajero);
        addtocaja(arbol->p,cajero);
        pasarinorder(arbol->der,cajero);
    }
}

void  pasarpostorder(nodoArbol* arbol,caja cajero[])
{
    if(arbol)
    {
        pasarpostorder(arbol->izq,cajero);
        pasarpostorder(arbol->der,cajero);
        addtocaja(arbol->p,cajero);
    }
}

void addtocaja(persona p,caja cajero[])
{
    int i=0;
    int flag=0;
    int metido=0;
    while(i<7&&metido==0)
    {
        if(FilaVacia(&cajero[i].filita)==1||cajacorrecta(p,cajero,i)==1)
        {
            flag=i;
            metido=1;
        }
        else if(cajacorrecta(p,cajero,i)==1)
        {
            flag=agarrarmenor(flag,cajero,i);
        }
        i++;
    }
    cajero[flag]=agregarClienteACaja(cajero,p,flag);
}

int cajacorrecta(persona p,caja cajero[],int i)
{
    int resultado=0;
    if(cajero[i].medioPago==p.medioPago)
    {
        resultado=1;
    }
    else if(cajero[i].medioPago==3&&p.medioPago==3)
    {
        resultado=1;
    }
    if(cajero[i].abiertaOcerrada==0)
    {
        resultado=0;
    }
    return resultado;
}

