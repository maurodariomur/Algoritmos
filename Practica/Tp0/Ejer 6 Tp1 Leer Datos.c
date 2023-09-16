#include<stdio.h>
#include<string.h>

//declaracion constante
#define MOVIMIENTO 2

//declaracion del prototipado
void inicializarVariables();
void iniciarProcesoLectura(); 
void leerRegistroArchivoCliente();
void procesarRegistroCliente();
void finalizarProcesoLectura();

//delclaracion del prototipado vectores
void mostrarClientes();
void cantidadMoviYTotalImpor();
void mostrarMovimientos();
void totalImporteCuentas();

//declaracion de tipos de datos
typedef char tc_cliente[20];
typedef int tv_vector[MOVIMIENTO];

//declaracion tipo vector
tv_vector vv_movimiento;

int i;
float totalImporteD,totalImporteE;

//declaracion de tipo Datos
typedef struct{
	int nroCuenta;
	tc_cliente nombYApe;
	int codigoMovimiento;
	float importe;
}tr_clientes;

tr_clientes vr_clientes; /*declaracion variable de tipo registro*/
FILE * vf_clientes;/*declaracion variable de tipo fichero*/

int main(){
	iniciarProcesoLectura(); 
	leerRegistroArchivoCliente();
	procesarRegistroCliente();
	finalizarProcesoLectura();
	return 0;
}

void iniciarProcesoLectura(){
	vf_clientes = fopen ("datosCuentaBancaria", "rb");
	printf("\nRegistros del Archivo\n");
}
void leerRegistroArchivoCliente(){
	fread(&vr_clientes,sizeof(tr_clientes), 1 ,vf_clientes);
}
void procesarRegistroCliente(){
	while (!feof(vf_clientes)){
		mostrarClientes();
		totalImporteCuentas();
	 	leerRegistroArchivoCliente();
	}
	mostrarMovimientos();
}

void mostrarClientes(){
		printf("\n\t %d \t\t %s \t\t %d \t\t $%.2f\n",vr_clientes.nroCuenta,vr_clientes.nombYApe,vr_clientes.codigoMovimiento,vr_clientes.importe);
			vv_movimiento[vr_clientes.codigoMovimiento-1]+=1;
		
}

void mostrarMovimientos(){	
			printf("\n\tLA CANTIDAD DE DEPOSITO:%d\t\tIMPORTE TOTAL: $%.2f",vv_movimiento[0],totalImporteD);
			printf("\n\tLA CANTIDAD DE EXTRACCION:%d\t\tIMPORTE TOTAL: $%.2f",vv_movimiento[1],totalImporteE);
}

void totalImporteCuentas(){
	if(vr_clientes.codigoMovimiento==1){
		totalImporteD+=vr_clientes.importe;
	}
	if(vr_clientes.codigoMovimiento==2){
		totalImporteE+=vr_clientes.importe;
	}
}

void finalizarProcesoLectura(){
	fclose(vf_clientes);
}
