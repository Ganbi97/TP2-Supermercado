#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "fila.h"
#include "lista.h"
//#include "menu.h"

typedef struct
{
        int nro_de_caja;
        char nombreCajero[40];
        int tipo_pago;                 //  1 efectivo, 2 crédito o débito, 3 todos
        int abiertaOcerrada;
        char algoritmoPlanificacion[30];  // debe informar que tipo de alg. de planificación utiliza la caja
        Fila filita ;
} caja;

/*
void addarchivecaja(char ubicacion[15]);
void cargararchivetocaja(char ubicacion[15],caja cajero[8]);
void verarchivecajas(char ubicacion[15]);
void agregararchivecaja(char ubicacion[15]);
caja agregarCaja(caja cajero,int nrocajero); // crea una nueva caja en el arreglo
caja abrirOcerrarCaja(caja cajero); // abre o cierra una caja a requerimiento (si hay clientes no puede cerrarse)
caja buscarCaja(caja cajero[],int tipodepago); // busca una caja de acuerdo a su tipo de pago y la retorna (si es que está abierta)
void mostrarCaja(caja cajero); // muestra la caja (sus datos) y toda la fila de clientes que esperan
caja agregarClienteACaja(caja cajero[],persona p,int cantidad); // agrega un cliente a la caja de acuerdo al orden que plantea el algoritmo de       planificación que aplica la caja, siempre y cuando la caja está abierta
void atenderClientes(); // atiende a losclientes deacuerdoal algoritmodeplanificaciónqueaplicalacaja, calculando                 el tiempo de espera de cada client
void switchesabrircerrar(caja cajero[],int cantidad);
void operacioncorrecta();
int agarrarmenor(int flag,caja cajero[],int i);
*/


#endif // CAJA_H_INCLUDED
