#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "lista.h"
#include "persona.h"

typedef struct
{
    struct nodo * cabecera;
    struct nodo * ultimo;
}Fila;

void inicFila(Fila * fila);
void agregar(Fila * fila,nodo * nuevo);
persona quitar(Fila * fila);
int filaVacia(Fila * fila);
void mostrarFila(Fila * fila);
void mostrarFilaPausado(Fila * fila);
int contarElementosFila(Fila * fila);




#endif // FILA_H_INCLUDED
