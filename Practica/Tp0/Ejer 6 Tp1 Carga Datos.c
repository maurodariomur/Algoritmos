/*
Realizar un programa en C que permita leer el archivo generado en el punto anterior y emita un listado de 
todas las cuentas. Obtener e informar al final la cantidad de depósitos y extracciones y el importe total de 
cada tipo de movimiento. Detalle del informe:
CANTIDAD DE DEPÓSITOS: 2 IMPORTE TOTAL: $15.500
CANTIDAD DE EXTRACCIONES: 3 IMPORTE TOTAL: $12.800
*/

#include<stdio.h>
#include<string.h>

//declaracion del prototipado
void iniciarProceso(); 
void continuarProceso();
void ingresarDatosRegistro();
void grabarRegistroCliente();
void finalizarProceso();

typedef char tc_cliente[20];

//declaracion de tipo Datos
typedef struct{
	int nroCuenta;
	tc_cliente nombYApe;
	int codigoMovimiento;
	float importe;
}tr_clientes;

tr_clientes vr_clientes; /*declaracion variable de tipo registro*/
FILE * vf_clientes;/*declaracion variable de tipo fichero*/

//delclaracion de variables globales
int continuar;
int main(){
	iniciarProceso();
	continuarProceso();
	while(continuar==1){
		ingresarDatosRegistro();
		grabarRegistroCliente();
		continuarProceso();
	}
	finalizarProceso();
	return 0;
}

void continuarProceso(){
	printf("\n\tIngresar Datos, 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void iniciarProceso() {
/* Se abre un archivo nuevo y se asigna a la variable archivo */
	vf_clientes = fopen("datosCuentaBancaria", "ab");
	printf("\nArchivo creado del cliente\n");
}

void ingresarDatosRegistro(){  
		printf("Ingrese Nro. de Cuenta: ");
    	scanf("%d",&vr_clientes.nroCuenta);
		printf("Ingrese Nombre y Apellidos: ");
		fflush(stdin);
    	scanf("%[^\n]s",&vr_clientes.nombYApe);
    	printf("Ingrese Codigo de movimiento 1-Deposito,2-Extraccion: ");
    	scanf("%d",&vr_clientes.codigoMovimiento);
    	printf("Ingrese importe del Cliente: ");
    	scanf("%f",&vr_clientes.importe);
}
	
void grabarRegistroCliente() {
/* Se graba 1 registro en el archivo del Cliente */
	fwrite( &vr_clientes, sizeof( tr_clientes ), 1, vf_clientes);
	printf( "\tRegistro del cliente insertado! \n" );
}

void finalizarProceso() {
	fclose(vf_clientes);
}
