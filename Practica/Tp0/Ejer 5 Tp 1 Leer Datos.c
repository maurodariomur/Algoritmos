#include<stdio.h>
#include<string.h>

//declaracion del prototipado
void inicializarVariables();
void iniciarProcesoLectura(); 
void leerRegistroArchivoCliente();
void procesarRegistroCliente();
void finalizarProcesoLectura();

//delclaracion del prototipado vectores
void mostrarClientes();

//declaracion de tipos de datos
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

int main(){
	iniciarProcesoLectura(); 
	leerRegistroArchivoCliente();
	procesarRegistroCliente();
	finalizarProcesoLectura();
	return 0;
}

void iniciarProcesoLectura(){
	vf_clientes = fopen ("datosCliente", "rb");
	printf("\nRegistros del Archivo\n");
}
void leerRegistroArchivoCliente(){
	fread(&vr_clientes,sizeof(tr_clientes), 1 ,vf_clientes);
}
void procesarRegistroCliente(){
	while (!feof(vf_clientes)){
		mostrarClientes();	
	 	leerRegistroArchivoCliente();
	}
}


void mostrarClientes(){
		printf("\n\t %d \t\t %s \t\t %d \t\t $%.2f\n",vr_clientes.nroCuenta,vr_clientes.nombYApe,vr_clientes.codigoMovimiento,vr_clientes.importe);
}

void finalizarProcesoLectura(){
	fclose(vf_clientes);
}
