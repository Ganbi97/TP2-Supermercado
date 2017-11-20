#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "persona.h"

typedef struct
{
      persona p;
      struct nodoArbol * izq;
      struct nodoArbol * der;
} nodoArbol;



nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(persona per);
nodoArbol* insertarNodoArbol(nodoArbol*arbol,persona per);
void mostrarArbolPostO(nodoArbol* arbol);
void mostrarArbolInO(nodoArbol* arbol);
void mostrarArbolPreO(nodoArbol* arbol);
nodoArbol* borrarUnNodoArbol(nodoArbol* arbol,char dato[40]);
nodoArbol* nodomasizquierda(nodoArbol* arbol);
nodoArbol* nodomasderecha(nodoArbol* arbol);
/*
void pasarDeArbolToLineaDeCajas(nodoArbol*arbol,caja cajero[]);
void pasarpreorder(nodoArbol* arbol,caja cajero[]);
void  pasarinorder(nodoArbol* arbol,caja cajero[]);
void  pasarpostorder(nodoArbol* arbol,caja cajero[]);
void addtocaja(persona p,caja cajero[]);
int cajacorrecta(persona p,caja cajero[],int i);
*/


#endif // ARBOL_H_INCLUDED
