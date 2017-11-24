#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "string.h"
#include "caja.h"
#include "fila.h"
#define dim 8
nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(persona a)
{
    nodoArbol * aux=malloc(sizeof(nodoArbol));

    strcpy(aux->p.nombre,a.nombre);
    strcpy(aux->p.apellido,a.apellido);
    aux->p.cantArticulos=a.cantArticulos;
    aux->p.tiempoDeEspera=a.tiempoDeEspera;
    aux->p.tiempoProcesado=a.tiempoProcesado;
    aux->p.tipo_cliente=a.tipo_cliente;
    aux->p.tipo_pago=a.tipo_pago;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}

nodoArbol * insertarNodoArbol(nodoArbol * arbol,persona nueva)
{
    if(!arbol) arbol=crearNodoArbol(nueva);
    else
    {
        if(strcmpi(nueva.nombre,arbol->p.nombre) < 0)
        {
            arbol->izq=insertarNodoArbol(arbol->izq,nueva);
        }
        else
        {
            arbol->der=insertarNodoArbol(arbol->der,nueva);
        }
    }
    return arbol;
}

void mostrarArbol(nodoArbol * aux)
{
    if(aux)
    {
        printf("Nombre y Apellido: %s",aux->p.nombre);
        printf(" %s\n",aux->p.apellido);
        printf("Cantidad Articulos: %d\n",aux->p.cantArticulos);
        printf("Tiempo de espera: %d\n",aux->p.tiempoDeEspera);
        printf("Tiempo de procesado: %d\n",aux->p.tiempoProcesado);
        printf("Tipo de cliente: %d",aux->p.tipo_cliente);
        tipodeCliente(aux->p.tipo_cliente);
        printf("Tipo de pago: %d",aux->p.tipo_pago);
        tipodePago(aux->p.tipo_pago);
        puts("-------------------------");
    }
}

void MostrarpreOrden(nodoArbol * aux)
{
    if(aux)
    {
        mostrarArbol(aux);
        MostrarpreOrden(aux->izq);
        MostrarpreOrden(aux->der);
    }
}

void MostrarInOrden(nodoArbol * aux)
{
    if(aux)
    {
        MostrarpreOrden(aux->izq);
        mostrarArbol(aux);
        MostrarpreOrden(aux->der);
    }
}

void MostrarPosOrden(nodoArbol * aux)
{
    if(aux)
    {
        MostrarpreOrden(aux->izq);
        MostrarpreOrden(aux->der);
        mostrarArbol(aux);
    }
}

void tipodeCliente(int cliente)
{
    if(cliente == 1) printf("(Embarazada)\n");
    else
    {
        if(cliente == 2) printf("(Jubilado)\n");
        else printf("(Normal)\n");
    }
}

void tipodePago(int pago)
{
    if(pago == 1) printf("(Efectivo)\n");
    else
    {
        if(pago == 2) printf("(Tarjeta o Debito)\n");
        else printf("(Todos)\n");
    }
}

void preOrden(nodoArbol * aux,Fila * filita)
{
    if(aux)
    {
        agregar(filita,crearNodo(aux->p));
        preOrden(aux->izq,filita);
        preOrden(aux->der,filita);
    }
}

void inOrden(nodoArbol * aux,Fila * filita)
{
    if(aux)
    {
        inOrden(aux->izq,filita);
        agregar(filita,crearNodo(aux->p));
        inOrden(aux->der,filita);
    }
}

void posOrden(nodoArbol * aux,Fila * filita)
{
    if(aux)
    {
        posOrden(aux->izq,filita);
        posOrden(aux->der,filita);
        agregar(filita,crearNodo(aux->p));
    }

}

nodoArbol * nodoMasDerecho(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(!arbol->der)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->der);
    }
    return aux;
}

nodoArbol * nodoMasIzquierdo(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(!arbol->izq)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izq);
    }
    return aux;
}


