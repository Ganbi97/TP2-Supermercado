#include <stdio.h>
#include <stdlib.h>
#include "caja.h"
#include "persona.h"
#define quantum 9

int agregarCaja(caja cajero[],int dimension)
{
    int i = 0;
    char control='s';
    while((control == 's') && (i < dimension))
    {
        cargarCajas(cajero,i);

        printf("Desea continuar?: ");
        fflush(stdin);
        scanf("%c",&control);

        i++;

        system("cls");

    }
    return i;
}

void cargarCajas(caja cajero[],int i)
{
    printf("Ingrese el numero de caja: ");
    scanf("%d",&cajero[i].nro_de_caja);
    printf("Ingrese el nombre del cajero: ");
    fflush(stdin);
    gets(cajero[i].nombreCajero);
    printf("Ingrese el metodo de pago: 1(Efectivo), 2(Credito o Debito), 3(Todos) ");
    scanf("%d",&cajero[i].medioPago);
    printf("Ingrese 1(Abierta) o 0(Cerrada): ");
    scanf("%d",&cajero[i].abiertaOcerrada);
    printf("Determine el algoritmo de planificacion: ");
    fflush(stdin);
    gets(cajero[i].algoritmoPlanificacion);
    inicFila(&cajero[i].filita);
}

void mostrarCajas(caja cajero[],int dimension)
{
    int i = 0;

    while(i < dimension)
    {
        leerCaja(cajero[i]);
        i++;
    }

}

void leerCaja(caja cajero)
{
    printf("Numero de caja: %d\n",cajero.nro_de_caja);
    printf("Nombre del cajero: %s\n",cajero.nombreCajero);
    printf("Tipo de pago: %d ",cajero.medioPago);tipodePago(cajero.medioPago);
    printf("%d",cajero.abiertaOcerrada);comprobar(cajero.abiertaOcerrada);
    printf("Algoritmo de planificacion: %s\n",cajero.algoritmoPlanificacion);
    printf("Personas: \n\n");
    mostrarFila(&cajero.filita);
    puts("--------------------------");

}

void mostrarCajaPausado(caja cajero[],int posicion)
{
    nodo * aux=cajero[posicion].filita.inicio;
    leerCajaPausado(cajero[posicion]);
}

void leerCajaPausado(caja cajero)
{
    printf("Numero de caja: %d\n",cajero.nro_de_caja);
    printf("Nombre del cajero: %s\n",cajero.nombreCajero);
    printf("Tipo de pago: %d ",cajero.medioPago);tipodePago(cajero.medioPago);
    printf("%d",cajero.abiertaOcerrada);comprobar(cajero.abiertaOcerrada);
    printf("Algoritmo de planificacion: %s\n",cajero.algoritmoPlanificacion);
    printf("Personas: \n\n");
    mostrarFilaPausado(&cajero.filita);
    puts("--------------------------");

}

void comprobar(int rta) // auxiliar para que muestre 1 si esta abierto o 0 si la caja esta cerrada
{
    if(rta==0)
    {
        printf("(Cerrado)\n");
    }
    else
    {
        printf("(Abierto)\n");
    }

}

void abriOcerrarCaja(caja cajero[],int i)
{
    if(!filaVacia(&cajero[i].filita))
    {
        if(cajero[i].abiertaOcerrada == 1) cajero[i].abiertaOcerrada=0;
        else cajero[i].abiertaOcerrada=1;
    }
    else
    {
        printf("La caja tiene personas, no se puede cerrar \n");
    }

}

void abrirTodasLasCajas(caja cajero[],int dimension)
{
    int i = 0;
    while(i < dimension)
    {
        if(cajero[i].abiertaOcerrada == 0)
        {
            cajero[i].abiertaOcerrada = 1;
        }
        i++;
    }
}

caja buscarCaja(caja cajero[],int dimension,int pago)
{
    int i = 0;
    caja aux;
    while(i < dimension)
    {
        if(pago == cajero[i].medioPago)
        {
            aux=cajero[i];
        }
        i++;
    }
    return aux;
}

void agregarClienteACaja(caja cajero[],persona p,int dimension)
{
    int i = 0,cantidad = 0,control = 0;
    while((i < dimension) && (control == 0))
    {
        cantidad=contarElementosFila(&cajero[i].filita);
        if((cajero[i].abiertaOcerrada == 1) && (cantidad < 6)) // cantidad es para que las cajas queden balanceadas
        {
            if((cajero[i].medioPago == p.medioPago))
            {
                planificador(cajero,i,p);
                control = 1;
            }
        }
        i++;
    }
}

