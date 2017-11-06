#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
typedef struct
{
        int nro_de_caja;
        char nombreCajero[40];
        int tipo_pago;                 //  1 efectivo, 2 cr�dito o d�bito, 3 todos
        int abiertaOcerrada;
        char algoritmoPlanificacion[30];  // debe informar que tipo de alg. de planificaci�n utiliza la caja
        Fila filita ;
} caja;

/*
agregarCaja // crea una nueva caja en el arreglo
abrirOcerrarCaja // abre o cierra una caja a requerimiento (si hay clientes no puede cerrarse)
buscarCaja // busca una caja de acuerdo a su tipo de pago y la retorna (si es que est� abierta)
mostrarCaja // muestra la caja (sus datos) y toda la fila de clientes que esperan
agregarClienteACaja // agrega un cliente a la caja de acuerdo al orden que plantea el algoritmo de planificaci�n que aplica la caja, siempre y cuando la caja est� abierta
agregarClienteACajaEnTiempoDeterminado //
atenderClientes // atiende a los clientes de acuerdo al algoritmo de planificaci�n que aplica la caja, calculando el tiempo de espera de cada cliente
*/


#endif // CAJA_H_INCLUDED