nodoArbol * borrarUnNodoArbol(nodoArbol * arbol,persona a)
{
    if(arbol)
    {
        if(strcmpi(a.nombre,arbol->p.nombre) > 0)
        {
            arbol->der=borrarUnNodoArbol(arbol->der,a);
        }
        else if (strcmpi(a.nombre,arbol->p.nombre) < 0)
        {
            arbol->izq=borrarUnNodoArbol(arbol->izq,a);
        }
        else
        {
            if(arbol->izq)
            {
                arbol->p=(nodoMasDerecho(arbol->izq))->p;
                arbol->izq=borrarUnNodoArbol(arbol->izq,arbol->p);
            }
            else if(arbol->der)
            {
                arbol->p=(nodoMasIzquierdo(arbol->der))->p;
                arbol->der=borrarUnNodoArbol(arbol->der,arbol->p);
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


int pasarDeArbolToLineaDeCajas(nodoArbol * arbol,caja cajero[],int dimension,int elegir)
{
    int contador = 0;
    Fila aux;
    inicFila(&aux);
    persona p;
    elegirOrden(arbol,&aux,elegir); // esto devuelve el arbol recorrido por el orden elegido y la fila armada con todas las personas
    while(filaVacia(&aux)) // recorro la fila hasta q no tenga datos
    {
        p=quitar(&aux);
        agregarClienteACaja(cajero,p,dimension);
        contador++;
    }
    return contador;
}

void elegirOrden(nodoArbol * arbol,Fila * filita,int elegir)
{
    switch(elegir)
    {
    case 1:
        preOrden(arbol,filita);
        break;

    case 2:
        inOrden(arbol,filita);
        break;

    case 3:
        posOrden(arbol,filita);
        break;
    }
}

nodoArbol * pasarArchivoArbol(nodoArbol * arbol,char nombre[])
{
    FILE * archi=fopen(nombre,"rb");
    persona aux;
    if(archi)
    {
        while((fread(&aux,sizeof(persona),1,archi)) > 0 )
        {
            arbol=insertarNodoArbol(arbol,aux);
        }
    }
    fclose(archi);
    return arbol;
}

void modosDeMuestraDelArbol(nodoArbol * arbol)
{
    int opcion=0;
    printf("  Seleccione el modo de mostrar el arbol\n");
    printf("    1)----->Inorden\n");
    printf("    2)----->Preorden\n");
    printf("    3)----->PosOrden\n");
    printf("    Opcion:");
    fflush(stdin);
    scanf("%d",&opcion);
    while((opcion < 1) || (opcion > 3))
    {
        printf("El valor ingresado no coincide\n");
        printf("Por favor, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    switch(opcion)
    {
    case 1:
        MostrarInOrden(arbol);
        break;

    case 2:
        MostrarpreOrden(arbol);
        break;

    case 3:
        MostrarPosOrden(arbol);
        break;
    }
}

int ElegirModoDePasarPersonasAlArreglo(nodoArbol * arbol,caja cajita[])
{
    int opcion=0,contador=0;

    printf("  Seleccione el modo de cargar el arbol\n");
    printf("    1)----->Inorden\n");
    printf("    2)----->Preorden\n");
    printf("    3)----->PosOrden\n");
    printf("    Opcion:");
    fflush(stdin);
    scanf("%d",&opcion);

    while(((opcion < 1) || (opcion > 3)))
    {
        printf("El valor ingresado no coincide\n");
        printf("Por favor, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    switch(opcion)
    {
    case 1:
        printf("Las personas se han cargado exitosamente a las cajas\n");
        contador=pasarDeArbolToLineaDeCajas(arbol,cajita,dim,1);
        break;

    case 2:
        printf("Las personas se han cargado exitosamente a las cajas\n");
        contador=pasarDeArbolToLineaDeCajas(arbol,cajita,dim,2);
        break;

    case 3:
        printf("Las personas se han cargado exitosamente a las cajas\n");
        contador=pasarDeArbolToLineaDeCajas(arbol,cajita,dim,3);
        break;

    }

    return contador;
}

persona crearPaborrar(char nombrr[])
{
    persona aux;
    strcpy(aux.nombre,nombrr);
    return aux;
}
