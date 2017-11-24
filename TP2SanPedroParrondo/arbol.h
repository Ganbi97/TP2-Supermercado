#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "persona.h"
#include "fila.h"
#include "caja.h"
typedef struct
{
     persona p;
     struct nodoArbol * izq;
     struct nodoArbol * der;
}nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(persona a);
nodoArbol * insertarNodoArbol(nodoArbol * arbol,persona nueva);
nodoArbol * nodoMasDerecho(nodoArbol * arbol);
nodoArbol * nodoMasIzquierdo(nodoArbol * arbol);
nodoArbol * borrarUnNodoArbol(nodoArbol * arbol,persona a);
nodoArbol * pasarArchivoArbol(nodoArbol * arbol,char nombre[]);
void elegirOrden(nodoArbol * arbol,Fila * filita,int elegir);
int pasarDeArbolToLineaDeCajas(nodoArbol * arbol,caja cajero[],int dimension,int elegir);
void preOrden(nodoArbol * aux,Fila * filita);
void inOrden(nodoArbol * aux,Fila * filita);
void posOrden(nodoArbol * aux,Fila * filita);
void tipodeCliente(int cliente);
void tipodePago(int pago);
void mostrarArbol(nodoArbol * aux);
void MostrarpreOrden(nodoArbol * aux);
void MostrarInOrden(nodoArbol * aux);
void MostrarPosOrden(nodoArbol * aux);
void modosDeMuestraDelArbol(nodoArbol * arbol);
int ElegirModoDePasarPersonasAlArreglo(nodoArbol * arbol,caja cajita[]);
persona crearPaborrar(char nombrr[]);

#endif // ARBOL_H_INCLUDED
