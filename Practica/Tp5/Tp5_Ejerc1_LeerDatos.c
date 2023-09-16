/*
Se tiene registrada la información sobre los movimientos de los clientes de un Banco. De cada movimiento
se conoce:
|Número de Cuenta|Nombre del Cliente|Código de Operación|Importe|
Se solicita:
a) Listar el detalle de movimientos por cuenta.
b) Informar cantidad de movimientos y totales de importes de depósitos y extracción, por cuenta.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include<locale.h>

//declaracion del protipado
void iniciarProcesoLectura();
void procesarCorte();
void finalizarProcesoLectura();

//declaracion del Prototipado Especificas a la Consigna
void principioCorte();
void unClienteMovimiento();
void finCorte();


//declaracion de tipos de datos
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
int	codCampoControl;
int movimientos1,movimientos2;
float importeDepositado,importeExtraccion;

//declaracion de funcion principal
int main() {
	setlocale(LC_ALL,"spanish");
	iniciarProcesoLectura();
	procesarCorte();
	finalizarProcesoLectura();
	return 0;
}

//Implementación de funciones
void iniciarProcesoLectura() {
	vf_clienteBanco = fopen("movimientosBanco.dat", "rb");
	fread(&vr_clienteBanco, sizeof(tr_clienteBanco), 1, vf_clienteBanco);
	printf("\n\t\t*** Detalle de Movimientos por cuenta *** \n");
	printf(" -------------------------------------------------------------------------\n");
	printf("|\tNro Cuenta \t|\tDepósito \t|\tExtracción\t |\n");
	printf(" -------------------------------------------------------------------------\n");
}

void procesarCorte() {
	while(!feof(vf_clienteBanco)) {		
		principioCorte();
		while(!feof(vf_clienteBanco) && vr_clienteBanco.nroCliente == codCampoControl){
			unClienteMovimiento();
			fread(&vr_clienteBanco, sizeof(tr_clienteBanco), 1, vf_clienteBanco);
		}
		finCorte();
	}	
}

void principioCorte() {	 
	movimientos1=0;
	movimientos2=0;
	importeDepositado=0;
	importeExtraccion=0;
	codCampoControl =vr_clienteBanco.nroCliente;
}

void unClienteMovimiento() {
	 if( vr_clienteBanco.codigoOperacion==1) {
		movimientos1+=1;
		importeDepositado+=vr_clienteBanco.importe; 
	 } else {
		 if( vr_clienteBanco.codigoOperacion==2){
			movimientos2+=1;
			importeExtraccion+=vr_clienteBanco.importe;
		}	
	}
	 printf("\t   %d\t\t\t %.2f \t\t%.2f\n",codCampoControl,importeDepositado,importeExtraccion);
}

void finCorte() {
	printf("\n___________________________________________________________________________\n");
	printf("\nTotal Cta %d \t\t%.2f \t\t\t%.2f\n",codCampoControl,importeDepositado,importeExtraccion);
	printf("Cantidad de mov. %d \t%d \t\t\t%d\n",codCampoControl,movimientos1,movimientos2);
	printf("\n____________________________________________________________________________\n");	
}

void finalizarProcesoLectura() {	
	fclose(vf_clienteBanco);	
}

