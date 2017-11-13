#include "Fila.h"
#include "persona.h"
#include "lista.h"

Fila inicFila(Fila Filanueva)
{
    Filanueva.inicio=inicLista();
    Filanueva.fin=inicLista();
    return Filanueva;
}

int FilaVacia(Fila*filita)
{
    int resultado=0;
    if(!filita->inicio)
        resultado=1;
    return resultado;
}

void agregar(Fila* filita,nodo* nuevonodo)
{
    if(!filita->inicio)
    {
        filita->inicio=nuevonodo;
    }
    else
    {
        filita->inicio=agregarAlFinal(filita->inicio,nuevonodo);
    }
    filita->fin=nuevonodo;
}


persona quitar(Fila * filita)
{
    persona a;
    if(filita->inicio)
    {
        nodo * aux=filita->inicio;
        nodo * sig=aux->siguiente;
        if(filita->inicio != filita->fin)
        {
            sig->anterior=NULL;
            filita->inicio=sig;
        }
        else
        {
            filita->inicio=NULL;
            filita->fin=NULL;
        }
        a=aux->cliente;
        free(aux);
    }
    return a;
}

void mostrarFila(Fila *filita)
{
    if(filita->inicio)
    {
        nodo* aux=filita->inicio;
        mostrarLista(aux);
    }
    else
    {
        printf("404 not found: La Fila esta vacia \n");
    }
}
