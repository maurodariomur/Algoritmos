/*
Se tiene registrada la información sobre los movimientos de los clientes de un Banco. De cada movimiento
se conoce:
|Número de Cuenta|Nombre del Cliente|Código de Operación|Importe|
Se solicita:
a) Listar el detalle de movimientos por cuenta.
b) Informar cantidad de movimientos y totales de importes de depósitos y extracción, por cuenta.
*/
#include<stdio.h>
#include<string.h>
#include<locale.h>

//declaracion del protipado
void iniciarProceso(); 
void ingresarDatosRegistro();
void finalizarProceso();
void grabarRegistroCliente();
void permitirProceso();
void continuarProceso();

typedef char tString[50];

//declaracion de tipo Datos
typedef struct{
	int nroCliente;
	tString nombre;
	int codigoOperacion;
	float importe;
}tr_clienteBanco;

tr_clienteBanco vr_clienteBanco; /*declaracion variable de tipo registro*/
FILE * vf_clienteBanco;/*declaracion variable de tipo fichero*/

//declaracion de variables globales
int continuar;

int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	permitirProceso();
	while(continuar==1){
		ingresarDatosRegistro();
		grabarRegistroCliente();
		continuarProceso();
	}
	finalizarProceso();
	return 0;
}

void permitirProceso(){
	printf("Ingresar Datos, 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void continuarProceso(){
	printf("Continuar con el ingreso de Datos, 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void iniciarProceso() {
/* Se abre un archivo nuevo y se asigna a la variable archivo */
vf_clienteBanco = fopen("movimientosBanco.dat", "wb");
printf("\n\t\tArchivo creado de clientes...\n");
}

void ingresarDatosRegistro(){  
		printf("Ingrese Nro. de Cliente: ");
    	scanf("%d",&vr_clienteBanco.nroCliente);
		printf("Ingrese Nombre y Apellido: ");
		fflush(stdin);
    	scanf("%[^\n]s",&vr_clienteBanco.nombre);
		printf("Ingrese el codigo de Operacion,1-Depósito o 2-Extracción: ");
    	scanf("%d",&vr_clienteBanco.codigoOperacion);
    	printf("Ingrese importe:  ");
    	scanf("%f",&vr_clienteBanco.importe);
}
	
void grabarRegistroCliente() {
/* Se graba 1 registro en el archivo de Usuario */
fwrite( &vr_clienteBanco, sizeof( tr_clienteBanco ), 1, vf_clienteBanco );
printf( "\tRegistro de cliente insertado! \n" );
}

void finalizarProceso() {
	fclose(vf_clienteBanco);
}
