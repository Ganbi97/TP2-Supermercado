#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "usuario.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void carga_pass(char A[])  // CARGO LA CONTRASEÑA, VERIFICO QUE TENGA 10 CARACTERES
{
    printf("Contraseña (exactamente 10 caracteres): ");
    do
    {
        fflush(stdin);
        gets(A);
        if (strlen(A)!=10)
        {
            printf("LA CONTRASEÑA DEBE CONTENER EXACTAMENTE 10 CARACTERES, VOLVE A INGRESARLA \n");
        }
    }
    while (strlen(A)!=10);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcula_inversa(int matriz[][2], float inv[][2])
{
    int det= matriz[0][0]*matriz[1][1]-(matriz[0][1]*matriz[1][0]);
    if (det!=0)
    {
        inv[0][0]= (1/(float)det)* matriz[1][1];
        inv[0][1]= (1/(float)det)*(-1)* matriz[0][1];
        inv[1][0]= (1/(float)det)*(-1)* matriz[1][0];
        inv[1][1]= (1/(float)det)* matriz[0][0];
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void arreglo_to_matriz(char A[], int M[][5])   // PASA EL PASS CARGADO EN EL ARREGLO A UNA MATRIZ (pasa los valores ASCII)  ANDAAAA!
{
    int i=0, j=0, u=0;    // i: fila, j:columna

    for (i=0; i<2; i++)
    {
        for (j=0; j<5; j++)
        {
            M[i][j]=(int)A[u];
            u++;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void encripta_matriz(int matriz_ascii[][5], stUsuario *encript)   // ACA MULTIPLICO LA DE 2X2(LA QUE SE YO) POR LA DE 2X5
{
    int i=0, j=0;
    int T[2][2]= {{1,3},{1,2}}; // MATRIZ TESTIGO (posee inversa)

    for (i=0; i<2; i++)
    {
        for (j=0; j<5; j++)
        {
            encript->pass[i][j]=(T[i][0]*matriz_ascii[0][j])+(T[i][1]*matriz_ascii[1][j]);  // M es la matriz de 2x5 a encriptar
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int verificacion_nombre_usuario(char arch_usr[], char nombre_usuario[])
{
    FILE*archi;
    archi=fopen(arch_usr,"rb");
    stUsuario aux;
    int valido=1;   // 0: nombre invalido (ya existe)

    if (archi)
    {
        while(fread(&aux, sizeof(stUsuario),1,archi)&& valido==1)
        {
            if (strcmpi(aux.usuario,nombre_usuario)==0)  //si los nombres son iguales, valido pasa a ser 0 (nombre invalido)
            {
                valido=0;
            }
        }
        fclose(archi);
    }

    return valido;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void carga_nombre_usuario(stUsuario *user, char arch_usr[])
{
    int valido=0;
    do
    {
        printf("Nombre de usuario: ");
        fflush(stdin);
        gets(user->usuario);
        valido=verificacion_nombre_usuario(arch_usr, user->usuario);
        if (valido==0)
        {
            printf("ESE NOMBRE YA EXISTE... \n");
        }
    }
    while (valido==0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int id_usuario(char arch_usr[])
{
    FILE*archi;
    archi=fopen(arch_usr,"rb");
    long cant_bytes;
    if(archi)
    {
        fseek(archi,0,2);
        cant_bytes=ftell(archi);
        fclose(archi);
    }
    return cant_bytes/sizeof(stUsuario);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void alta(char arch_usr[])  // CARGA DATOS PARA NUEVO CLIENTE
{
    FILE* archi_2;

    archi_2= fopen(arch_usr,"ab");

    stUsuario nuevo_usuario;

    char pass_arreglo[10];
    int pass_matriz_ascii[2][5];

    int i,j;


    if(archi_2)  // si los pudo abrir
    {

        carga_nombre_usuario(&nuevo_usuario, arch_usr);   // le paso la direccion de la variable nuevo_usuario para q la modifique

        carga_pass(pass_arreglo);                           // llamo a funcion de carga de password

        arreglo_to_matriz(pass_arreglo, pass_matriz_ascii); // paso el pass del arreglo a la matriz casteandolo a int

        encripta_matriz(pass_matriz_ascii, &nuevo_usuario);   // guardo en nuevo_usuario->pass, el password encriptado

        /*for (i=0; i<2; i++)
        {
            for (j=0; j<5; j++)
            {
                printf()
            }
        }*/

        nuevo_usuario.activo=1;  // esto va aca xq es una vez que valida el usuario


        nuevo_usuario.id=id_usuario(arch_usr)+1;  // devuelve la cant de datos escritos en el archivo, y le agrega uno, para el proximo id.
        //nuevo_usuario.id=nuevo_cliente.id;

        // aca ya tengo el password en la matriz con su codigo ascii

        fwrite(&nuevo_usuario, sizeof(stUsuario),1,archi_2); // PASO LOS DATOS A LOS ARCHIVOS CORRESPONDIENTES

        fclose(archi_2);
        printf("CLIENTE CARGADO CON EXITO....");
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void matriz_to_arreglo(int M[][5], char P[])   // PASA EL PASS CARGADO EN EL ARREGLO A UNA MATRIZ (pasa los valores ASCII)
{
    int i=0, j=0, u=0;
    char aux[10]="";  /// HAY Q CREAR ESTA VARIABLE POR EL ERROR DEL CARACTER DE MAS

    int r=0;  // separo memoria para q no se pise

    for (i=0; i<2; i++)
    {
        for (j=0; j<5; j++)
        {
            aux[u]=(char)M[i][j];
            u++;
        }
    }

    strcpy(P,aux);
//   P[10]='\0';

    /// YA ESTARIA CORREJIDO Y HASTA ACA VA BIEN,

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void desencripta_matriz(int encript[][5], char pass[])   // recibo la matriz encriptada, devuelvo el pass en arreglo de 10 elementos
{
    int i=0, j=0;
    int T[2][2]= {{1,3},{1,2}};     // MATRIZ TESTIGO (posee inversa)
    int desencript[2][5];
    float invT[2][2];


    calcula_inversa(T, invT);    //invT es la matriz inversa de la matriz T (testigo)

    for (i=0; i<2; i++)
    {
        for (j=0; j<5; j++)
        {
            desencript[i][j]=(invT[i][0]*encript[0][j])+(invT[i][1]*encript[1][j]);  // encript es la matriz encriptada , pone en desencript la matriz ascii luego de desencriptarla

        }                                                                                   //ANDA!!!!!!!!!!
    }
    matriz_to_arreglo(desencript, pass);  // llamo a la funcion que me pasa la matriz desencriptada al arreglo de char (ese seria ya el pass desencriptado)
    /* for (i=0; i<10; i++)
     {
         printf("%c ",pass[i]);
     }*/
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void login (char arch_usr[])
{
    FILE* archi_2;
    archi_2=fopen(arch_usr,"rb");


    char usuario_ingresado[20]="";

    stUsuario aux;

    int i=0;
    char pass_ingresado[11]="";


    int contrasenia_valida=0, nombre_valido=0, cont=0;

    char password[11]="";

    if (archi_2)
    {
        printf("\nNombre de usuario: ");
        fflush(stdin);
        gets(usuario_ingresado);  // pido que ingrese el usuario y lo guardo en usuario
        printf("Usuario ingresado: %s\n",usuario_ingresado);

        do
        {
            printf("\nPassword: ");
            fflush(stdin);
            gets(pass_ingresado);    // pido que ingrese el password y lo guardo en pass
            printf("Password ingresado: %s\n",pass_ingresado);


            rewind(archi_2);

            while ( fread(&aux, sizeof(stUsuario),1, archi_2)>0 )
            {

                printf("\nUSUARIO LEIDO DEL ARCHIVO:%s\n",aux.usuario);

                if (strcmp(aux.usuario, usuario_ingresado)==0)  // SI LOS NOMBRES DE USUARIO SON IGUALES...
                {
                    desencripta_matriz(aux.pass, password);  // DESENCRIPTO LA CONTRASEÑA DEL ARCHIVO Y LA GUARDO EN PASSWORD (PARA COMPARAR)
                    printf("LOS NOMBRES COINCIDEN...\n");
                    nombre_valido=1;


                    printf("\nLA CONTRASEÑA DESENCRIPTADA ES: \n");
                    printf("%s\n",password);
                    printf("%s\n",pass_ingresado);


                    if (strcmp(pass_ingresado, password)==0)
                    {
                        contrasenia_valida=1;

                        //system("cls");
                        printf("\nBIENVENIDO...");
                    }
                }
            }
            cont++;
            if (contrasenia_valida==0 && nombre_valido==1)
            {
                //system("cls");
                printf("\nCONTRASEÑA INCORRECTA, CANTIDAD DE INTENTOS RESTANTES: %d \n",3-cont);
            }

        }
        while (contrasenia_valida==0 && nombre_valido==1 && cont<3);



        fclose(archi_2);
    }
    else
        printf("\nPASO ALGO GRABE, NO PUDE ABRIR EL ARCHIVO \n");

    if (nombre_valido==0)
        printf("\nNOMBRE DE USUARIO INEXISTENTE\n ");

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void muestra_todos_usuarios(char nombr_arch[])
{
    FILE* archi;
    archi=fopen(nombr_arch,"rb");
    stUsuario aux;
    char pass_desencript[10];

    if (archi)
    {
        printf("MOSTRANDO USUARIOS...\n ");
        while (fread(&aux, sizeof(stUsuario),1,archi)>0)
        {
            printf("\nUsuario:%s",aux.usuario);
            //printf("\nID: %d",aux.id_cliente);
            //printf("\nActivo(1:si 0:no): %d \n",aux.activo);

            desencripta_matriz(aux.pass, pass_desencript);
            printf("\nPassword:%s\n",pass_desencript);
        }
    }
    fclose(archi);
}

void submenuUsuario(char nombr_arch[])
{
    //
    system("pause");
    system("color 4");
    int opciones=0;
    while(opciones!=5)
    {
        system("cls");
        mostrarMenuUsuario();
        printf("\n");
        printf("Eliga una opcion: ");
        fflush(stdin);
        scanf("%d",&opciones);
        switch(opciones)
        {
        case 1:

            login(nombr_arch);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            alta(nombr_arch);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            muestra_todos_usuarios(nombr_arch);
            system("pause");
            system("cls");
            break;
        case 4:
            exit(0);
        }
        printf("\n");
    }
    system("cls");
    printf("\nGood Bye!\n");
}

void mostrarMenuUsuario()
{
    printf("[1]Logearse nuevamente\n");
    printf("[2]Dar de alta usuario\n");
    printf("[3]Ver usuarios\n");
    printf("\n\n[4]SALIR DEL PROGRAMA\n");
    printf("[5]Entrar al programa Supermercado");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
