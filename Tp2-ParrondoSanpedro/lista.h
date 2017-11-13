#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    persona cliente;
    struct nodo * siguiente;
    struct nodo * anterior;
} nodo;


nodo*inicLista();
nodo*crearNodoLista(persona p);
nodo*agregarAlPrincipio(nodo*lista,nodo*nuevo);
nodo*agregarAlFinal(nodo*lista,nodo*nuevo);
nodo*buscarElUltimo(nodo*lista);
nodo*agregarEnOrdenTipoCliente(nodo*lista,nodo*nuevo);
nodo*agregarEnOrdenPorCant(nodo*lista,nodo*nuevo);
void mostrarLista(nodo*lista);
nodo*borrarNodo(nodo*lista,char nombre[40]);
nodo*borrarPrimero(nodo*lista);

#endif // LISTA_H_INCLUDED
