#include "persona.h"
#include <stdio.h>
#include <stdlib.h>

persona crearPersona()
{
    persona aux;
    aux.tiempoEspera=0;
    aux.tiempoProcesado=0;
    aux.eliminado=0;
    printf("\nIngrese nombre de la persona: ");
    fflush(stdin);
    scanf("%s",&aux.nombres);
    printf("\nIngrese apellido de la persona: ");
    fflush(stdin);
    scanf("%s",&aux.apellido);
    printf("\nIngrese tipo de cliente: ");                ///Arreglarlo para que solo se ingrese 1 2 o 3
    scanf("%d",&aux.tipoCliente);
    printf("\nIngrese cantidad de articulos: ");
    scanf("%d",&aux.cantArticulos);
    printf("\nIngrese medio de pago: ");
    scanf("%d",&aux.medioPago);
    printf("\nIngrese el id(DNI): ");
    scanf("%d",&aux.id);
    return aux;
}

void mostrarMP(persona p)
{
    int aux=p.medioPago;
    if(aux==1)
    {
        printf("Efectivo");
    }
    else if(aux==2)
    {
        printf("Credito");
    }
    else
    {
        printf("Todos");
    }
}

void mostrarTC(persona p)
{
    int aux=p.medioPago;
    if(aux==1)
    {
        printf("Embarazada");
    }
    else if(aux==2)
    {
        printf("Jubilado");
    }
    else
    {
        printf("Cliente Comun");
    }
}

void mostrarPersona(persona p)
    printf("-------------------------------------\n");
    printf("\nNombre: %s %s",p.nombres,p.apellido);
    printf("\nId: %d",p.id);
    printf("\nTipo de cliente: ");
    mostrarTC(p);
    printf("\nMedio de pago: ");
    mostrarMP(p);
    printf("\nCantidad de articulos: %d",p.cantArticulos);
    printf("\n-------------------------------------");
}
