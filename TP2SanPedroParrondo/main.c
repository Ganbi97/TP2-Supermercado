#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "arbol.h"
#include "lista.h"
#include "fila.h"
#include "caja.h"
#include "libreriamadre.h"
int main()
{
    char nombre[20]="archivos.dat";
    char archivo[20]="cajas.dat";
    caja cajita[8]; // bajo de 8 a 4
    nodoArbol * arbol;
    arbol=inicArbol();
    MENU(nombre,archivo,arbol,cajita);
    return 0;
}
