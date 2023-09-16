/*La empresa de telefonía MuyClaro S.A. está adherida al servicio de Rapipago, que es un canal de cobranza extrabancario,  
para que sus clientes puedan realizar el pago del servicio por este canal. 
Al final del día Rapipago envía al área de Cobranzas de MuyClaro S.A. un archivo con el detalle de los pagos recibidos, 
que se encuentra ordenado por el código de sucursal donde se realizó el pago. Cada registro de pago tiene la siguiente forma:
	
Se solicita procesar el archivo pagosmuyclaro.dat para generar un informe que incluya:

a) La cantidad de pagos realizados en cada sucursal.

b) El importe recaudado por sucursal.

c) Identificar la sucursal con mayor cantidad de pagos.

d) La cantidad total de pagos realizados.

e) El detalle de pagos por sucursal según indica el formato de reporte del punto siguiente.

f) Generar un informe con el siguiente formato de salida por pantalla:*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef char tString[10];
typedef char tString1[30];
typedef tString1 t_array_string[];
t_array_string sucursal = {" ", "Centro de servicio rapi pago", "Estacion de servicio Pachero", "Tele centro pellegrini", "Farmacio de Rosario", "Correo Argentino"};
typedef struct {   
  short codigoDeSucursal;
  long int numeroCliente;
  tString fechaDeVencimiento;
  tString fechaDePago;
  bool pagoATerminar;
  float importe;
}tr_Registro;	 


tr_Registro vr_Registro;
FILE * vf_Registro;

void inicializacionLectura();
void procesarCorte();
void finalizacion();
void principioCorte();
void unUsuario();
void finCorte();
void determinarMayorCantidadPagos();

int codCampoControl,sucursalNum;
int mayorCantidadPagos,totalPagoSucursal,totalDePagosSurcursal;
float totalImporte;
tString1 sucursalMayor;
tString booleano;

int main() {		
	inicializacionLectura();	
	procesarCorte();		
	finalizacion();
	return 0;
}


void inicializacionLectura() {		
	vf_Registro = fopen("pagosmuyclaro.dat", "rb");
	fread(&vr_Registro, sizeof(tr_Registro), 1 ,vf_Registro);
	mayorCantidadPagos=0;
	totalPagoSucursal=0;
	printf("\n------------------------------------------------------------------------------------------------");
	printf("\n\t\t\tListado de pagos a MuyClaro S.A. del dia de la fecha\n");
	printf("--------------------------------------------------------------------------------------------------\n");			
}

void procesarCorte() {
	while(!feof(vf_Registro)) {		
		principioCorte();
    	while(!feof(vf_Registro) && vr_Registro.codigoDeSucursal== codCampoControl){
			unUsuario();
			fread(&vr_Registro, sizeof(tr_Registro), 1, vf_Registro);
		}
		finCorte();
	}
}

void principioCorte(){
	printf("%s\n",sucursal[vr_Registro.codigoDeSucursal]);
	printf("\nNum.Cliente\tFecha vencimiento\t\tPago a terminar\t\t\tImporte\n");
	totalImporte=0;
	totalDePagosSurcursal=0;
	codCampoControl=vr_Registro.codigoDeSucursal;
}

void unUsuario(){
	if (vr_Registro.codigoDeSucursal){
		totalImporte+=vr_Registro.importe;
		totalDePagosSurcursal++;
    }
		if(vr_Registro.pagoATerminar==true){
		printf("%d\t\t%s\t\t\tSI\t\t\t%.2f\n",vr_Registro.numeroCliente,vr_Registro.fechaDeVencimiento,vr_Registro.importe);	
		}else{
			printf("%d\t\t%s\t\t\tNO\t\t\t%.2f\n",vr_Registro.numeroCliente,vr_Registro.fechaDeVencimiento,vr_Registro.importe);	
		}
		
		
	
}

void determinarMayorCantidadPagos(){
	  totalPagoSucursal++;
	if(	totalDePagosSurcursal>mayorCantidadPagos){
		mayorCantidadPagos=	totalDePagosSurcursal;
		strcpy(sucursalMayor,sucursal[codCampoControl]);
		sucursalNum=codCampoControl;
	}
}

void finCorte(){
	determinarMayorCantidadPagos();
	printf("_________________________________________________________________________________________________");
	printf("\nTotal de pagos de la surcusal %d\nImporte recaudado de la surcusal %.2f\n",totalDePagosSurcursal,totalImporte);
	printf("_________________________________________________________________________________________________\n");
}

void finalizacion(){
   	printf("\nCantidad de pagos regristrados en el archivo: %d",totalPagoSucursal);
	printf("\nSucursal con mayor cantidad de pago: %d-%s-Pagos:%d",sucursalNum,sucursalMayor,mayorCantidadPagos);
		  
   fclose(vf_Registro);      
}