void planificador(caja cajero[],int i,persona p)
{
    nodo * carro=inicNodo();
    carro=crearNodo(p);
    agregar(&cajero[i].filita,carro);
    if(strcmpi(cajero[i].algoritmoPlanificacion,"sjf") == 0)
    {
        if(filaVacia(&cajero[i].filita)) ordenarporArticulos(&cajero[i].filita);
    }
    if(strcmpi(cajero[i].algoritmoPlanificacion,"prioridad") == 0)
    {
        if(filaVacia(&cajero[i].filita)) ordenarporTipoCliente(&cajero[i].filita);
    }

}

void guardarCajasEnArchivo(caja cajero[],char nombre[],int dimension)
{
    int i = 0;
    FILE * archi=fopen(nombre,"ab");
    if(archi)
    {
        while(i < dimension)
        {
            fwrite(&cajero[i],sizeof(caja),1,archi);
            i++;
        }


    }
    fclose(archi);
}

void pasarArchivoAcajas(char nombre[],caja cajero[],int dimension)
{
    int i = 0;
    caja aux;
    FILE * archi=fopen(nombre,"rb");
    if(archi)
    {
        while((fread(&aux,sizeof(caja),1,archi)) > 0 && (i < dimension))
        {
           cajero[i]=aux;
           i++;
        }
    }
    fclose(archi);
}

int atenderClientes(caja cajero[],int dimension)
{
   int i = 0,contador = 0;

   while(i < dimension)
   {
        contador=sacarClientesDeCajas(cajero,i,contador);
        i++;
   }
   return contador;
}

int sacarClientesDeCajas(caja cajero[],int i,int contador)
{
    Fila aux;
    inicFila(&aux);
    nodo * lista=inicNodo();
    persona p;
    int suma = 0,sumando = 0;
    while(filaVacia(&cajero[i].filita))
    {
        p=quitar(&cajero[i].filita);
        if(strcmpi(cajero[i].algoritmoPlanificacion,"rr") == 0)
        {
            if(p.cantArticulos > quantum)
            {
                sumando++;
                p.tiempoDeEspera=suma;
                p.tiempoProcesado=quantum*sumando;
                p.cantArticulos=p.cantArticulos-quantum;
                suma=suma-p.cantArticulos+quantum;
                agregar(&cajero[i].filita,crearNodo(p));

            }
            else
            {
                if(p.tiempoProcesado != p.tiempoDeEspera)
                {
                    p.tiempoDeEspera=suma;
                    p.tiempoProcesado=p.tiempoProcesado+p.cantArticulos;
                }
                else
                {
                    p.tiempoDeEspera=suma;
                    p.tiempoProcesado=p.cantArticulos;
                }
            }
            agregar(&aux,crearNodo(p));
            contador++;
        }
        else
        {
            p.tiempoDeEspera=suma;
            p.tiempoProcesado=p.cantArticulos;
            agregar(&aux,crearNodo(p));
            contador++;
        }
        suma=suma+p.cantArticulos;
    }
    while(filaVacia(&aux)) // para poder mostrar las cajas con las personas
    {
        agregar(&cajero[i].filita,crearNodo(quitar(&aux)));
    }
    return contador;
}

int AtenderEnXTiempo(caja cajita,persona p,int tiempo)
{
    int cont=0,rta=0;
    nodo * nuevo=crearNodo(p);
    if( strcmpi(cajita.algoritmoPlanificacion,"prioridad")==0 || strcmpi(cajita.algoritmoPlanificacion,"rr")==0 )
    {
        if(cajita.abiertaOcerrada == 1)
    {
        if(nuevo->cliente.medioPago == cajita.medioPago)
        {
            nodo * lista=cajita.filita.cabecera;
            nodo * aux=lista;
            nodo * pos;

            if(tiempo < lista->cliente.cantArticulos)
            {
                lista=agregarPrincipio(lista,nuevo);
            }
            else
            {
                while((aux) && (tiempo > cont))
                {
                    cont=cont+aux->cliente.cantArticulos;
                    pos=aux;
                    aux=aux->siguiente;
                }
                if(aux)
                {
                    nodo *ante=pos->anterior;
                    ante->siguiente=nuevo;
                    nuevo->anterior=ante;
                    nuevo->siguiente=pos;
                    pos->anterior=nuevo;
                }
                else
                {
                    lista=agregarFinal(lista,nuevo);
                }
            }
            rta++;
        }
     }
    }
    else
    {
        if(cajita.abiertaOcerrada == 1)
        {
            if(nuevo->cliente.medioPago == cajita.medioPago)
            {
                agregar(&cajita.filita,nuevo);
                rta++;
            }
        }
    }
    return rta;
}

