#ifndef LIBRERIAMADRE_H_INCLUDED
#define LIBRERIAMADRE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "arbol.h"
#include "string.h"
#include "caja.h"
#include "fila.h"
#include "persona.h"

void MENU(char nombre[],char cajeros[],nodoArbol *arbol,caja cajita[]);
nodoArbol *opciones(int o,char nombre[],char archivo[],nodoArbol *arbol,caja cajita[],int *bandera,int *control);
void mostrarMenu();
void submenuCaja();
void submenuPersona();
void submenuArbol();





#endif // LIBRERIAMADRE_H_INCLUDED
