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
/*
inicArbol
crearNodoArbol
insertarNodoArbol (ordenado por nombre o apellido)
mostrarArbol  (recorriendo inOrder, postOrder, preOrder)
borrarUnNodoArbol (buscarlo por nombre o apellido)
pasarDeArbolToLineaDeCajas (recorriendo inOrder, postOrder, preOrder)
*/


#endif // ARBOL_H_INCLUDED
