#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct
{
    int id;
    char apeNomb[30];
    char usuario[20];
    int pass[2][5]; // dato para guardar la matriz encriptada
    int activo;  /// 1 activo 0 inactivo
} stUsuario;

void carga_pass(char A[]);
void calcula_inversa(int matriz[][2], float inv[][2]);
void arreglo_to_matriz(char A[], int M[][5]);
void encripta_matriz(int matriz_ascii[][5], stUsuario *encript);
int verificacion_nombre_usuario(char arch_usr[], char nombre_usuario[]);
void carga_nombre_usuario(stUsuario *user, char arch_usr[]);
int id_usuario(char arch_usr[]);
void alta(char arch_usr[]);
void matriz_to_arreglo(int M[][5], char P[]);
void desencripta_matriz(int encript[][5], char pass[]);
void login (char arch_usr[]);
void muestra_todos_usuarios(char nombr_arch[]);
void submenuUsuario(char nombr_arch[]);
void mostrarMenuUsuario();


#endif // USUARIO_H_INCLUDED
