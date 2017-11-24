#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    char nombre[40];
    char apellido[40];
    int cantArticulos;                // es el tiempo de ejecución
    int tiempoDeEspera;             // es el tiempo de respuesta
    int tiempoProcesado;          // es el tiempo que ya fue procesado en la línea de caja
    int tipo_cliente;              //  prioridad (1: embarazada, 2: jubilado y 3: normal)
    int tipo_pago;                //  1 efectivo, 2 crédito o débito, 3 todos
}persona;

int CargarPersonas(char nombre[]);
void MostrarArchivo(char nombre[]);
void AgregarPersonas(char nombre[]);
void MostrarCliente(persona p);
int VerificacionCliente();
int VerificacionDePago();
persona CrearPersona();
//persona encontrarPersona(char nombre[15]);

#endif // PERSONA_H_INCLUDED
