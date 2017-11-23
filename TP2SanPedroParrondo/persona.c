#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "caja.h"

int CargarPersonas(char nombre[])
{
    int contador=0;
    char control='s';
    persona p;
    FILE *archivo=fopen(nombre,"r+b");
    if(!archivo)
    {
        printf("El archivo no existe, creando uno... \n");
        FILE *archivo=fopen(nombre,"w+b");
        if(archivo)
        {
            while(control == 's')
            {
                p=CrearPersona();
                fwrite(&p,sizeof(persona),1,archivo);
                contador++;
                system("cls");
                printf("Desea continuar? ...s/n ");
                fflush(stdin);
                scanf("%c",&control);
            }
        }
        else
        {
            printf("No se pudo abrir el archivo \n");
        }
    }
    else
    {
        printf("El archivo ya contiene datos \n");
    }
    fclose(archivo);
    return contador;
}

void MostrarArchivo(char nombre[])
{
    persona aux;
    FILE *archivo=fopen(nombre,"rb");
    if(archivo)
    {
          while(fread(&aux,sizeof(persona),1,archivo)>0)
          {
              MostrarCliente(aux);
          }
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
    fclose(archivo);

}

void AgregarPersonas(char nombre[])
{
    char control='s';
    persona p;
    FILE *archivo=fopen(nombre,"ab");
    if(archivo)
    {
        while(control == 's')
        {
            p=CrearPersona();
            fwrite(&p,sizeof(persona),1,archivo);

            system("cls");
            printf("Desea continuar? ...s/n ");
            fflush(stdin);
            scanf("%c",&control);
        }
    }
    else
    {
        printf("No se pudo abrir el archivo \n");
    }
    fclose(archivo);
}

void MostrarCliente(persona p)
{
    printf("Nombre y Apellido: %s\n",p.nombreApellido);
    printf("Cantidad de articulos: %d\n",p.cantArticulos);
    printf("Tiempo de espera: %d\n",p.tiempoDeEspera);
    printf("Tiempo de procesado: %d\n",p.tiempoProcesado);
    printf("Tipo de cliente: %d\n",p.tipo_cliente);
    printf("Tipo de pago: %d\n",p.tipo_pago);
    puts("---------------------------------------------");
}

int VerificacionCliente()
{
    int tipo=0;

        printf("Tipo de cliente: ");
        scanf("%d",&tipo);

        if((tipo < 1) || (tipo > 3))
        {
            while((tipo < 1) || (tipo > 3))
            {
                printf("Vuelva a ingresar el tipo de cliente correspondiente\n");
                printf("Tipo de cliente: ");
                fflush(stdin);
                scanf("%d",&tipo);
            }
        }
    return tipo;
}

int VerificacionDePago()
{
    int pago=0;

    printf("Tipo de pago: ");
    scanf("%d",&pago);

        if((pago < 1) || (pago > 3))
        {
            while((pago < 1) || (pago > 3))
            {
                printf("Vuelva a ingresar el tipo de pago correspondiente\n");
                printf("Tipo de pago: ");
                fflush(stdin);
                scanf("%d",&pago);
            }
        }
    return pago;
}

persona CrearPersona()
{
    persona p;
    printf("Ingrese el nombre y apellido: ");
    fflush(stdin);
    gets(p.nombreApellido);

    printf("Ingrese la cantidad de articulos: ");
    fflush(stdin);
    scanf("%d",&p.cantArticulos);

    p.tiempoDeEspera=0;

    p.tiempoProcesado=0;

    p.tipo_cliente=VerificacionCliente();

    p.tipo_pago=VerificacionDePago();

    return p;
}

void MostrarArchivoCajas(char nombre[])
{
    caja cajero;
    int i = 0;
    FILE * archivo=fopen(nombre,"rb");
    if(archivo)
    {
          while(fread(&cajero,sizeof(caja),1,archivo)>0)
          {
                printf("Numero de caja: %d\n",cajero.nro_de_caja);
                printf("Nombre del cajero: %s\n",cajero.nombreCajero);
                printf("Tipo de pago: %d ",cajero.tipo_pago);tipodePago(cajero.tipo_pago);
                printf("%d",cajero.abiertaOcerrada);comprobar(cajero.abiertaOcerrada);
                printf("Algoritmo de planificacion: %s\n",cajero.algoritmoPlanificacion);
                puts("--------------------------");
          }
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
    fclose(archivo);

}

/*persona encontrarPersona(char nombre[15])
{
    persona aux;
    persona respuesta;
    FILE *archivo=fopen(nombre,"rb");
    if(archivo)
    {
          while(fread(&aux,sizeof(persona),1,archivo)>0)
          {
              if(strcmpi(nombre,aux.nombreApellido)==0)
              {
                  respuesta=aux;
              }
          }
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
    fclose(archivo);
    return respuesta;
^*/
