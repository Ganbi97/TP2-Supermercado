#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"


typedef struct{

    persona cliente;
    struct nodo * siguiente;
    struct nodo * anterior;
}nodo;

nodo * inicNodo();
nodo * crearNodo(persona a);
nodo * agregarPrincipio(nodo * Lista,nodo * nuevo);
nodo * agregarFinal(nodo * Lista,nodo * nuevo);
nodo * agregarEnOrdenTipoCli(nodo * Lista,nodo * nuevo);
nodo * agregarEnOrdenPorCant(nodo * Lista,nodo * nuevo);
nodo * borrarNodo(nodo * Lista,char nombre[]);
nodo * copiarArchivoALista(nodo * Lista,char nombre[]);
nodo * buscarUltimo(nodo * Lista);
nodo * borrarPrimero(nodo * Lista);
void mostrarLista(nodo * Lista);
void mostrarListaPausado(nodo * Lista);
void mostrarNodo(persona cliente);


#endif // LISTA_H_INCLUDED
