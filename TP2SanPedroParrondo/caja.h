#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "fila.h"

typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;                 //  1 efectivo, 2 crédito o débito, 3 todos
    int abiertaOcerrada;           // 1 abierto, 0 cerrado
    char algoritmoPlanificacion[30];  // debe informar que tipo de alg. de planificación utiliza la caja
    Fila filita;
}caja;

int agregarCaja(caja cajero[],int dimension);
void cargarCajas(caja cajero[],int i);
void mostrarCajas(caja cajero[],int dimension);
void mostrarCajaPausado(caja cajero[],int posicion);
void leerCajaPausado(caja cajero);
void leerCaja(caja cajero);
void comprobar(int rta);
void abriOcerrarCaja(caja cajero[],int dimension);
void abrirTodasLasCajas(caja cajero[],int dimension);
caja buscarCaja(caja cajero[],int dimension,int pago);
void guardarCajasEnArchivo(caja cajero[],char nombre[],int dimension);
void agregarClienteACaja(caja cajero[],persona p,int dimension);
void planificador(caja cajero[],int i,persona p);
void pasarArchivoAcajas(char nombre[],caja cajero[],int dimension);
int atenderClientes(caja cajero[],int dimension);
int sacarClientesDeCajas(caja cajero[],int i,int contador);
int AtenderEnXTiempo(caja cajita,persona p,int tiempo);
int calcularTiempoDeCaja(caja cajero[],int i,float  * tEjecucion,float * tRespuesta,int * totalEjecucion,int * totalRespuesta);
void calcularTiemposTotales(caja cajero[],int dimension,float  * tEjecucion,float * tRespuesta,int * totalEjecucion,int * totalRespuesta);
int contarTiempoProcesado(caja cajero);
void MostrarDeterminadaCaja(caja cajita[]);
void MeterPersona(caja cajita[],int num);
int ElegirEnCaja();



#endif // CAJA_H_INCLUDED