int calcularTiempoDeCaja(caja cajero[],int i,float  * tEjecucion,float * tRespuesta,int * totalEjecucion,int * totalRespuesta)
{
    int suma = 0;
    int contador=contarElementosFila(&cajero[i].filita.cabecera);
    nodo * aux=cajero[i].filita.cabecera;
    nodo * lista=cajero[i].filita.ultimo;
    if(aux)
    {
        while(aux)
        {
            suma=aux->cliente.tiempoProcesado+suma;
            aux=aux->siguiente;
        }
        *tEjecucion=suma;
        *tRespuesta=lista->cliente.tiempoDeEspera;
        *totalEjecucion=*tEjecucion;
        *totalRespuesta=*tRespuesta;
        *tEjecucion=(float)*tEjecucion/contador;
        *tRespuesta=(float)*tRespuesta/contador;
    }

    return contador;
}

void calcularTiemposTotales(caja cajero[],int dimension,float  * tEjecucion,float * tRespuesta,int * totalEjecucion,int * totalRespuesta)
{
    int i = 0,contador = 0,suma = 0,ejecucion = 0,respuesta = 0,contar = 0;
    nodo * aux=inicNodo();
    nodo * lista=inicNodo();
    while(i < dimension)
    {
        contador=contarElementosFila(&cajero[i].filita.cabecera);
        lista=cajero[i].filita.ultimo;
        contar=contarTiempoProcesado(cajero[i]);
        if(lista)
        {
            *tEjecucion=contar+*tEjecucion;
            *tRespuesta=*tRespuesta+lista->cliente.tiempoDeEspera;
        }

        suma=suma+contador;
        i++;
    }
    if(*tEjecucion != 0 || *tRespuesta != 0)
    {
        *totalEjecucion=*tEjecucion;
        *totalRespuesta=*tRespuesta;
        *tEjecucion=(float)*tEjecucion/suma;
        *tRespuesta=(float)*tRespuesta/suma;
    }


}

int contarTiempoProcesado(caja cajero)
{
    int contar = 0;
    nodo * aux=inicNodo();
    aux=cajero.filita.cabecera;
    while(aux)
    {
        contar=aux->cliente.tiempoProcesado+contar;
        aux=aux->siguiente;
    }
    return contar;
}

void MostrarDeterminadaCaja(caja cajita[])
{
    int opcion=0;

    printf("Seleccione una caja entre 1-8: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while( (opcion<1) || (opcion>8) )
    {
        printf("La caja ingresada no existe\n");
        printf("Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    system("cls");
    leerCaja(cajita[opcion-1]);
}

void MeterPersona(caja cajita[],int dim)
{
    int tiempo=0,control=0,i=0,aux=0;
    persona p;

    printf("Ingrese los datos de la nueva persona\n");
    p=CrearPersona();
    printf("Ingrese el tiempo: ");
    fflush(stdin);
    scanf("%d",&tiempo);

    while(control==0)
    {
        i = rand() % 7;
        control=AtenderEnXTiempo(cajita[i],p,tiempo);
    }
    printf("La persona ingreso en la caja %d\n",i+1);

}

int ElegirEnCaja()
{
    int pos=0;

    printf("Eliga la caja: ");
    fflush(stdin);
    scanf("%d",&pos);
    while( (pos<1)||(pos>8) )
    {
        printf("La caja indicada no existe\n");
        printf("Seleccione otra caja: ");
        fflush(stdin);
        scanf("%d",&pos);
    }

    return pos-1;
}

void vaciarCajas(caja cajita[],int dim)
{
    int i = 0;
    nodo * aux=inicNodo();
    nodo * prox;
    while(i < dim)
    {
        while(filaVacia(&cajita[i].filita))
        {
            quitar(&cajita[i].filita);
        }
        i++;
    }
