#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
        int id;
        char apellido[30];
        char nombres [40];
        int tipoCliente;             /// Prioridad 1:embarazada, 2:jubilado y 3:cliente común
        int medioPago;            /// 1:efectivo, 2:crédito y 3:todos
        int cantArticulos;            /// es el tiempo de ejecución
        int tiempoEspera;     // vale 0    /// es el tiempo de respuesta
        int tiempoProcesado;  //  vale 0     /// es el tiempo que ya fue procesado en la línea de caja
        int eliminado;            /// 1: eliminado, 0: activo
} persona;

persona crearPersona();
int solo3opciones(); //funcion que no permite que se ingrese otra cosa que no sea 1, 2 o 3 sirve tanto para tipo de cliente como para medio de pago
void mostrarPersona(persona p);
void mostrarMP(persona p);
void mostrarTC(persona p);


#endif // PERSONA_H_INCLUDED
