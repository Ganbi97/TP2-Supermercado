#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "arbol.h"
#include <string.h>
#include "caja.h"
#include "fila.h"
#include "persona.h"
#include "libreriamadre.h"
#define dim 8
/*
nodoArbol * opciones(int o,char nombre[],char archivo[],nodoArbol * arbol,caja cajita[dim],int *bandera,int *control)
{
        float tEjecucion = 0,tRespuesta = 0;
        int totalEjecucion = 0,totalRespuesta = 0,pos = 0,i = 0,posicion = 0,cont=0;
        char validacion;
        printf("\n");
        switch(o)
        {
        case 1:
            system("cls");
            MostrarArchivo(nombre);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if(!arbol)
            {
                arbol=pasarArchivoArbol(arbol,nombre);
                printf("Los datos se pasaron exitosamente\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("El arbol se encuentra cargado\n");
                system("pause");
                system("cls");
            }
            break;

        case 3:
            system("cls");
            if(arbol)
            {
                modosDeMuestraDelArbol(arbol);
                system("pause");
                system("cls");
            }

            else
            {
                printf("Cargue el arbol primero\n");
                system("pause");
                system("cls");
            }
            break;

        case 4:
            system("cls");
            printf("Las cajas se cargaron exitosamente\n");
            pasarArchivoAcajas(archivo,cajita,dim);
            *bandera=1;
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            if(*bandera == 0)
            {
                printf("Los cajeros no estan cargados\n");
                system("pause");
                system("cls");
            }
            else
            {
                abrirTodasLasCajas(cajita,dim);
                printf("Las cajas se abrieron con exito\n");
                system("pause");
                system("cls");
            }
            break;

        case 6:
            system("cls");
            if(*bandera == 0)
            {
                printf("Los cajeros no estan cargados\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Eliga la caja a abrir/cerrar :\n");
                scanf("%d",&i);
                abriOcerrarCaja(cajita,i-1);
                if(cajita[i-1].abiertaOcerrada == 0)
                {
                    printf("La caja %d fue cerrada con exito \n",i);
                }
                else
                {
                    printf("La caja %d fue abierta con exito \n",i);
                }
                system("pause");
                system("cls");
            }
            break;

        case 7:
            system("cls");
            if(*bandera == 0)
            {
                printf("Por favor, cargue los datos del archivo al arreglo\n");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                mostrarCajas(cajita,dim);
                system("pause");
                system("cls");
            }
            break;

        case 8:
            system("cls");
            if( (!arbol) || (*bandera == 0) )
            {
                if(!arbol)
                {
                    printf("El arbol no esta cargado\n");
                    system("pause");
                    system("cls");
                }
                if(*bandera == 0)
                {
                    printf("Las cajas no estan cargadas\n");
                    system("pause");
                    system("cls");
                }

            }
            else
            {
                if(*control==0)
                {
                    cont=ElegirModoDePasarPersonasAlArreglo(arbol,cajita);
                    printf("Se cargaron %d clientes correctamente\n",cont);
                    *control=1;
                }
                else
                {
                    *control=1;
                    vaciarCajas(cajita,8);
                    cont=ElegirModoDePasarPersonasAlArreglo(arbol,cajita);
                    printf("Se cargaron %d clientes correctamente\n",cont);
                    *control=0;
                }
                system("pause");
                system("cls");
            }
            break;

        case 9:
            system("cls");
            int num = 0;
            if( *bandera == 0 )
            {
                printf("Por favor, cargue los datos del archivo al arreglo\n");
                system("pause");
                system("cls");
            }
            else
            {
                MostrarDeterminadaCaja(cajita);
                system("pause");
                system("cls");
            }
            break;

        case 10:
            system("cls");
            if(*bandera == 0)
            {
                printf("Por favor, cargue los datos del archivo al arreglo\n");
                system("pause");
                system("cls");
            }
            else
            {
                MeterPersona(cajita,dim);
                system("pause");
                system("cls");
            }
            break;

        case 11:
            system("cls");
            if( (*bandera==0) || (cajita[0].abiertaOcerrada!=1) )
            {
                if ( *bandera==0 )
                {
                    printf("Por favor, cargue los datos del archivo al arreglo\n");
                    system("pause");
                    system("cls");
                }

                if(cajita[0].abiertaOcerrada!=1)
                {
                    printf("Las cajas estan cerradas\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                atenderClientes(cajita,dim);
                mostrarCajas(cajita,dim);
                system("pause");
                system("cls");
            }
            break;

        case 12:
            system("cls");
            if(*bandera == 0)
            {
                if (*bandera == 0)
                {
                    printf("Por favor, cargue los datos del archivo al arreglo\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Eliga la caja a mostrar :\n");
                scanf("%d",&posicion);
                if(strcmpi(cajita[posicion-1].algoritmoPlanificacion,"rr") == 0)
                {
                    cont=sacarClientesDeCajas(cajita,posicion-1,0);
                    mostrarCajaPausado(cajita,posicion-1);
                }
                else
                {
                    cont=sacarClientesDeCajas(cajita,posicion-1,0);
                    leerCaja(cajita[posicion-1]);
                }
                    printf("Se atendieron %d clientes \n",cont);
                    system("pause");
                    system("cls");
                }
            break;

        case 13:
            system("cls");
            if(*bandera  == 0)
            {
                printf("Los cajeros no estan cargados\n");
                system("pause");
                system("cls");
            }
            else
            {
                pos=ElegirEnCaja(cajita);
                calcularTiempoDeCaja(cajita,pos,&tEjecucion,&tRespuesta,&totalEjecucion,&totalRespuesta);
                printf("Tiempo total de ejecucion: %d\n",totalEjecucion);
                printf("Tiempo total de respuesta: %d\n",totalRespuesta);
                printf("Tiempo promedio de ejecucion: %.2f\n",tEjecucion);
                printf("Tiempo promedio de respuesta: %.2f\n",tRespuesta);
                system("pause");
                system("cls");
            }
            break;

        case 14:
            system("cls");
            if(*bandera  == 0)
            {
                printf("Los cajeros no estan cargados\n");
                system("pause");
                system("cls");
            }
            else
            {
                calcularTiemposTotales(cajita,dim,&tEjecucion,&tRespuesta,&totalEjecucion,&totalRespuesta);
                printf("Tiempo total de ejecucion: %d\n",totalEjecucion);
                printf("Tiempo total de respuesta: %d\n",totalRespuesta);
                printf("Tiempo promedio de ejecucion: %.2f\n",tEjecucion);
                printf("Tiempo promedio de respuesta: %.2f\n",tRespuesta);
                system("pause");
                system("cls");
            }
            break;
        }

        return arbol;
}

void MENU(char nombre[],char cajeros[],nodoArbol * arbol,caja cajita[dim])
{
    int bandera=0,control=0;
    int opcion=0;
    printf("\n");


    while(opcion != 15)
    {
        mostrarMenu();
        printf("\n");
        printf("Eliga una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        arbol=opciones(opcion,nombre,cajeros,arbol,cajita,&bandera,&control);
        printf("\n");
    }

    system("cls");
    printf(" HASTA LUEGO !!!!!!!\n");

}

void mostrarMenu()
{
    system ("color B");
    printf("     ------------------Supermercado--------------------\n\n");

    printf("1)----> Mostrar archivo\n");
    printf("2)----> Pasar de archivo a arboles\n");
    printf("3)----> Mostrar arboles\n");
    printf("4)----> Pasar cajas de archivo a arreglo\n");
    printf("5)----> Abrir todas las cajas\n");
    printf("6)----> Abrir/cerrar determinada caja\n");
    printf("7)----> Mostrar Cajas\n");
    printf("8)----> Pasar clientes del arbol a caja\n");
    printf("9)----> Mostrar una caja a eleccion\n");
    printf("10)---> Agregar clientes en tiempo X\n");
    printf("11)---> Procesar colas\n");
    printf("12)---> Procesar colas individual\n");
    printf("13)---> Calcular tiempo individual\n");
    printf("14)---> Calcular tiempo total\n\n");

    printf("15)---> SALIR\n");
}
*/
nodoArbol * opciones(int o,char nombre[],char archivo[],nodoArbol * arbol,caja cajita[dim],int *bandera,int *control)
{
    float tEjecucion = 0,tRespuesta = 0;
    int totalEjecucion = 0,totalRespuesta = 0,pos = 0,i = 0,posicion = 0,cont=0;
    char validacion;
    persona borrada;
    printf("\n");
    int subopcion;
    switch(o)
    {
    case 1:
        subopcion=0;
        system("cls");
        while(subopcion!=4)
        {
            submenuPersona();
            printf("\n");
            printf("Eliga una opcion: ");
            fflush(stdin);
            scanf("%d",&subopcion);
            switch(subopcion)
            {
            case 1:
                system("cls");
                AgregarPersonas(nombre);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                MostrarArchivo(nombre);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                if(!arbol)
                {
                    arbol=pasarArchivoArbol(arbol,nombre);
                    printf("Los datos se pasaron exitosamente\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("El arbol se encuentra cargado\n");
                    system("pause");
                    system("cls");
                }
                break;
            }
            printf("\n");
        }
        break;
    case 2:
        subopcion=0;
        system("cls");
        while(subopcion!=4)
        {
            submenuArbol();
            printf("\n");
            printf("Eliga una opcion: ");
            fflush(stdin);
            scanf("%d",&subopcion);
            switch(subopcion)
            {
            case 1:
                system("cls");
                if(arbol)
                {
                    modosDeMuestraDelArbol(arbol);
                    system("pause");
                    system("cls");
                }

                else
                {
                    printf("Cargue el arbol primero\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                system("cls");
                if(arbol)
                {
                    MostrarPosOrden(arbol);
                    char nomborr[30];
                    persona aux;
                    printf("Ingrese el nombre de la persona a borrar: ");
                    fflush(stdin);
                    scanf("%s",&nomborr);
                    aux=crearPaborrar(nomborr);
                    arbol=borrarUnNodoArbol(arbol,aux);
                    mostrarArbol(arbol);
                }

                else
                {
                    printf("Cargue el arbol primero\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                system("cls");
                if(!arbol)
                {
                    if(!arbol)
                    {
                        printf("El arbol no esta cargado\n");
                        system("pause");
                        system("cls");
                    }

                }
                else
                {
                    if(*control==0)
                    {
                        cont=ElegirModoDePasarPersonasAlArreglo(arbol,cajita);
                        printf("Se cargaron %d clientes correctamente\n",cont);
                        *control=1;
                    }
                    else
                    {
                        *control=1;
                        vaciarCajas(cajita,8);
                        cont=ElegirModoDePasarPersonasAlArreglo(arbol,cajita);
                        printf("Se cargaron %d clientes correctamente\n",cont);
                        *control=0;
                    }
                    system("pause");
                    system("cls");
                }
                break;
            }
            printf("\n");
        }
        break;
    case 3:
        subopcion=0;
        system("cls");
        while(subopcion!=8)
        {
            submenuCaja();
            printf("\n");
            printf("Eliga una opcion: ");
            fflush(stdin);
            scanf("%d",&subopcion);
            switch(subopcion)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            }
            printf("\n");
        }
        break;
    }
    return arbol;
}


void MENU(char nombre[],char cajeros[],nodoArbol * arbol,caja cajita[dim])
{
    int bandera=0,control=0;
    int opcion=0;
    printf("\n");
    while(opcion != 4)
    {
        mostrarMenu();
        printf("\n");
        printf("Eliga una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        arbol=opciones(opcion,nombre,cajeros,arbol,cajita,&bandera,&control);
        printf("\n");
    }
    system("cls");
    printf("\nGood Bye!\n");
}

void mostrarMenu()
{
    system("color B");
    printf("     -------------Supermercado-Nueva-Luna(ah-re-chino)-------------    \n\n");
    printf("[1]Administrar Personas\n");
    printf("[2]Administrar Arbol\n");
    printf("[3]Administrar Cajas\n");
    printf("\n\n[4]SALIR\n");
}

void submenuArbol()
{
    printf("[1]Ver arbol\n");
    printf("[2]Borrar un Arbol\n");
    printf("[3]Pasar del arbol a las cajas\n");
    printf("\n\n[4]SALIR\n");
}

void submenuPersona()
{
    printf("[1]Agregar persona\n");
    printf("[2]Ver archivo de personas\n");
    printf("[3]Pasar del archivo al arbol\n");
    printf("\n\n[4]SALIR\n");
}

void submenuCaja()
{
    printf("[1]Abrir todas las cajas\n");
    printf("[2]Abrir/cerrar caja especifica\n");
    printf("[3]Mostrar cajas\n");
    printf("--------------------------------------\n");
    printf("[4]Agregar clientes en x tiempo\n");
    printf("[5]Procesar colas\n");
    printf("[6]Procesar colas individualmente\n");
    printf("[7]Calcular tiempo individual\n");
    printf("[8]Calcular tiempo total\n");
    printf("\n\n[9]SALIR\n");
}
