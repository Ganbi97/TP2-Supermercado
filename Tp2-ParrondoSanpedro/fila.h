#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "lista.h"


typedef struct
{
    struct nodo * inicio;
    struct nodo * fin; //final es una palabra reservada del sistema segun codeblocks
} Fila;

Fila inicFila(Fila Filanueva);
persona quitar(Fila* filita);
void agregar(Fila* filita,nodo* nuevonodo);
void mostrar(Fila* filita);
int FilaVacia(Fila* filita);

#endif // FILA_H_INCLUDED
