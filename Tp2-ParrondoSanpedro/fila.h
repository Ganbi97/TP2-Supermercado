#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct
{
    persona cliente;
    struct nodo * siguiente;
    struct nodo * anterior;
} nodo;
typedef struct
{
    struct nodo * inicio;
    struct nodo * final;
} Fila;
/*
inicLista
crearNodoLista
agregarAlPrincipio
agregarAlFinal
agregarEnOrdenTipoCli (por tipo de cliente)
agregarEnOrdenPorCant (por cantidad de productos)
mostrarLista
borrarNodo (por nombre de cliente)
borrarPrimero (para vaciar la fila)
*/
/*
inicFila
agregar
quitar
mostrar
filaVacia
*/
#endif // FILA_H_INCLUDED
